#include <stdio.h>
#include <stdlib.h>

void print_array(int *array_param, int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("[%d] = %d\n", i, array_param[i]);
    }
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

int main()
{
    int array_0[100] = {
        [0] = 10,
        [2] = 20,
        [4] = 40,
        [3] = 30},
        size = 5, i;

    int insert_index = 2, insert_entry = 99;

    printf("0)Before insert !\n");
    print_array(array_0, size);
    printf("\n\n");

    size++;
    insert_array(array_0, size, insert_index, insert_entry);
    printf("1) After insert %d in [%d] !\n", insert_entry, insert_index);
    print_array(array_0, size);

    size++;
    insert_index = 0;
    insert_entry = 98;
    insert_array(array_0, size, insert_index, insert_entry);
    printf("2) After insert %d in [%d] !\n", insert_entry, insert_index);
    print_array(array_0, size);

    size++;
    insert_index = size - 1;
    insert_entry = 97;
    insert_array(array_0, size, insert_index, insert_entry);
    printf("3) After insert %d in [%d] !\n", insert_entry, insert_index);
    print_array(array_0, size);
}
