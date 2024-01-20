#include <stdio.h>
#include <stdlib.h>

struct node
{
    int number;
    struct node *next;
};

/**
 * @brief
 *
 * @param root
 * @return int
 */
int list_print(struct node *root)
{
    int i = 0;
    struct node *iterator = root;
    if (root == NULL)
    {
        fprintf(stderr, "Trying to print empty list\n");
        return -1;
    }

    do
    {
        printf("[%d] = %d ", i, iterator->number);
        iterator = iterator->next;
        i++;
    } while (iterator != NULL);
    printf("\n");
    return i;
}

struct node *list_add(struct node *root, int insert_index, int number)
{
    int i = 0;
    struct node *new_node = malloc(sizeof(struct node));
    struct node *iterator = root;
    struct node *iterator2 = root;

    new_node->number = number;
    new_node->next = NULL;

    if (root == NULL)
    {
        return new_node;
    }

    do
    {
        i++;
        iterator = iterator2;
        iterator2 = iterator->next;
    } while ((insert_index == -1 || insert_index > i) && iterator->next != NULL);

    if (iterator->next == NULL)
    {
        if (insert_index != -1 && insert_index != i)
        {
            fprintf(stderr, "Trying to insert %d bigger then list size %d\n", insert_index, i);
            return NULL;
        }
        iterator->next = new_node;
    }
    else
    {
        new_node->next = iterator->next;
        iterator->next = new_node;
    }

    return new_node;
}

int list_rm(struct node *root, int insert_index, int number)
{
    return -1;
}

int main()
{
    int i;
    struct node *element = NULL, *new_element;

    // = {.number = 200, .next = NULL},
    // element1 = {.number = 100, .next = &element0};
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

    printf("\n");
}
