#include<stdio.h>
struct Array
{
int A[10];
int size;
int length;
};
void Display(struct Array arr)
{
int i;
printf("\nElements are\n");
for(i=0;i<arr.length;i++)
printf("%d ",arr.A[i]);
}
void Delete(struct Array *arr,int index)
{
int x=0;
int i;
if(index>=0 && index<arr->length)
{

for(i=index;i<arr->length-1;i++)
arr->A[i]=arr->A[i+1];
arr->length--;

}
return 0;
}
int main()
{
struct Array arr1={{2,3,4,5,6},10,5};
Delete(&arr1,3);
Display(arr1);
return 0;
}
