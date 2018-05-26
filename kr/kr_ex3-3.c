#include <stdio.h>

void expand(char *src, char *dst) {
    int s = 0, d = 0;

    // handle leading dash
    if (src[0] == '-') {
	dst[d++] = src[s++];
    }

    // kiss
    do {
        for(char c = src[s]; c != src[s+2] + 1 ; c++)
	    dst[d++] = c;
    } while (src[s += 3]);

    // mark the end of the string
    dst[d] = '\0'; 

    printf("%s\n", src);
    printf("%s\n", dst);
}

void main(int argc, char** argv) {
    char dst[255];
    
    expand(argv[1], dst);
}
