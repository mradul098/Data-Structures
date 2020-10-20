#include<stdlib.h>
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


struct Array  Difference(struct Array *arr,struct Array *arr2)
{
    struct Array arr3;
    arr3.length=0;
    int k=0;
    for(int i=0;i<arr->length;i++)
    {
        if(arr->A[i]!=arr2->A[i])
        {
            arr3.length++;
            arr3.A[k++]=arr->A[i];
        }

    }
    return arr3;
};



int main()
{
 struct Array arr4={{2,9,21,21,35},10,5};
 struct Array arr5={{2,3,21,2,28},10,5};

  Display(Difference(&arr4,&arr5));

}
