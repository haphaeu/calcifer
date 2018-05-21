#include <stdio.h>
#include <stdlib.h>

#define BITS 8


char *int2bin(int a, char *buffer, int buf_size) {
  /*  buffer must have length >= sizeof(int) + 1
   *  Write to the buffer backwards so that the binary representation
   *  is in the correct order i.e.  the LSB is on the far right
   *  instead of the far left of the printed string
   *
   *  modified from: https://stackoverflow.com/a/1024414/5069105
   */

    buffer += (buf_size - 1);

    for (int i = buf_size-1; i >= 0; i--) {
        *buffer-- = (a & 1) + '0';
	//*buffer-- = ' ';

        a >>= 1;
    }

    return buffer;
}


unsigned int getbits (unsigned int x, int p, int n) {
    /* from The C programming language, 2nd edition
     * Section 2.9 Bitwise Operators, page 49
     */
    return (x >> (p+1-n)) & ~(~0 << n);
}

unsigned int setbits(unsigned int x, int p, int n, unsigned int y) {
    /* The C programming language, 2nd edition
     * Exercise 2-6
     *
     * A primeira parte da expressao abaixo, antes do +, vai zerar n bits de x na posicao p.
     *
     * A segunda parte, depois do +, vai deslocar os n ultimos bits de y para a posicao p.
     *
     * Feito isso, pode usar uma simpes soma aritimetica para.
     */
    return (x & ~(~(~0 << n) << (p-n+1))) + ((y & ~(~0 << n)) << (p-n+1));
}


int main(int argc, char **argv) {
  
    char buffer[BITS + 1];
    unsigned int a, b, a2;
    int p, n;
    buffer[BITS] = '\0';

    // Replace n bits of a at position p with
    // the rightmost n bits from b
    a = atoi(argv[1]);
    b = atoi(argv[2]);
    p = atoi(argv[3]);
    n = atoi(argv[4]);
    
    int2bin(a, buffer, BITS);
    printf("%5d = %s\n", a, buffer);

    int2bin(b, buffer, BITS);
    printf("%5d = %s\n", b, buffer);

    a2 = setbits(a, p, n, b);
    int2bin(a2, buffer, BITS);
    printf("%5d = %s\n", a2, buffer);

    
  
}
