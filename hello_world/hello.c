#include <stdio.h>
#include <stdlib.h>

enum Day { SUN, MON, TUE, WED, THU, FRI, SAT };
enum Mood { HAPPY = 3, SAD = 1, ANXIOUS = 4, SLEEPY = 2 };

struct ClockOfTheLongNow
{
  int year;
  int month=1;
};


int main(void)
{
  enum Day today = THU;
  // puts("Hello world !!!");
  int i = 0;
  struct ClockOfTheLongNow yeah = {1994};
  printf("Year: %d %d %d!!!\n", yeah.year, yeah.month, today);
  for (i = 0; i < 16; i++)
  {
    printf("Hello world %02x !!!", i);
    printf("TEST......\n");
  }
  return EXIT_SUCCESS;
}
