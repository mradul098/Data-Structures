#include <stdlib.h>
struct Node
{
int data;
struct Node *next;
}*front=NULL,*rear=NULL;

void enqueue(int x)
{
struct Node *t;
t=(struct Node*)malloc(sizeof(struct Node));
if(t==NULL)
printf("Queue is FUll\n");
else
{
t->data=x;
t->next=NULL;
if(front==NULL)
front=rear=t;
else
{
rear->next=t;
rear=t;
}
}
}

int dequeue()
{
int x=-1;
struct Node* t;
if(front==NULL)
printf("Queue is Empty\n");
else
{
x=front->data;
t=front;
front=front->next;
free(t);
}
return x;
}
int isEmpty()
{
return front==NULL;
}

void BFS(int G[][7] , int start , int n)
{
    int visited[7]={0};
    int i=start;
    visited[i]=1;
    enqueue(i);

    while(!isEmpty())
    {
        i=dequeue();
        printf("%d",i);

        for(int j=0 ; j<n ; j++)
        {
            if(G[i][j]==1 && visited[j]==0)
            {
                enqueue(j);
                visited[j]=1;
            }
        }
    }
}

void DFS(int G[][7],int start,int n)  //kdse
{
   int i=start;
   static int visited[7]={0}; // its only a one time thing its not going to  change on a recursive call
   visited[i]=1;
   printf("%d",i);
   for(int j=1 ; j<n ; j++)
   {
       if(G[i][j]==1 && visited[j]==0)

       {
           DFS(G,j,n);
           visited[j]=1;
       }
   }
}

int main()
{
int G[7][7]={{0,0,0,0,0,0,0},
{0,0,1,1,0,0,0},
{0,1,0,0,1,0,0},
{0,1,0,0,1,0,0},
{0,0,1,1,0,1,1},
{0,0,0,0,1,0,0},
{0,0,0,0,1,0,0}};
BFS(G,1,4);
return 0;
}
