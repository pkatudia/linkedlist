#include "LinkedList.h"

/* Remove duplicate in sorted linkedList only */

void removeDup(node *L);


void removeDup(node *L)
{
  if(L == NULL || L->next == NULL)
  {
    return;
  }

  node *tmp = L;
  node *n;
  while(tmp != NULL && tmp->next != NULL)
  {
#if DEEP_DEBUG
    printLL(L);
#endif
    n= tmp->next;
    if(tmp->data == n->data)
    {
      node *n1 = n->next;
      tmp->next = n1;
      tmp = n1;
      n = NULL;
      free(n);
    }else{
      tmp = tmp->next;
    }
  }
  return;
}



int main()
{
  node *L;
  L = createLL(NULL,1);
  L = createLL(L,2);
  L = createLL(L,2);
  L = createLL(L,4);
  L = createLL(L,4);
  L = createLL(L,5);
  
  printf("Original: ");
  printLL(L);
  removeDup(L);
  printf("DD_Remove: ");
  printLL(L);

  /* Validation */
  if((findnum(L,2) > 1) || (findnum(L,4)> 1))
  {
    abort();
  }


  node *L2;
  L2 = createLL(NULL,1);
  L2 = createLL(L2,1);
  printf("Original: ");
  printLL(L2);
  removeDup(L2);
  printf("DD_Remove: ");
  printLL(L2);

  node *L3;
  L3 = createLL(NULL,4);
  printf("Original: ");
  printLL(L3);
  removeDup(L3);
  printf("DD_Remove: ");
  printLL(L3);

  removeDup(NULL);

  return 0;
}

