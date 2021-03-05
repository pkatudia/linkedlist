#include "LinkedList.h"


void addnodeLL(node **L, node *n)
{
    struct node *root = *L;
    if (*L == NULL){
        *L = n;
        return;
    }
    while((root)->next != NULL)
    {
       root = (root)->next;
    }
    (root)->next = n;
    return;
}


node * addtwoLL(node *L1, node *L2)
{
  if (L1 == NULL)
      return L2;
  if (L2 == NULL)
      return L1;
  
  struct node *tmpL1 = L1;
  struct node *tmpL2 = L2;
  struct node *L3 = NULL;


  static  int data, sum = 0;
  while(tmpL1 != NULL || tmpL2 !=NULL)
  {
      if (tmpL1)
      {
        data = tmpL1->data + data;
        tmpL1 = tmpL1->next;
      }
      if (tmpL2) {
        data = tmpL2->data + data;
        tmpL2 = tmpL2->next;
      }
      sum = data%10;
      data = data/10;
      node *n = (node *)malloc(sizeof(node));
      n->data = sum;
      n->next = NULL;
      addnodeLL(&L3, n);
  }
  if (data != 0)
  {
      node *c = (node *)malloc(sizeof(node));
      c->data = data;
      c->next = NULL;
      addnodeLL(&L3, c);
  }
  return L3;
}



int main(){
  node *L1 = createLL(NULL, 9);
  L1 = createLL(L1, 9);
  L1 = createLL(L1, 9);
  L1 = createLL(L1, 9);
  L1 = createLL(L1, 9);
  L1 = createLL(L1, 9);
  L1 = createLL(L1, 9);
  L1 = createLL(L1, 9);
  node *L2 = createLL(NULL, 9);
  L2 = createLL(L2, 9);
  L2 = createLL(L2, 9);
  L2 = createLL(L2, 9);
  L2 = createLL(L2, 9);
  L2 = createLL(L2, 9);
 
  printLL(L1);
  printLL(L2);
  node *L3 = addtwoLL(L1, L2);
  printLL(L3);

  /* Test 1:
   * expected result: 8 9 9 9 9 9 0 0 1 
   * */

  node *test = createLL(NULL, 8);
  test = createLL(test, 9);
  test = createLL(test, 9);
  test = createLL(test, 9);
  test = createLL(test, 9);
  test = createLL(test, 9);
  test = createLL(test, 0);
  test = createLL(test, 0);
  test = createLL(test, 1);
 
  if (isSameLL(test, L3) != 1)
    {myabort();}
  else 
    printf("PASS\n");
  
  /* Test 2: NULL Test
   */


  node *test2 = addtwoLL(L1, NULL);
  if (!isSameLL(test2,L1))
    {myabort();}
    
  return 0;
}


