#include<stdlib.h>

int count(int A[])
{
    return sizeof(A)/sizeof(A[0]);
}



int *create(int A[],int Array[])
{
    for(int j=0 ; j<count(Array) ; j++)
    {

        int temp,i=count(Array)+1;
        temp=Array[j];
        while(i>1 && temp>A[i/2])
        {
            A[i]=A[i/2];
            i=i/2;
        }
        A[i]=temp;
    }
    A[count(Array)+2]='\0';
    return A;
}

int main()
{
    int b[] = {10, 20, 30, 25, 5, 40, 35};
    int a[100];
    int *B=create(a,b);
    int i=0;
    while(B[i]!='\0')
    {
        printf("%d ",a[i]);
        i++;
    }
}
