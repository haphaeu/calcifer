/*

Example working with file read, write and buffers.

This example only copies the input file. But it can be extended to process
files.

Idea behind is differentiatiing between working with small files that fit entirely into
one buffer and working with large files that needs to be split in chunks.

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAX_LINE_SZ  1024
#define MAX_FILE_SZ  1024*1024
#define MAX_BUFF_SZ  8192


int read_full_buffer(const char *fin, const char *fout) {
    /*
    Reads input file line by line and store contents in a buffer.
    The buffer must be large enough to store the entire input file.
    In the end, buffer is dumped into an output file.
    */
    FILE *fp;
    char line[MAX_LINE_SZ];
    char buffer[MAX_FILE_SZ];
    buffer[0] = '\0';
    
    fp = fopen (fin, "r");
    
    // Checks if buffer is large enough to hold the contents of the input file.
    fseek(fp, 0, SEEK_END); // seek to end of file
    if (ftell(fp) > MAX_FILE_SZ) {  // get current file pointer which is the file size
        printf("Error2: increase MAX_FILE_SZ!\n");
        return -2;
    }
    fseek(fp, 0, SEEK_SET); // seek back to beginning of file
    
    
    // Read the file line by line
    while (fgets(line, MAX_LINE_SZ, fp)) {
        
        // Perform some sanity checks on sizes of line and buffer
        if ( ! (line[strlen(line)-1] == '\n')) {
            printf("Error: increase MAX_LINE_SZ!\n");
            return -1;
        }
        // Append current line to buffer
        strcat(buffer, line);
        printf("Line is (%d)(%d): %s", strlen(line), strlen(buffer), line);
        
    }
    fclose(fp);
    printf("Buffer is (%d):\n%s", strlen(buffer), buffer);
    
    // Save the buffer into an output file
    fp = fopen(fout, "w");
    fprintf(fp, buffer);
    fclose(fp);
    return 0;
}

int read_part_buffer(const char *fin, const char *fout) {
    /*
    Reads input file line by line and store contents in a buffer.
    The buffer does NOT need to be large enough to store the entire file. 
    When buffer is full, its contents is dumped(appended) into a file.
    */
    FILE * fp_in, *fp_out;
    char line[MAX_LINE_SZ];
    char buffer[MAX_BUFF_SZ];  
    buffer[0] = '\0';
    
    fp_in = fopen (fin, "r");
    fp_out = fopen(fout, "w");
    
    // Read the file line by line    
    while (fgets(line, MAX_LINE_SZ, fp_in)) {
        
        // Perform some sanity checks on sizes of line and buffer
        if ( ! (line[strlen(line)-1] == '\n')) {
            printf("Error: increase MAX_LINE_SZ!\n");
            return -1;
        }
        // When buffer is full, saved it to the output file and clear it
        if ( strlen(line) + strlen(buffer) > MAX_BUFF_SZ) { 
            fprintf(fp_out, buffer);                        
            buffer[0] = '\0';                               
        }
        // append current line to buffer
        strcat(buffer, line);  
    }
    // copy the remaining from buffer_small into buffer
    fprintf(fp_out, buffer);
    
    fclose(fp_in);
    fclose(fp_out);
    
    //printf("Buffer small is (%d):\n%s", strlen(buffer_small), buffer_small);
    //printf("Buffer is (%d):\n%s", strlen(buffer), buffer);
    return 0;
}

int main() {
    
    assert(MAX_BUFF_SZ >= MAX_LINE_SZ);
    assert(MAX_FILE_SZ >= MAX_BUFF_SZ);
    read_full_buffer("dummy.txt", "dummy_out.txt");
    read_part_buffer("dummy.txt", "dummy_out2.txt");
    
}

