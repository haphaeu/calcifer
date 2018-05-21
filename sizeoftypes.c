#include <stdio.h>

/*

Print the number of bits of various data types.

*/

void main() {
  char c = 0;
  short s = 0;
  int i = 0;
  long l = 0L;
  long long ll = 0LL;
  float f = 0.0F;
  double d = 0.0;
  long double ld = 0.0L;

  printf("Type        Bits\n");
  printf("char        %d\n", 8*(int)sizeof(c));
  printf("short       %d\n", 8*(int)sizeof(s));
  printf("int         %d\n", 8*(int)sizeof(i));
  printf("long        %d\n", 8*(int)sizeof(l));
  printf("long long   %d\n", 8*(int)sizeof(ll));
  printf("float       %d\n", 8*(int)sizeof(f));
  printf("double      %d\n", 8*(int)sizeof(d));
  printf("long double %d\n", 8*(int)sizeof(ld));
}

/* 
in my noisy multicom laptop (linuxmint):
raf ~ $ gcc sizeoftypes.c 
raf ~ $ ./a.out
Type        Bits
char        8
short       16
int         32
long        64
long long   64
float       32
double      64
long double 128
*/
