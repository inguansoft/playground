#include <stdio.h>
#include <stdlib.h>

void print_array(int *array_param, int size, int highlight)
{
    int i;
    for (i = 0; i < size; i++)
    {
        char highligther = '*';
        if (highlight > i)
        {
            highligther = '*';
        }
        else
        {
            highligther = ' ';
        }
        printf("[%d]%c= %d", i, highligther, array_param[i]);
        if (i != size - 1)
        {
            printf(", ");
        }
    }
    printf("\n");
}

void insert_array(int *array_param, int new_size, int insert_index, int insert_entry)
{
    int i;
    for (i = new_size - 1; i > insert_index; i--)
    {
        array_param[i] = array_param[i - 1];
    }
    array_param[i] = insert_entry;
}

#define ARRAY_SIZE 100

int main()
{
    int array_0[ARRAY_SIZE], i, j, k, inject = 0, current_number;

    // Fill in with random values
    for (i = 0; i < ARRAY_SIZE; i++)
    {
        array_0[i] = random() % 100;
    }

    printf("Random unsorted array:\n");
    print_array(array_0, ARRAY_SIZE, -1);

    // Sort algoritmhm
    for (i = 0; i < ARRAY_SIZE; i++)
    {
        // sorted arrays is the start of the array from 0 to i
        // index is i
        // unsorted array is from i to ARRAY_SIZE
        inject = -1;
        current_number = array_0[i];
        for (j = 0; j <= i; j++)
        {
            if (inject > -1 || current_number < array_0[j])
            {
                inject++;
                if (i - inject > 0)
                {
                    array_0[i - inject] = array_0[i - inject - 1];
                }
            }
        }
        if (inject > -1)
        {
            array_0[i - inject] = current_number;
        }

        // printf("Processed array on [%d, %d]:%d\n", i, inject, current_number);
        // print_array(array_0, ARRAY_SIZE, i);
    }

    printf("\nSorted array:\n");
    print_array(array_0, ARRAY_SIZE, -1);
}
