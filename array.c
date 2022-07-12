#include <stdio.h>

int main(void)
{
    int arr[5];
    
    // input data to array
    for (int i = 0; i < 5; i++) {
        printf("Input arr[%d]: ", i);
        scanf("%d", (arr + i));
    }
    
    // print result
    for (int i = 0; i < 5; i++) {
        printf("Array[%d]: %d\n", i, arr[i]);
    }
    
    return 0;
}
