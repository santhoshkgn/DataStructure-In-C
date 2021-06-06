#include<stdio.h>
#include<stdlib.h>

typedef struct stu
{
   int data;
   struct stu *pnext;
}st;

st* Addatbegin(st* phead, int data);
void print(st *phead);


st* Addatbegin(st* phead, int data)
{
   st *pCur = NULL;
   pCur = (st*)malloc(sizeof(st));
   if(pCur == NULL)
   {
      printf("pCur node is NULL:\n");
      return NULL;
   } 

   pCur->data  = data;
   pCur->pnext = phead;

   return pCur;
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
  phead = Addatbegin(phead, 10);
  phead = Addatbegin(phead, 20);
  phead = Addatbegin(phead, 30);
  phead = Addatbegin(phead, 40);
  phead = Addatbegin(phead, 50);

  print(phead);
}
