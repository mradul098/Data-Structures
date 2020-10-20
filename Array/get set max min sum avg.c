#include<stdio.h>
#include<stdlib.h>

struct Array
{
    int A[20];
    int size;
    int length;
};
void set(struct Array *arr,int index,int x)
{
   if(index>=0 && index<arr->length)
        arr->A[index]=x;
}
int get(struct Array arr,int index)
{
   if(index>=0 && index<arr.length)
    return arr.A[index];
}
int max(struct Array arr)
{
    int max=arr.A[0];
    for(int i=1;i<arr.length;i++)
    {
        if(arr.A[i]>max)
            max=arr.A[i];
    }
    return max;

}
int min(struct Array arr)
{
    int min=arr.A[0];
    for(int i=1;i<arr.length;i++)
    {
        if(arr.A[i]<min)
            min=arr.A[i];
    }
    return min;

}
int sum(struct Array *arr)
{
    int total=0;
    for(int i=0;i<arr->length;i++)
    {
        total+=arr->A[i];
    }
    return total;
}

int main()
{
    struct Array arr1={{1,2,3,4,5,6,7,8,9},10,9};
    printf("%d",sum(&arr1));
    printf("%d",max(arr1));
    printf("%d",min(arr1));
        set(&arr1,3,89);
    printf("%d",get(arr1,3));

}
