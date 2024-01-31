#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    // 0x01
    unsigned int basket = 0x00, i = 0x12345678, x, k = 0x01, shift_counter = 31, direction = -2;
    printf("Trailing back and forth %08x\n", i);
    while (1)
    {
        if (direction != 1)
        {
            x = basket << 1;
            k = 0x01;
        }
        else
        {
            x = basket >> 1;
            k = 0x80000000;
        }
        if (0x00000001 & (i >> shift_counter))
        {
            x = x | k;
        }
        basket = x;

        if (shift_counter == 0 || shift_counter == 31)
        {
            if (direction == -2)
            {
                direction = -1;
            }
            else
            {
                printf("Change direction to %c combo set %08x\n",
                       (direction == 1) ? '>' : '<',
                       basket);
                direction *= -1;
            }
        }
        printf("0x%08x\n", basket);
        shift_counter += direction;
        sleep(1);
    }
}
