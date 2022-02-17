// gcc atof.c -o atof.out -lm
#include <stdio.h>
#include <ctype.h>
#include <math.h>

/* atof: convert string s to double */
double atof(char s[]) {
  double val, power, val_power;
  int i, sign, sign_power;

  for (i = 0; isspace(s[i]); i++); // skip white spaces

  sign = (s[i] == '-') ? -1 : 1;

  if (s[i] == '+' || s[i] == '-')
    i++;

  for (val = 0; isdigit(s[i]); i++)
    val = 10.0 * val + (s[i] - '0');

  if (s[i] == '.')
    i++;

  for (power = 1.0; isdigit(s[i]); i++) {
    val = 10.0 * val + (s[i] - '0');
    power *= 10.0;
  }

  if (s[i] == 'e' || s[i] == 'E')
    sign_power = (s[++i] == '-') ? -1 : 1;

  if (s[i] == '+' || s[i] == '-')
    i++;

  for (val_power = 0; isdigit(s[i]); i++)
    val_power = 10.0 * val_power + (s[i] - '0');
  

  return sign * val / power * sign_power * pow(10, val_power);
}

void main(int argc, char **argv) {
  if (argc > 1) 
    printf("%.6f\n", atof(argv[1]));
    
}
