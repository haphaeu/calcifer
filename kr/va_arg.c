/*
Example of function with multiple arguments.
K&R Section 7.3, page 156
*/
#include <stdio.h>
#include <stdarg.h>


void minprintf(char*, ...);

int main(void) {
    minprintf("an int %d, a double %f and a string %s\n", 1, 2.3, "'string'");
}

/* 
The declaration ... means that the number and types of arguments may vary.

This is handled by <stdrag.h> and the variable type va_list.

va_list ap;                     // this variable will refer to each arg in turn
va_start(ap, last_named_arg);   // initialises ap to the first unnamed arg
va_arg(ap, type)                // returns the next arg, assuming type
va_end(ap)                      // clean up

*/
void minprintf(char *fmt, ...) {
    va_list ap;
    char *p, *sval;
    int ival;
    double dval;

    // make ap point to 1st unnamed arg
    va_start(ap, fmt);

    for (p = fmt; *p; p++) {
	if (*p != '%') {
	    putchar(*p);
	    continue;
	}
	switch (*++p) {
	case 'd':
	    ival = va_arg(ap, int);
	    printf("%d", ival);
	    break;
	case 'f':
	    dval = va_arg(ap, double);
	    printf("%f", dval);
	    break;
	case 's':
	    for (sval = va_arg(ap, char*); *sval; sval++)
		putchar(*sval);
	    break;
	default:
	    putchar(*p);
	    break;
	}
    }
    // clean up 
    va_end(ap);
}

    
    
