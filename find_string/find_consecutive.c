#include <stdio.h>
#include <string.h>
// Find substring with highest consecutive repetition

void find_top_consecutive_repeat(char *input_string, char *solution_string)
{
    int len, current_count = 1, max_count = 1, max_i;
    if (input_string != NULL)
    {
        len = strlen(input_string);
        if (len < 2)
        {
            strcpy(solution_string, input_string);
            solution_string[len] = '\0';
        }
        else
        {
            while (len > 0)
            {
                if (input_string[len] == input_string[len - 1])
                {
                    current_count++;
                    if (current_count > max_count)
                    {
                        max_count = current_count;
                        max_i = len;
                    }
                }
                else
                {
                    current_count = 1;
                }
                len--;
            }
            strncpy(solution_string, input_string + max_i, max_count);
            solution_string[max_count] = '\0';
        }
    }
}

int main()
{
    char input[] = "abcddddefefefefef",
         actual[100], // optimize size allocation
         expected[] = "dddd";
    find_top_consecutive_repeat(input, actual),

    // Assert
    printf("%s\n", actual);
    printf("%s\n", expected);
}