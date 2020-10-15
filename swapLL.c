#include "LinkedList.h"

void swapLL(node *root);


void swapLL(node *root)
{
  if(root == NULL || root->next == NULL)
  {
    return;
  }
  node *tmp = root;
  while(tmp != NULL && tmp->next != NULL)
  {
#if DEEP_DEBUG
    printLL(root);
#endif
    node *n = tmp->next;
    int data = tmp->data;
    tmp->data = n->data;
    n->data = data;
    tmp = n->next;
  }
  return;
}


int main()
{
  int t1,t2=0;
  node *L1 = getRandomLL(11,1);
  printf("Original: ");
  printLL(L1);
  t1 = totalNode(L1);
  swapLL(L1);
  printf("SWAP_LL: ");
  printLL(L1);
  t2 = totalNode(L1);

  /* Validation */
  if(t1 != t2)
    abort();

  t1=0;t2=0;
  node *L10 = getRandomLL(10,3);
  printf("Original: ");
  printLL(L10);
  t1 = totalNode(L10);
  swapLL(L10);
  printf("SWAP_LL: ");
  printLL(L10);
  t2 = totalNode(L10);

  /* Validation */
  if(t1 != t2)
    abort();

  /* One node testing */
  t1=0; t2=0;
  node *L2 = createLL(NULL,10);
  printf("Original: ");
  printLL(L2);
  t1 = totalNode(L2);
  swapLL(L2);
  printf("SWAP_LL: ");
  printLL(L2);
  t2 = totalNode(L2);

  /* Validation */
  if(t1 != t2)
    abort();

  /* NULL Testing */
  swapLL(NULL);
  return 0;
}

