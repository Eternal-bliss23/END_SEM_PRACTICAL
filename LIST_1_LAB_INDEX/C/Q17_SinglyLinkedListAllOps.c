/* Q17: Singly Linked List - All Operations
   Purpose: Menu for insert/delete at begin, end, position, display, count, search. */

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void insertBegin(int value)
{
    struct Node *node = malloc(sizeof(*node));
    if (node == NULL) { printf("Memory allocation failed.\n"); return; }
    node->data = value;
    node->next = head;
    head = node;
    printf("Inserted %d at beginning.\n", value);
}

void insertEnd(int value)
{
    struct Node *node = malloc(sizeof(*node));
    struct Node *cur;
    if (node == NULL) { printf("Memory allocation failed.\n"); return; }
    node->data = value;
    node->next = NULL;
    if (head == NULL)
        head = node;
    else
    {
        cur = head;
        while (cur->next != NULL)
            cur = cur->next;
        cur->next = node;
    }
    printf("Inserted %d at end.\n", value);
}

void insertAt(int pos, int value)
{
    struct Node *node, *cur;
    int i;
    if (pos < 1) { printf("Invalid position.\n"); return; }
    if (pos == 1) { insertBegin(value); return; }
    node = malloc(sizeof(*node));
    if (node == NULL) { printf("Memory allocation failed.\n"); return; }
    cur = head;
    for (i = 1; i < pos - 1 && cur != NULL; i++)
        cur = cur->next;
    if (cur == NULL)
    {
        printf("Invalid position.\n");
        free(node);
        return;
    }
    node->data = value;
    node->next = cur->next;
    cur->next = node;
    printf("Inserted %d at position %d.\n", value, pos);
}

void deleteFirst(void)
{
    struct Node *node;
    if (head == NULL) { printf("List is empty.\n"); return; }
    node = head;
    head = head->next;
    printf("Deleted %d from beginning.\n", node->data);
    free(node);
}

void deleteLast(void)
{
    struct Node *cur, *node;
    if (head == NULL) { printf("List is empty.\n"); return; }
    if (head->next == NULL)
    {
        printf("Deleted %d from end.\n", head->data);
        free(head);
        head = NULL;
        return;
    }
    cur = head;
    while (cur->next->next != NULL)
        cur = cur->next;
    node = cur->next;
    cur->next = NULL;
    printf("Deleted %d from end.\n", node->data);
    free(node);
}

void deleteAt(int pos)
{
    struct Node *cur = head, *node;
    int i;
    if (head == NULL) { printf("List is empty.\n"); return; }
    if (pos == 1) { deleteFirst(); return; }
    for (i = 1; i < pos - 1 && cur->next != NULL; i++)
        cur = cur->next;
    if (cur->next == NULL) { printf("Invalid position.\n"); return; }
    node = cur->next;
    cur->next = node->next;
    printf("Deleted %d from position %d.\n", node->data, pos);
    free(node);
}

void display(void)
{
    struct Node *cur = head;
    printf("List: ");
    while (cur != NULL)
    {
        printf("%d -> ", cur->data);
        cur = cur->next;
    }
    printf("NULL\n");
}

void count(void)
{
    struct Node *cur = head;
    int n = 0;
    while (cur != NULL) { n++; cur = cur->next; }
    printf("Number of nodes = %d\n", n);
}

void search(int value)
{
    struct Node *cur = head;
    int pos = 1;
    while (cur != NULL && cur->data != value) { cur = cur->next; pos++; }
    if (cur == NULL)
        printf("%d not found.\n", value);
    else
        printf("%d found at position %d.\n", value, pos);
}

int main(void)
{
    int choice, value, pos;

    for (;;)
    {
        printf("\n1. Insert begin  2. Insert end  3. Insert at position\n");
        printf("4. Delete first  5. Delete last  6. Delete at position\n");
        printf("7. Display  8. Count nodes  9. Search  0. Exit\n");
        printf("Enter choice: ");
        if (scanf("%d", &choice) != 1)
            break;
        switch (choice)
        {
        case 1:
        case 2:
            printf("Enter value: ");
            if (scanf("%d", &value) != 1) break;
            if (choice == 1) insertBegin(value); else insertEnd(value);
            break;
        case 3:
            printf("Enter position: ");
            if (scanf("%d", &pos) != 1) break;
            printf("Enter value: ");
            if (scanf("%d", &value) != 1) break;
            insertAt(pos, value);
            break;
        case 4: deleteFirst(); break;
        case 5: deleteLast(); break;
        case 6:
            printf("Enter position: ");
            if (scanf("%d", &pos) != 1) break;
            deleteAt(pos);
            break;
        case 7: display(); break;
        case 8: count(); break;
        case 9:
            printf("Enter value to search: ");
            if (scanf("%d", &value) != 1) break;
            search(value);
            break;
        case 0:
            while (head != NULL)
            {
                struct Node *next = head->next;
                free(head);
                head = next;
            }
            printf("List cleared. Goodbye.\n");
            return 0;
        default:
            printf("Invalid choice.\n");
        }
    }
    return 0;
}
