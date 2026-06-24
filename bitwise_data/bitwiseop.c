#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    int n = 1, high = 4, low = 2, new_val = 0x5;
    // Registers have const addresses, but their contents are mutable, so pointer is volatile
    volatile uint32_t *const REG = (volatile uint32_t *)0x40020000;
    // SET OR
    *REG |= (UINT32_C(1) << n);
    // CLEAR AND
    *REG &= ~(UINT32_C(1) << n);
    // TOGGLE XOR
    *REG ^= (UINT32_C(1) << n);
    // Read a bit
    uint32_t bit = (*REG >> n) & UINT32_C(1);

    // READ a bit field (bits [high:low])
    uint32_t field = (*REG >> low) & ((UINT32_C(1) << (high - low + 1)) - 1);

    // WRITE a bit field without disturbing other bits
    uint32_t mask = ((UINT32_C(1) << (high - low + 1)) - 1) << low;
    uint32_t value = new_val << low;
    *REG = (*REG & ~mask) | (value & mask);
    // The (value & mask) guards against new_val being too wide — common oversight
}