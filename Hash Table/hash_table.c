#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#define table_size 10

int findHashIndex(char *name)
    {
        int Hash=0;

        for(int i=0 ; i<strlen(name) ; i++)
        {
            Hash = Hash + name[i];
        }
        return Hash%10;
    }

struct item
  {
    char * name;
    char * drink;
    struct item *next;
  };

  struct item *H[table_size];

  void Additem(char * n , char * drink )
  {
    int index=findHashIndex(n);
    if(strcmp(H[index]->name,"empty")==0)
    {
        H[index]->name = n;
        H[index]->drink = drink;
        H[index]->next = NULL;
    }
    else
    {
        struct item *ptr = H[index];
        struct item *it = (struct item*)malloc(sizeof(struct item));

        while(ptr->next!=NULL)
            ptr = ptr->next;
        it->name = n;
        it->drink = drink;
        it->next=NULL;
        ptr->next=it;
    }
  }


  int numOfItemsinIndex(int index)
  {
      int count=1;
      struct item *ptr = H[index];

      if(strcmp(ptr->name,"empty")==0)
      {
          return 0;
      }

      while(ptr->next!=NULL )   //last mistake commited : i was doing ptr->name != "empty"  which is equivalent to saying ki jab tak p->name empty na ho wo to ek entry ke baad hi true ho jayega and then we will not be able to deal with other collisions
      {
          ptr = ptr->next;
          count++;
      }
      return count;
  }

  void printtable()
{
    for(int i=0 ; i<table_size ; i++)
    {
        int num = numOfItemsinIndex(i);

        printf("______________\n");
        printf("number of items in this index %d is %d\n",i,num);
        printf("name in head list :%s\n",H[i]->name);
        printf("drink he/she prefer :%s\n",H[i]->drink);
        printf("______________\n");
    }
}

  void findDrink(char *nm)
  {
      int index = findHashIndex(nm);
      struct item *ptr= H[index];
      if(strcmp(ptr->name,nm)==0)
          {
            printf("______________\n");
            printf("%s prefer %s\n",nm,H[index]->drink);
            printf("______________\n");
            return;
          }

      else
        while(ptr!=NULL)
      {
          if(strcmp(ptr->name,nm)==0)
          {
            printf("______________\n");
            printf("%s prefer %s",ptr->name,ptr->drink);//cout<<"drink "<<name<<" prefer :"<<ptr->drink<<endl;
            printf("______________\n");
            return;
          }
          else
            ptr = ptr->next;
      }

      printf(" Given person not found\n");
  }

  bool removeItem(char * name)
  {
      int index = findHashIndex(name);
      struct item *ptr= H[index];
      struct item *ptr2= H[index]->next;

    //case 1: bucket is empty
    if(strcmp(H[index]->name,"empty")==0)
    {
        printf("name not found \n");
        return true;
    }

    //case 2: only one item contained in the bucket and has a matching name

    else if(H[index]->name == name)
    {
        H[index]=H[index]->next;
        return true;
    }

    //case 3: bucket contains items but its not the first one
    //case 3.1:no match

    while(ptr2->name!=name && ptr2!=NULL)
    {
        ptr=ptr->next;
        ptr2=ptr2->next;
    }
    if(ptr2==NULL)
    {
        printf("match not found \n");
        return false;
    }
    else  //case 3.2:match found
    {
        //if its the last one
        if(ptr2->next==NULL)
        {
            ptr->next=NULL;
            return true;
        }
        else //if its stuck in the middle
            {
                ptr->next=ptr2->next;
                free(ptr2);
                return true;
            }
    }
  }





int main()
{


    for(int i=0 ; i<table_size ; i++)
  {
      H[i]=(struct item*)malloc(sizeof(struct item));
      H[i]->name = "empty";
      H[i]->drink = "empty";
      H[i]->next = NULL;
  }




    Additem("andy","mango juice");
    Additem("Angela","cough syrup");
    Additem("oscar","hotwater");
    Additem("phylis","anything");

    printtable();

    char name[20];
    while(strcmp(name,"exit")!=0)
    {
        printf("search for \n");
        scanf("%s",name);
        findDrink(name);
    }

}

