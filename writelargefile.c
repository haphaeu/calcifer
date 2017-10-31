/*

Write a binary file filled with dummy data.

The idea is to quicly create large dummy files.

This is able to create ~ 2 Gb in seconds, 20 GB in less than 1 minute.

@author Haphaeu

*/
#include <stdio.h>

int main(int argc, char *argv[]) {
    if ( argc != 4 ) 
    {
        printf( "usage: %s filename filesize_MB chunksize_kB", argv[0] );
        return 1;
    }
    
    unsigned int fsz = atoi(argv[2]); // MB
    unsigned int csz = atoi(argv[3]); // kB
    unsigned int nchunks = 1000 * fsz / csz; 

    printf("Filesize %d MB\n", fsz);
    printf("Chunksize %d kB\n", csz);
    printf("Number of chunks %d\n", nchunks);
    printf("Working ");

    unsigned char buffer[1000*csz];
    FILE *pf;
    
    unsigned int c;
    csz *= 1000; 
    for (c=0; c < csz; c++) {
            buffer[c] = c%10;
    }
    
    pf = fopen(argv[1],"wb"); 
    fseek(pf, 0, SEEK_SET);

    unsigned int iprog = nchunks/20;
    for (c=0; c < nchunks; c++) {
        fwrite(buffer,sizeof(buffer), 1, pf); 
        if (!(c%iprog)) printf(".");
    }
    fclose(pf);
    printf(" done.\n");

    return 0;
}