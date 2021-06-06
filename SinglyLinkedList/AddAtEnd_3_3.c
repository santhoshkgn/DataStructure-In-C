#include<stdio.h>
#include<stdlib.h>

typedef struct stu
{
   int data;
   struct stu *pnext;
}st;

st* AddatEnd(st* phead, int data);
void print(st *phead);

st* AddatEnd(st* phead, int data)
{
  st *ptemp = NULL, *ptemp1 = NULL;

  ptemp = (st*)malloc(sizeof(st));
  if(ptemp == NULL)
  {
     printf("Faild to allocate the memory:\n");
     return NULL;
  } 
  ptemp->data = data;

  if(phead == NULL)
  {
    ptemp->pnext = phead;
    phead = ptemp;   
  }
  else
  {
     ptemp1 = phead;
     while(ptemp1->pnext != NULL)
        ptemp1 = ptemp1->pnext;
     
     ptemp->pnext  = ptemp1->pnext;
     ptemp1->pnext = ptemp;
  }
  return phead;
}	

void print(st *phead)
{
   static int i;

   if(phead == NULL) 
    return;
   
   printf("The node %d data is %d\n", i++ , phead->data);

   print(phead->pnext);
}	


int main()
{
  st *phead = NULL;
  int data, new_data;

  phead = AddatEnd(phead, 10);
  phead = AddatEnd(phead, 20);
  phead = AddatEnd(phead, 30);
  phead = AddatEnd(phead, 40);
  phead = AddatEnd(phead, 50);

  printf("The data's in the node are:\n");
  print(phead);
 
}
