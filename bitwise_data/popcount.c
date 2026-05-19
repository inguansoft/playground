//Count set bits (Hamming weight)
//Implement popcount() without using __builtin_popcount. 
//Then explain when you'd use the lookup-table variant vs. 
//the Kernighan trick in embedded contexts.

#include <stdint.h>
#include <stdio.h>

uint8_t popcount(uint32_t x) {
  uint8_t count =0;
  while (x > 0) {
    count += (x & UINT32_C(1)) == 1 ? 1 : 0;
    x = x >> 1;
  }
  return count;
}


/* Kernighan's trick hint:
   x & (x-1) clears the lowest set bit */

int main(void) {


  printf("%d expected 2\n", popcount(3));
  printf("%d expected 1\n", popcount(8));
  printf("%d expected 3\n", popcount(7));
  
}
