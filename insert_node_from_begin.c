#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void print_list(struct node *head)
{
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main(void)
{
    struct node *head = (struct node *)malloc(sizeof(struct node));
    struct node *a = (struct node *)malloc(sizeof(struct node));
    struct node *b = (struct node *)malloc(sizeof(struct node));
    struct node *c = (struct node *)malloc(sizeof(struct node));
    struct node *d = (struct node *)malloc(sizeof(struct node));
    
    a->data = 2;
    b->data = 4;
    c->data = 6;
    d->data = 8;
    
    head->next = a;
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = NULL;
    
    print_list(head->next);
    
    struct node *x = (struct node *)malloc(sizeof(struct node));
    x->data = 1;
    
    x->next = head->next;
    head->next = x;
    
    print_list(head->next);
    
    return 0;
}
