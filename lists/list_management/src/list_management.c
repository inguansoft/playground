#include <stdio.h>
#include <stdlib.h>
#include <list_management.h>

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

/**
 * @brief
 *
 * @param root
 * @param insert_index
 * @param number
 * @return struct node*
 */
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

int list_rm(struct node *root, int delete_index)
{
    int i = 0;
    struct node *iterator = root;
    struct node *iterator2;

    if (root == NULL)
    {
        fprintf(stderr, "Trying to print empty list\n");
        return -1;
    }
    if (delete_index < -1)
    {
        fprintf(stderr, "Removal index needs to be bigger than -1, -1 used to remove last entry from list\n");
        return -1;
    }

    while ((delete_index == -1 || delete_index > i) && iterator->next != NULL)
    {
        i++;
        iterator2 = iterator;
        iterator = iterator->next;
    }

    if (iterator->next == NULL)
    {
        if (delete_index != -1 && delete_index != i)
        {
            fprintf(stderr, "Trying to delete %d bigger then list size %d\n", delete_index, i);
            return -1;
        }
        if (i == 1)
        {
            fprintf(stderr, "Cannot delete element on list with only one element\n");
            return -1;
        }
    }
    iterator2->next = iterator->next;
    free(iterator);
    return 0;
}
