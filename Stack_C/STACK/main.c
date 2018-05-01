#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

void PrintArray(int* array,int arr_size){

    int i;

    printf("Array is:\n");

    for(i = 0; i < arr_size;++i)
        printf("%d,",array[i]);
}

int main()
{
    Data* stack = NULL;

    Insert(&stack,666);
    Insert(&stack,-999);
    Insert(&stack,555);
    Insert(&stack,888);

    int arr[4] = {0};
    int arr_size = sizeof(arr)/sizeof(arr[0]);

    int i;
    for (i = 0; i < arr_size;++i)
            arr[i] = Pop(&stack);

    PrintArray(&arr,arr_size);



    PrintStack(stack);
}
