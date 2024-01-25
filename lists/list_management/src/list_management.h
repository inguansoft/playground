

#ifndef LIST_MANAGEMENT_H
#define LIST_MANAGEMENT_H

struct node
{
    int number;
    struct node *next;
};

int list_print(struct node *root);

struct node *list_add(struct node *root, int insert_index, int number);

int list_rm(struct node *root, int insert_index, int number);

#endif