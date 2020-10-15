#include "LinkedList.h"

void sortLL(node *L)
{
  if(L == NULL)
  {
    return;
  }
  int len = totalnode(L);
  node *L1 = 
}



int main()
{
  node *L1 = createLL(NULL,1);
  L1 = createLL(L1, 5);
  L1 = createLL(L1, 2);
  printLL(L1);
  sortLL(L1);
  printLL(L1);
  return 0;
}

