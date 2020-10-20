#include<stdlib.h>
struct Array
{
    int A[10];
    int size;
    int length;
};
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
void Display(struct Array arr)
{
 int i;
 printf("\nElements are\n");
 for(i=0;i<arr.length;i++)
 printf("%d ",arr.A[i]);
}

struct Array merge(struct Array *arr1,struct Array *arr2)
{
    struct Array arr3;
    arr3.length=(arr1->length)+(arr2->length);
    int k=0;
    for(int i=0;i<arr1->length;i++)
    {
        arr3.A[k++]=arr1->A[i];

    }
    for(int j=0;j<arr2->length;j++)
    {
        arr3.A[k++]=arr2->A[j];
    }

    return arr3;

}

void Union(struct Array *arr)
{
    for(int i=0;i<arr->length;i++)
        for(int j=i+1;j<arr->length;j++)
    {
        if(arr->A[i]==arr->A[j])
        {

            int t=0;

        {

            for(t=j;t<arr->length-1;t++)
            arr->A[t]=arr->A[t+1];
            arr->length--;

        }

        }
        continue;
}
};

int main()
{
 struct Array arr4={{2,9,21,21,35},10,5};
 struct Array arr5={{2,3,21,2,28},10,5};
 struct Array arr6=merge(&arr4,&arr5);
 printf("\n%d\n",arr6.length);
 Union(&arr6);
 Display(arr6);
 printf("\n%d",arr6.length);

}
