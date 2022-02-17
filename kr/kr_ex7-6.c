/*
K&R
Exercise 7-6, page 165
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFSZ 200

int main(int argc, char *argv[])
{
    FILE *fp1, *fp2;
    char l1[BUFSZ], l2[BUFSZ];

    fp1 = fopen(argv[1], "r");
    fp2 = fopen(argv[2], "r");

    while ( fgets(l1, BUFSZ, fp1) && fgets(l2, BUFSZ, fp2) && !strcmp(l1, l2) );

    printf("Files differ at line:\n");
    printf("%s: \t %s\n", argv[1], l1);
    printf("%s: \t %s\n", argv[2], l2);    
    
    
    return 0;
}

