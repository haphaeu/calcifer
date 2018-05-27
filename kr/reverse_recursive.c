#include <stdio.h>

// print string s in reverse order
void print_reverse(char *s) {
    if (*s) print_reverse(s+1);
    putchar(*s);
}

void main(void) {
    char s[] = "...sdrawkcab saw I ,ypoohw";
    print_reverse(s);
    putchar('\n');
}
