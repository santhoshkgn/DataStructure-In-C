#include<stdio.h>
#include<stdlib.h>

typedef struct stu
{
   int data;
   struct stu *pnext;
}st;

st* Addatbegin(st* phead, int data);
void print(st *phead);
st* AddNodeAtMiddle(st *phead, int old_data, int new_data);
static int i;

st* AddNodeAtMiddle(st *phead, int old_data, int new_data)
{
  st *ptemp = NULL, *plcl = NULL;

  ptemp = (st*)malloc(sizeof(st));
  if(ptemp == NULL)
  {
    printf("Failed to allocate the memory:\n");
    return NULL;
  } 
  ptemp->data = new_data;

  plcl = phead;
  while(plcl != NULL)
  {
     if(plcl->data == old_data)
     {
       ptemp->pnext = plcl->pnext;
       plcl->pnext  = ptemp;
       break;  
     }
     plcl = plcl->pnext;
  }
  return phead; 	
}	

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
   if(phead == NULL) 
    return;
   
   printf("The node %d data is %d\n", i++ , phead->data);

   print(phead->pnext);
}	


int main()
{
  st *phead = NULL;
  int data, new_data;

  phead = Addatbegin(phead, 10);
  phead = Addatbegin(phead, 20);
  phead = Addatbegin(phead, 30);
  phead = Addatbegin(phead, 40);
  phead = Addatbegin(phead, 50);

  printf("The data's in the node are:\n");
  print(phead);
  i = 0;

  printf("After which node you want to add the data");
  scanf("%d", &data);
  printf("Enter the node data to be inserted\n");
  scanf("%d", &new_data);

  phead = AddNodeAtMiddle(phead, data, new_data);
  printf("the final nodes are:\n");
  print(phead); 

}
