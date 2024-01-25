#include <stdio.h>
#include <stdlib.h>
#include <list_management.h>

int main()
{
    int i;
    struct node *element = NULL, *new_element;
    list_print(element);

    element = list_add(element, 0, 100);
    printf("Initial list added-> [0] 100:");
    list_print(element);

    new_element = list_add(element, -1, 200);
    printf("list append element 200");
    list_print(element);

    new_element = list_add(element, -1, 300);
    printf("list append element 300");
    list_print(element);

    new_element = list_add(element, -1, 400);
    printf("list append element 400");
    list_print(element);

    new_element = list_add(element, 2, 222);
    printf("list append element 222");
    list_print(element);

    i = list_rm(element, 1);
    printf("Removed element 1\n");
    list_print(element);

    i = list_rm(element, -1);
    printf("Removed last -1\n");
    list_print(element);

    printf("\n");
}
