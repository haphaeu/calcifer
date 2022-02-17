/*
Example of function with multiple arguments.
K&R Section 7.3
*/
#include <stdio.h>
#include <stdarg.h>


double sumd(int n, ...);

int main(void) {
    printf("%f ", sumd(4, 1.1, 2.2, 3.3, 4.4));
    printf("%f ", sumd(3, 1.1, 2.2, 3.3));
    printf("%f\n", sumd(1, 1.1));
}

double sumd(int n, ...) {
    va_list ap;
    double x;

    // make ap point to 1st unnamed arg
    va_start(ap, n);

    x = 0.0;
    for (int i = 0; i < n; ++i)
	x += va_arg(ap, double); // fetch next arg
      
    // clean up 
    va_end(ap);

    return x;
}

    
    
