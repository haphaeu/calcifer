#include <stdio.h>
#include <stdlib.h>

int SIZE = 50;
unsigned long long* PRIME_FACTORS;


void fact(unsigned long long n) {
    int p = 2;
    int i = 0;
    while (1) {
        if (n < p*p) {
            PRIME_FACTORS[i++] = n;
            PRIME_FACTORS[i++] = 0;
            return;
        }
        if (n % p == 0) {
            PRIME_FACTORS[i++] = p;
            n /= p;
        } else {
            p++;
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Use: %s N\n", argv[0]);
        return 1;
    }
    unsigned long long n = atoll(argv[1]);
    if (n <= 0) {
        printf("Error: N must be positive larger than zero.\n");
        return 2;
    }
    printf("%lld = ", n);
    PRIME_FACTORS = (unsigned long long*) malloc(SIZE * sizeof(unsigned long long));
    fact(n);
    unsigned long long f;
    for (int i = 0; (f = PRIME_FACTORS[i]) > 0 ; i++)
        printf("%lld ", f);
    printf("\n");
    return 0;
}
