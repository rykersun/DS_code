#include <stdio.h>

void print_list(int *p, int size)
{
    printf("list: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", *(p + i));
    }
    printf("\n");
}

void sort(int *p, int size)
{
    int pivot = *p;
    int lower[size], higher[size];
    int l_counter = 0, h_counter = 0;
    
    for (int i = 0; i < size; i++) {
        if (*(p + i) != pivot) {
            (*(p + i) > pivot) ? (higher[h_counter++] = *(p + i)) : (lower[l_counter++] = *(p + i));
        }
    }
    
    if (h_counter == 1 && l_counter == 1) {
        return 1;
    }
    return 0;
    
    // debug
    printf("lower: ");
    for (int i = 0; i < l_counter; i++) {
        printf("%d ", lower[i]);
    }
    printf("\n");
    printf("pivot: %d\n", *p);
    printf("higher: ");
    for (int i = 0; i < h_counter; i++) {
        printf("%d ", higher[i]);
    }
    printf("\n");
    
    while (!sort())
}

int main(void)
{
    int unsort[10] = {2, 4, 5, 1, 6, 7, 8, 3, 9, 10};
    
    printf("before: ");
    print_list(unsort, 10);
    
    sort(unsort, 10);
    
    return 0;
}