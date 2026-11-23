/* Q12: Self-Referential Structure
   Purpose: Create three nodes with malloc, link them, traverse, and free. */

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

int main(void)
{
    struct Node *head, *second, *third, *cur;

    head = malloc(sizeof(struct Node));
    second = malloc(sizeof(struct Node));
    third = malloc(sizeof(struct Node));
    if (head == NULL || second == NULL || third == NULL)
    {
        printf("Memory allocation failed.\n");
        free(head);
        free(second);
        free(third);
        return 1;
    }

    head->data = 10;
    head->next = second;
    second->data = 20;
    second->next = third;
    third->data = 30;
    third->next = NULL;

    printf("Linked list: ");
    cur = head;
    while (cur != NULL)
    {
        printf("%d -> ", cur->data);
        cur = cur->next;
    }
    printf("NULL\n");

    /* Free every node while walking the list. */
    cur = head;
    while (cur != NULL)
    {
        struct Node *next = cur->next;
        free(cur);
        cur = next;
    }

    return 0;
}
