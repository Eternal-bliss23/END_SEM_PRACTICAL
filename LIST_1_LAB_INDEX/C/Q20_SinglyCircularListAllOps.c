/* Q20: Singly Circular List - All Operations
   Purpose: Menu for insert/delete at begin, end, position and display. */

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
    struct Node *tail;
    if (node == NULL) { printf("Memory allocation failed.\n"); return; }
    node->data = value;
    if (head == NULL)
    {
        node->next = node;
        head = node;
    }
    else
    {
        tail = head;
        while (tail->next != head)
            tail = tail->next;
        node->next = head;
        tail->next = node;
        head = node;
    }
    printf("Inserted %d at beginning.\n", value);
}

void insertEnd(int value)
{
    struct Node *node = malloc(sizeof(*node));
    struct Node *tail;
    if (node == NULL) { printf("Memory allocation failed.\n"); return; }
    node->data = value;
    if (head == NULL)
    {
        node->next = node;
        head = node;
    }
    else
    {
        tail = head;
        while (tail->next != head)
            tail = tail->next;
        tail->next = node;
        node->next = head;
    }
    printf("Inserted %d at end.\n", value);
}

void insertAt(int pos, int value)
{
    struct Node *node, *prev;
    int i;
    if (pos < 1) { printf("Invalid position.\n"); return; }
    if (pos == 1) { insertBegin(value); return; }
    if (head == NULL) { printf("Invalid position.\n"); return; }
    node = malloc(sizeof(*node));
    if (node == NULL) { printf("Memory allocation failed.\n"); return; }
    prev = head;
    for (i = 1; i < pos - 1 && prev->next != head; i++)
        prev = prev->next;
    if (i != pos - 1)
    {
        printf("Invalid position.\n");
        free(node);
        return;
    }
    node->data = value;
    node->next = prev->next;
    prev->next = node;
    printf("Inserted %d at position %d.\n", value, pos);
}

void deleteFirst(void)
{
    struct Node *node;
    if (head == NULL) { printf("List is empty.\n"); return; }
    node = head;
    if (head->next == head)
        head = NULL;
    else
    {
        struct Node *tail = head;
        while (tail->next != head)
            tail = tail->next;
        tail->next = head->next;
        head = head->next;
    }
    printf("Deleted %d from beginning.\n", node->data);
    free(node);
}

void deleteLast(void)
{
    struct Node *cur, *node;
    if (head == NULL) { printf("List is empty.\n"); return; }
    if (head->next == head)
    {
        printf("Deleted %d from end.\n", head->data);
        free(head);
        head = NULL;
        return;
    }
    cur = head;
    while (cur->next->next != head)
        cur = cur->next;
    node = cur->next;
    cur->next = node->next;
    printf("Deleted %d from end.\n", node->data);
    free(node);
}

void deleteAt(int pos)
{
    struct Node *cur, *node;
    int i;
    if (head == NULL) { printf("List is empty.\n"); return; }
    if (pos == 1) { deleteFirst(); return; }
    cur = head;
    for (i = 1; i < pos - 1 && cur->next != head; i++)
        cur = cur->next;
    if (i != pos - 1 || cur->next == head)
    {
        printf("Invalid position.\n");
        return;
    }
    node = cur->next;
    cur->next = node->next;
    printf("Deleted %d from position %d.\n", node->data, pos);
    free(node);
}

void clearList(void)
{
    while (head != NULL)
    {
        struct Node *node = head;
        if (head->next == node)
            head = NULL;              /* last node points to itself */
        else
        {
            head = head->next;
            if (head->next == node)
                head->next = head;    /* new head is now the only node */
        }
        free(node);
    }
}

void display(void)
{
    struct Node *cur = head;
    if (head == NULL) { printf("List is empty.\n"); return; }
    printf("Circular list: ");
    do
    {
        printf("%d -> ", cur->data);
        cur = cur->next;
    } while (cur != head);
    printf("(back to %d)\n", head->data);
}

int main(void)
{
    int choice, value, pos;

    for (;;)
    {
        printf("\n1. Insert begin  2. Insert end  3. Insert at position\n");
        printf("4. Delete first  5. Delete last  6. Delete at position\n");
        printf("7. Display  0. Exit\n");
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
        case 0:
            clearList();
            printf("List cleared. Goodbye.\n");
            return 0;
        default:
            printf("Invalid choice.\n");
        }
    }
    return 0;
}
