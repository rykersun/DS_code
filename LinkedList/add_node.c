#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

typedef struct node node_t;

void print_list(node_t *head)
{
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main(int argc, char **argv)
{
    node_t *head = (node_t *)malloc(sizeof(node_t));
    node_t *current = head;    

    current->next = (node_t *)malloc(sizeof(node_t));
    current = current->next;
    current->data = 1;
    
    current->next = (node_t *)malloc(sizeof(node_t));
    current = current->next;
    current->data = 3;
  
    current->next = (node_t *)malloc(sizeof(node_t));
    current = current->next;
    current->data = 5;
    
    current->next = NULL;
    
    printf("Before insert: ");
    print_list(head);
    
    // create node
    node_t *new_node = (node_t *)malloc(sizeof(node_t));

    // set data
    new_node->data = 2;

    // set next
    new_node->next = (head->next)->next;
    
    // set pre node
    (head->next )->next = new_node;

    printf("After insert: ");
    print_list(head);

    return 0;
}
