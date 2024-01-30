#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
 * @brief Create atoi function that takes the same arguments as atoi
 * from the std library, return 0 if not a valid string for int conversion
 *
 * @param string_input char[] pointer string input to be converted into int
 * @return int converted number
 */
int me_atoi(char *string_input)
{
    int i = 0, negative_number = 0,
        msi = -1, lsi = -1,
        number = 0, current_digit;
    while (string_input[i] != '\0' && string_input[i] != '.')
    {
        if (string_input[i] >= 48 && string_input[i] <= 57)
        {
            if (msi == -1)
            {
                msi = i;
            }
        }
        else
        {
            if (msi == -1)
            {
                if (string_input[i] == '-')
                {
                    if (negative_number > 0)
                    {
                        return 0;
                    }
                    else
                    {
                        negative_number = 1;
                    }
                }
                if (string_input[i] == '+')
                {
                    if (negative_number > 0)
                    {
                        return 0;
                    }
                    else
                    {
                        negative_number = 2;
                    }
                }
            }
            else
            {
                return 0;
            }
        }
        i++;
    }
    if (msi != -1)
    {
        lsi = i - 1;
    }
    else
    {
        fprintf(stderr, "Invalid sequence, unsafe to convert to integer");
        return 0;
    }

    for (i = 0; i <= lsi - msi; i++)
    {
        // 0 - 9
        //-48->57
        number += (string_input[lsi - i] - 48) * pow(10, i);
    }
    if (negative_number == 1)
    {
        number *= -1;
    }
    return number;
}

int main()
{
    char string_number[] = " - 1149.9";
    int int_number_fc = atoi(string_number);
    int int_number_me = me_atoi(string_number);

    printf("%s converted to %d == %d\n", string_number, int_number_fc, int_number_me);
    return 0;
}