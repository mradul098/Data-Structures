#include<stdlib.h>
#include<stdio.h>
struct Array
{
    int A[10];

    int length;
};

void Display(struct Array arr)
{
 int i;
 printf("\nElements are\n");
 for(i=0;i<arr.length;i++)
 printf("%d ",arr.A[i]);
}


struct Array Intersection(struct Array arr1,struct Array arr2)
{
    struct Array arr3;
    int k=0;
    arr3.length=0;
    for(int i=0;i<arr1.length;i++)
    {for(int j=0;j<arr2.length;j++)
    {
        if(arr1.A[i]==arr2.A[j])
        {
            arr3.length++;
            arr3.A[k++]=arr2.A[j];

        }


    }}
    for(int o=0;o<arr3.length;o++)
        for(int p=o+1;p<arr3.length;p++)
    {
        if(arr3.A[o] == arr3.A[p])
        {
            for(int i=p;i<arr3.length-1;i++)
            {
                arr3.A[i]=arr3.A[i+1];
            }
            arr3.length--;
            p--;

        }
    }

        return arr3;
};


int main()
{
 struct Array arr4={{2,9,23,23,21,2,0,21},8};
 struct Array arr5={{2,2,3,3,23,0,0,28,9},9};


 Display(Intersection(arr4,arr5));



}
