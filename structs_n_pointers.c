#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Album {
  char name[30];
  char artist[30];
  short year;
  short tracks;
  //char *tracksNames[30];
};
void displayAlbum(struct Album *a);

int main() {
  struct Album album1;
  struct Album *ptr;
  ptr = &album1;
  strcpy(album1.name, "Black Force Domain");
  strcpy(album1.artist, "Krisiun");
  album1.year = 2001;
  album1.tracks = 12;
  displayAlbum(&album1);
  displayAlbum(ptr);
}

void displayAlbum(struct Album *a) {
  printf("%s, ", a->name);
  printf("%s, ", a->artist);
  printf("%d, ", a->year);
  printf("%d tracks.\n", a->tracks);  
}
