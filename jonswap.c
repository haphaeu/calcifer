/*
* TODO
 - [ ] Re-think PERIOD_START and PERIOD_END constants
 - [ ] Re-define spectrum based on frequency and sort out a-/de-scending order of omega array.
 - [ ] Implement mandatory input arguments for
   - [ ] simulation duration
   - [ ] time step 
 - [ ] Implement a function to parse input arguments to handle optional input arguments
   - [ ] number of harmonics
   - [ ] gamma parameter
   - [ ] random seed
 - Usage should be
      jonswap hs tp duration timestep [-n num_harmonics] [-g gamma] [-s seed]


c:/Users/rarossi/portable/Cpp/App/Dev-Cpp/MinGW64/bin/gcc -std=c11 jonswap.c -o jonswap


* JONSWAP spectrum calculations

Calculates a discretised JONSWAP spectrum based on input Hs and Tp.

Also calculates a time history of wave elevation according to that spectrum.

#+AUTHOR Rafael Rossi
#+DATE 06-Jun-2018

*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define PI            3.14159265358979323846
#define TWOPI         6.28318530717958647692
#define SEED          12543
#define PERIOD_START  1.0
#define PERIOD_END   30.0

#define VBS 1

double jonswap_gamma(double hs, double tp);
double custom_gamma_val = 0.0;            // dummy variable and function to handle user custom...
double custom_gamma_func(double, double); // ...value for the gamma parameter
double* period_domain(int length);
double* freq_domain(int length);
double* pierson_moskowitz_spectrum(double hs, double tp, int length, double *w);
double* jonswap_spectrum(double hs, double tp, double (*fgamma)(double, double),
			 int length, double *w, double *pm);
double spectral_moment(int n, double *s, double *w, int length);
double* jonswap_component_amplitude(double *s, double *w, int length);
double* phases(int length, int seed);
double* time_domain(double to, double tf, double ts, int *length);
double* wave_elevation(double *amp, double *w, double *phi, double *t, int len_spectrum, int len_tt);

int main(int argc, char *argv[]) {

    double hs, tp;
    double *t, *w, *pm, *js, *amp, *phi, *tt, *eta;
    double (*fgamma)(double, double);
    int size, tt_size;

    if (argc < 4 || argc > 5) {
	printf("Error: invalid arguments.\nUse: jonswap hs tp size [gamma]\n");
	exit(1);
    }

    hs = atof(argv[1]);
    tp = atof(argv[2]);
    size = atoi(argv[3]);

    if (argc == 5) {
	if ((custom_gamma_val = atof(argv[4])) == 0.0) {
	    printf("Error: invalid input to gamma parameter.\nUse: jonswap hs tp size [gamma]");
	    exit(2);
	}
	fgamma = custom_gamma_func;
    } else
	fgamma = jonswap_gamma;

    printf("Hs %.2f m\nTp %.2f s\n", hs, tp);

    t = period_domain(size);
    w = freq_domain(size);
    pm = pierson_moskowitz_spectrum(hs, tp, size, w);
    js = jonswap_spectrum(hs, tp, fgamma, size, w, pm);
    amp = jonswap_component_amplitude(js, w, size);
    phi = phases(size, SEED);
    tt = time_domain(0, 600, 0.1, &tt_size);
    eta = wave_elevation(amp, w, phi, tt, size, tt_size);

    // checking using the relationship zero-th moment is Hs squared divided by 16
    // m0 = Hs**2 / 16 ==> Hs = 4*sqrt(m0)
    printf("Check Hs %.2f m\n", 4*sqrt(spectral_moment(0, js, w, size)));
    printf("\nSpectrum\n\n");
    printf("%10s %10s %10s %10s %10s %10s \n", "T", "w", "PM", "JS", "amp", "phi");
    printf("%10s %10s %10s %10s %10s %10s \n", "[s]", "[rd/s]", "[m2s/rd]", "[m2s/rd]", "[m]", "[rd]");
    for (int i = 0; i < size; ++i)
	printf("%10.1f %10.3f %10.3f %10.3f %10.3f %10.3f\n", t[i], w[i], pm[i], js[i], amp[i], phi[i]);
    printf("\nTime History\n\n");
    printf("%10s %10s \n", "Time", "Elevation");
    for (int j = 0; j < tt_size; ++j)
	printf("%10.2f %10.3f\n", tt[j], eta[j]);

    return 0;
}

double jonswap_gamma(double hs, double tp) {
    /* 
    Return gamma factor for a JONSWAP spectrum according to DNV
    */
    double chk, gamma;

    chk = tp / sqrt(hs);

    if (chk < 3.6)
	return 5.0;
    else if (chk > 5.0)
	return 1.0;
    else
	return exp(5.75 - 1.15*chk);
}

double custom_gamma_func(double hs, double tp) {
    return custom_gamma_val;
}

double* period_domain(int length) {
    /*
    Returns the period domain of size length, from PERIOD_START to PERIOD_END.
     */
    double step = (PERIOD_END - PERIOD_START) / (length - 1);
    double *t = (double*) malloc(length * sizeof(double));
    
    for (int i = 0; i < length; ++i)
	*(t+i) = PERIOD_START + i*step;
    
    return t;
}

