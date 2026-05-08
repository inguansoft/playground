#include <stdint.h>
#include <assert.h>
#include <stdio.h>

#define REG_ADDR  0x40020014UL
volatile uint32_t * const GPIO_OUT =
    (volatile uint32_t *)REG_ADDR;

/* write your macros here */
#define BIT_SET(reg, n)   (UINT32_C(1) << n | reg )
#define BIT_CLR(reg, n)   (~(UINT32_C(1) << n) & reg)
#define BIT_TOG(reg, n)   ((UINT32_C(1) << n) ^ reg )

//  uint32_t sample = 151;
//  EXPECT_EQ(BIT_SET(22, 9), 55);

//int main(int argc, char **argv) {
int main(void) {
  volatile uint32_t *sample;
  
  uint32_t mock_reg = 0x00000022;
  sample = &mock_reg;
  printf("INPUT: 0x%08x\n", *sample);
  printf("%s -> got 0x%08x\n", 
    (BIT_SET(*sample, 8) == 0x00000122)? "PASS" : "FAIL", BIT_SET(*sample, 8));
  printf("%s ->  0x%08x == 0x00000020\n", 
    (BIT_CLR(*sample, 1) == 0x00000020)? "PASS" : "FAIL", BIT_CLR(*sample, 1));
  printf("%s -> got 0x%08x\n", 
    (BIT_TOG(*sample, 8) == 0x00000122)? "PASS" : "FAIL", BIT_TOG(*sample, 8));
  return 0;
}
