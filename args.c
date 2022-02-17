#include <stdio.h>
#include <stdlib.h>
#include <dirent.h> 
#include <time.h>

#define LINE_SIZE 300
#define BUFFER_SZ 5000*LINE_SIZE

int main(int argc, char *argv[]) {
    printf("Arguments are:\n");
    for (int i=0; i<argc; i++)
        printf("  %s\n", argv[i]);
}
