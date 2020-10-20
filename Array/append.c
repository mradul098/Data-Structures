#include<stdio.h>
#include<stdlib.h>

struct Array
{
    int A[20];
    int size;
    int length;
};
void display(struct Array arr)
{
    int i;
    printf("\nElements are\n");
    for(i=0;i<arr.length;i++)
        printf("%d",arr.A[i]);
}
void append(struct Array *arr,int x)
{
    if(arr->length<arr->size)
        arr->A[arr->length++]=x;
}
int main()
{
    struct Array arr={{2,3,4,5,6},20,5};
    append(&arr,10);
    display(arr);
    return 0;

}
