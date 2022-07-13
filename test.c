#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

typedef struct node node_t;

void print_list(node_t *);
node_t *create_node(int);
void create_list(node_t **, int *, int);

int main(void)
{
    int data[5] = {1, 2, 3, 4, 5};
    node_t *head = NULL;

    create_list(&head, data, 5);
    print_list(head);
    
    free(head);

    return 0;
}

void print_list(node_t *list_head)
{
    node_t *origin = list_head;
    printf("Graph: ");
    while (list_head != NULL) {
        printf("%d -> ", list_head->data);
        list_head = list_head->next;
    }
    printf("NULL\n");
    printf("\n");
    list_head = origin;
    while (list_head != NULL) {
        printf("data: %d, address: %p, next address: %p\n", list_head->data, list_head, list_head->next);
        list_head = list_head->next;
    }
}
node_t *create_node(int new_data)
{
    node_t *result = (node_t *)malloc(sizeof(node_t));
    result->data = new_data;
    result->next = NULL;
    return result;
}
void create_list(node_t **list_head, int *data_pointer, int data_size)
{
    node_t *current = NULL;
    for (int i = 0; i < data_size; i++) {
        if (i == 0) {
            *list_head = create_node(*(data_pointer + i));
            current = *list_head;
            continue;
        }
        current->next = create_node(*(data_pointer + i));
        current = current->next;
    }
}
