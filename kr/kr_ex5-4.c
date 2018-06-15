#include <stdio.h>
#include <stdlib.h>

int strlen2(char*);
int strend(char*, char*);

int main(int argc, char *argv[])
{
    if (argc != 3) {
	fprintf(stderr, "Error - Use: strend string substring\n");
	exit(1);
    }

    printf("Substring %s at the end of string.\n",
	   strend(argv[1], argv[2]) ? "occurs" : "does not occur");

    return 0;
}

int strlen2(char *s) {
    int i;
    for (i = 0; *s++; i++);
    return i;
}

int strend(char *s, char *t) {
    
    int ls = strlen2(s),
	lt = strlen2(t);
    
    if (ls < lt)
	return 0;

    int i, j;
    for (i = lt, j = ls;
	 (i >= 0) && (*(t+i) == *(s+j));
	 i--, j--);

    return i < 0 ? 1 : 0;
}
