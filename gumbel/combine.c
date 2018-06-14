/*
Combine batch results from the rlc package into one results file, typically results.txt.

The C version is 2x faster than Python.

This unbuffered version is faster than the buffered version.

*/
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h> 
#include <time.h>

#define LINE_SIZE 300

void combine(char *fname) {
    DIR *d;
    FILE *fin;
    FILE *fout;
    struct dirent *dir;
    char header[LINE_SIZE];
    char values[LINE_SIZE];
    short flagHeader = 1;
    
    fout = fopen(fname, "wb");
    chdir("runs");
    d = opendir(".");
    if (d) {
        while ((dir = readdir(d)) != NULL) {
            if ((strstr(dir->d_name, "Hs")) && (strstr(dir->d_name, ".txt")) ) {
                fin = fopen (dir->d_name, "rb");
                fgets(header, LINE_SIZE, fin);  // read header
                fgets(values, LINE_SIZE, fin);  // read values
                if (flagHeader) {  // append it to buffer only once
                    flagHeader = 0;
                    fputs(header, fout);
                }
                fputs(values, fout);
                fclose(fin);
            }
        }
        closedir(d);
        fclose(fout);
    }
}

int main() {
    
    clock_t tc;
    int msec;
    
    tc = clock(); 
    combine("results_c.txt");
    msec = (clock() - tc) * 1000 / CLOCKS_PER_SEC;
    printf("elapsed time: %d.%ds\n", msec/1000, msec%1000);
    return 0;
}

