#include <stdio.h>
#include <stdlib.h>
#include <dirent.h> 
#include <time.h>

#define LINE_SIZE 300
#define BUFFER_SZ 5000*LINE_SIZE

void combine(char *fname) {
    DIR *d;
    FILE * fp;
    char line[LINE_SIZE];
    char buffer[BUFFER_SZ];
    short flagHeader = 1;
    buffer[0] = '\0';  // need to init buffer befroe strcat to it
    
    struct dirent *dir;
    chdir("runs");
    d = opendir(".");
    if (d) {
        while ((dir = readdir(d)) != NULL) {
            if ((strstr(dir->d_name, "Hs")) && (strstr(dir->d_name, ".txt")) ) {
                //printf("%s\n", dir->d_name);
                fp = fopen (dir->d_name, "r");
                fgets(line, LINE_SIZE, fp);  // read first line
                if (flagHeader) {  // append it to buffer only once
                    strcat(buffer, line);
                    //printf("  Header is: %s", line);
                    flagHeader = 0;
                }
                fgets(line, LINE_SIZE, fp);  // read second line
                strcat(buffer, line);
                //printf("  Line is: %s", line);
                fclose(fp);
            }
        }
        closedir(d);
        chdir("..");
        //printf("Buffer is: %s", buffer);
        fp = fopen(fname, "w");
        fprintf(fp, buffer);
        fclose(fp);
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

