#include <stdio.h>

// malloc required
#include <stdlib.h>

// define node
struct node
{
    int data;
    struct node *next;
};

int main(void)
{
    // head node without the data
    struct node *head = (struct node *)malloc(sizeof(struct node));
    struct node *origin_head = head;
    
    // add a node next to the head node
    head->next = (struct node *)malloc(sizeof(struct node));
    
    // move head to the next node
    head = head->next;
    
    // set node's data
    head->data = 1;
    
    // set the last node's next to NULL (meaning this node is the end of the list)
    head->next = NULL;
    
    head = origin_head;
    
    // free
    while (head != NULL) {
        free(head);
        head = head->next;
    }

    return 0;
}
