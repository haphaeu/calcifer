/*
K & R - The C Programming Language

Exercise 7-3. Revise minprint to handle more of the other facilities of printf.

Implementado aqui:

  - %nd
    integer occupying n empty scapes

  - %0nd
    same as previous with leading zeros

  - %.df
    float with d decimal places

  - %n.df
    same as above, accopying maximum n spaces

  - %*.*? 
    handle format parameters above as input arguments

@author: Rafael
@date: 13-Jun-2018

*/
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>


void minprintf(char *, ...);

int main(void)
{
       printf("int %d double %f string %s\n", 1, 1.1, "apples");
    minprintf("int %d double %f string %s\n", 1, 1.1, "apples");

       printf("%d   %4d   %04d   %f   %.3f   %10.3f\n", 1, 2, 3, 1.1, 2.2, 3.3);
    minprintf("%d   %4d   %04d   %f   %.3f   %10.3f\n", 1, 2, 3, 1.1, 2.2, 3.3);

       printf("%d   %*d   %0*d   %f   %.*f   %*.*f\n", 1, 4, 2, 4, 3, 1.1, 3, 2.2, 10, 3, 3.3);
    minprintf("%d   %*d   %0*d   %f   %.*f   %*.*f\n", 1, 4, 2, 4, 3, 1.1, 3, 2.2, 10, 3, 3.3);

    return 0;
}


/* minprintf: minimal printf with variable argument list*/
void minprintf(char *fmt, ...) {
    va_list ap;
    char *p, *sval;
    int ival;
    double dval;
    int lead_size, lead_zeros, decimals;

    va_start(ap, fmt);
    for (p = fmt; *p; p++) {
        if (*p != '%') {
            putchar(*p);
            continue;
        }

	lead_size = lead_zeros = 0;
	decimals = 6;

	if (*++p == '0') {
	    lead_zeros = 1;
	    ++p;
	}

	if (*p == '*') {
	    lead_size = va_arg(ap, int);
	    ++p;
	}

	if (*p >= '1' && *p <= '9') {
	    while (*p >= '0' && *p <= '9') {
                lead_size = 10 * lead_size + (int) (*p - '0');
                ++p;
	    }
	}

	if (*p == '.') {
	    if (*++p == '*')
		decimals = va_arg(ap, int);
	    else
		decimals = (int) (*p - '0');
	    ++p;
	}

        switch (*p) {
        case 'd':
            ival = va_arg(ap, int);
	    if (lead_zeros)
		printf("%0*d", lead_size, ival);
	    else
		printf("%*d", lead_size, ival);
            break;
        case 'f':
            dval = va_arg(ap, double);
            printf("%*.*f", lead_size, decimals, dval);
	    break;
        case 's':
            for (sval = va_arg(ap, char *); *sval; sval++)
                putchar(*sval);
            break;
        default:
            putchar(*p);
            break;
        }
    }
    va_end(ap);
}
