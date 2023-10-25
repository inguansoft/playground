#include <stdio.h>
#include <stdlib.h>

struct ClockOfTheLongNow
{
  int year;
};

int main(void)
{
  // puts("Hello world !!!");
  int i = 0;
  struct ClockOfTheLongNow yeah = {1994};
  printf("Year: %d !!!\n", yeah.year);
  for (i = 0; i < 16; i++)
  {
    printf("Hello world %02x !!!", i);
    printf("TEST......\n");
  }
  return EXIT_SUCCESS;
}
