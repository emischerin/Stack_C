#include <stdio.h>
#include <stdlib.h>

typedef struct Data{
    int data;
    struct Data* next;
}Data;

/**< FUNCTIONS PROTOTYPES */

void PrintStack(Data* ptr);
void Insert(Data** ptr, int data);
void InsertFirstElement(Data** ptr,int data);
void InsertElement(Data** ptr,int data);

void PrintStack(Data* ptr){

    Data* tmp = ptr;

    while(tmp){
        printf("%d\n",tmp->data);
        tmp = tmp->next;
    }

    free(tmp);

}

void Insert(Data** ptr, int data){

    if (!(*ptr))
        InsertFirstElement(&*ptr,data);

    else
        InsertElement(&*ptr,data);
}

void InsertFirstElement(Data** ptr, int data){

    *ptr = malloc(sizeof(Data));
    (*ptr)->data = data;
    (*ptr)->next = NULL;
}

void InsertElement(Data** ptr,int data){

    Data* newnode = malloc(sizeof(Data));
    newnode->data = data;
    newnode->next = *ptr;
    *ptr = newnode;
}

int Pop(Data** ptr){

    if(!(*ptr))
        return NULL;
    else
        return PopElement(&*ptr);


}

int PopElement(Data** ptr){

    Data* tmp = *ptr;
    int pop = (*ptr)->data;

    *ptr = (*ptr)->next;
    free(tmp);

    return pop;
}