double* freq_domain(int length) {
    /*
    Returns the frequency domain of size length, from PERIOD_START to PERIOD_END.
    Note that the step is calculated based on time-domain to match both arrays.
     */

    double step = (PERIOD_END - PERIOD_START) / (length - 1);
    double *f = (double *) malloc(length * sizeof(double));

    for (int i = 0; i < length; ++i)
	*(f+i) = TWOPI / (PERIOD_START + i*step);

    return f;
}

double* pierson_moskowitz_spectrum(double hs, double tp, int length, double *w) {
    /*
    Return Pierson Moskowitz spectrum.

    hs     : significant wave height
    tp     : peak period
    length : length of the array
    w      : angular frequencies, or NULL to calculate it.
     */
    double wp, pm_cte, *s;

    if (w == NULL)
	w = freq_domain(length);

    wp = TWOPI / tp;
    pm_cte = 0.3125 * pow(hs, 2) * pow(wp, 4);

    if (VBS) printf("Pierson Moskowitz\n  wp %.2f\n  cte %.2f\n", wp, pm_cte);

    s = (double*) malloc(length * sizeof(double));

    for (int i = 0; i < length; ++i)
	*(s+i) = pm_cte * pow(*(w+i), -5) * exp(-1.25 * pow(*(w+i)/wp, -4));

    return s;
}

double* jonswap_spectrum(double hs, double tp, double (*fgamma)(double, double),
			 int length, double *w, double *pm) {
    /*
    Return JONSWAP spectrum.

    hs     : significant wave height
    tp     : peak period
    fgamma : function(hs, tp) retuning gamma parameter
    length : length of the array
    w      : angular frequencies, or NULL to calculate it
    pm     : Pierson Moskowitz spectrum, or NULL to calculate it.

    */
    
    double wp, gamma, norm, *s;

    if (w == NULL)
	w = freq_domain(length);
    
    if (pm == NULL)
	pm = pierson_moskowitz_spectrum(hs, tp, length, w);

    wp = TWOPI / tp;
    gamma = fgamma(hs, tp);
    norm = 1.0 - 0.287 * log(gamma);

    if (VBS) printf("JONSWAP\n  wp %.2f\n  gamma %.2f\n  norm %.2f\n", wp, gamma, norm);

    s = (double*) malloc(length * sizeof(double));

    for (int i = 0; i < length; ++i)  // I might regret this later, but I'm using
	*(s+i) = norm * *(pm+i) *     // pointer shift for arrays instead of indexes, i.e:
	    pow(gamma,                // *(pm+i) == pm[i]
		exp(-0.5 * pow((*(w+i) - wp)/wp/ (*(w+i) < wp ? 0.07 : 0.09), 2)));
    return s;
}

double spectral_moment(int n, double *s, double *w, int length) {
    /*
    Return the n-th spectral moment.

    n      : order of the spectral moment to be calculated
    s      : spectrum array
    w      : angular frequency array
    length : length of the s and w arrays
     */
    double m;
    for (int i = 0; i < length - 1; ++i)
	// THIS ASSUMES ARRAY w IS SORTED IN DESCENDING ORDER - NEED TO FIX THIS
	m += pow((*(w+i) - *(w+i+1))/2.0, n) * (*(w+i) - *(w+i+1)) * (*(s+i) + *(s+i+1));/* / 2.0; */
    return m/2.0;
}

double* jonswap_component_amplitude(double *s, double *w, int length) {
    /*
    Return the amplitude of a sinusoidal signal for each frequency component
    of a discretizes spectrum.
    
    s      : spectrum array
    w      : angular frequency array
    length : length of the arrays

    Ref: https://ceprofs.civil.tamu.edu/jzhang/ocen300/statistics-spectrum.pdf

    */
    double *amp = (double*) malloc(length * sizeof(double));
    for (int i = 0; i < length; ++i)
	// THIS ASSUMES ARRAY w IS SORTED IN DESCENDING ORDER - NEED TO FIX THIS
	*(amp+i) = sqrt(2 * *(s+i) * (*(w+i) - *(w+i+1)));
    return amp;
}

double* phases(int length, int seed) {
    double *phi = (double*) malloc(length  * sizeof(double));
    srand(seed);
    for (int i = 0; i < length; ++i)
	// random double between -pi and pi
	*(phi+i) = ((double)rand()/RAND_MAX*2.0 - 1.0) * PI;
    return phi;
}
double* time_domain(double to, double tf, double ts, int *length) {
    /*
    Return the time domain to be used to calculate the wave elevation.

    Note that since input is time-step, the array length must be passed
    as a pointer and it is where the length will be stored. 
    */
    double *td;
    *length = (int) ((tf - to) / ts);
    td = (double*) malloc(*length * sizeof(double));
    for (int i = 0; i < *length; ++i)
	*(td+i) = to + i*ts;
    return td;    
}
double *wave_elevation(double *amp, double *w, double *phi, double *t, int len_spectrum, int len_tt) {
    double *eta;
    eta = (double*) malloc(len_tt * sizeof(double));
    for (int i = 0; i < len_tt; ++i) {
	eta[i] = 0.0;
	for (int j = 0; j < len_spectrum; ++j)
	    // ok, here I got tired of pointer notation =PPP
	    eta[i] += amp[j] * cos(w[j]*t[i] - phi[j]);
    }
    return eta;
}
