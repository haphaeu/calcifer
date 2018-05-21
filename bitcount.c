#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*

The C programming language, 2nd edition
Exercise 2-9, page 51

*/
int bitcount(unsigned long x) {
  // from book, page 50
  int b;
  for (b = 0; x != 0; x >>= 1)
    if (x & 01)
      b++;
  return b;
}

int bitcount2(unsigned long x) {
  // my solution
  int b;
  for (b = 0; x != 0; b++)
    x &= x-1;
  return b;
}

int bitcount3(unsigned long x) {
  // https://stackoverflow.com/a/47606643/5069105
    int b = 0;
    while (x != 0) {
        x &= x-1;
        b++;
    }
    return b;
}

void bench(unsigned long a) {
  clock_t tc;
  int msec;
  int b;
  int num = (int) 1e6;
  
  tc = clock();
  for (int i = 0; i < num; i++)
    b = bitcount(a);
  msec = (clock() - tc) * 1000 / CLOCKS_PER_SEC;
  printf("bitcount : elapsed time: %d.%ds\n", msec/1000, msec%1000);

  tc = clock();
  for (int i = 0; i < num; i++)
    b = bitcount2(a);
  msec = (clock() - tc) * 1000 / CLOCKS_PER_SEC;
  printf("bitcount2: elapsed time: %d.%ds\n", msec/1000, msec%1000);

  tc = clock();
  for (int i = 0; i < num; i++)
    b = bitcount3(a);
  msec = (clock() - tc) * 1000 / CLOCKS_PER_SEC;
  printf("bitcount3: elapsed time: %d.%ds\n", msec/1000, msec%1000);
}

void main(int argc, char **argv) {
  unsigned long a = strtoul(argv[1], NULL, 10);

  int b;
  
  printf("a = %lu\n", a);

  b = bitcount(a);
  printf("has %d 1-bits\n", b);

  b = bitcount2(a);
  printf("has %d 1-bits\n", b);

  bench(a);

}
