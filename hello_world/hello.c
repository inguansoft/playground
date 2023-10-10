#include <stdio.h>
#include <stdlib.h>

int main(void) {
  //puts("Hello world !!!");
  int i=0;
  for (i=0;i<16;i++) {
    printf("Hello world %02x !!!", i);
    printf("TEST......\n");
  }
  return EXIT_SUCCESS;

}
