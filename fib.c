#include <stdio.h>
#include <stdlib.h>

int SIZE = 999;
typedef unsigned long long ull;
ull* CACHE;

// naive recursive implementation
// leading to a gazilion recursion calls...
// ok up to 30 elements...
ull fib_naive(int n) {
    if (n == 0)
        return 0;
    else if (n <= 2)
        return 1;
    else
        return fib_naive(n-1) + fib_naive(n-2);
}

// memoization cache for fib
void init_fib_cache() {
    CACHE = (ull*) malloc(SIZE * sizeof(ull));
    CACHE[0] = 0;
    CACHE[1] = 1;
    for (int i = 2; i < SIZE; ++i)
        CACHE[i] = -1;
}

// fib with memoization
// can calc up to fib(93)=12200160415121876738,
// limited by unsigned long long type
ull fib(int n) {
    if (CACHE[n] == -1)
        CACHE[n] = fib(n - 1) + fib(n - 2);
    return CACHE[n];
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Use: %s N\n", argv[0]);
        return 1;
    }
    int n = atoll(argv[1]);
    if (n <= 0) {
        printf("Error: N must be positive larger than zero.\n");
        return 2;
    }
    init_fib_cache();
    printf("fib(%d) = ", n);
    ull f = fib(n);
    printf("%llu\n", f);
    
    printf("fib_naive(%d) = ", n);
    fflush(stdout);  // will take a while if n > 35-ish
    f = fib_naive(n);
    printf("%llu\n", f);

    return 0;
}
