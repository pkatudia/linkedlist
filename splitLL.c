#include "LinkedList.h"

void validateMe(int, node *, node *);

void splitLL(node *L, node **L1, node **L2)
{
  if(L == NULL)
  {
    return;
  }
  node *prev;
  node *slow = L;
  node *fast = L;
  while(fast != NULL)
  {
    fast = fast->next;
    prev = slow;
    if(fast != NULL){
      slow = slow->next;
      fast = fast->next;
    }
  }

  /* Condition for even/odd
   * if odd, prev = slow.
   */
  if(prev == slow)
    *L2 = slow->next;
  else
    *L2 = slow;
  prev->next = NULL;
  *L1 = L;
}

int main()
{
  /* Test 1 */
  node *L;
  int N=10;
  L = getRandomLL(N, 5);
  node *L1,*L2;
  L1 = L2 = NULL;
  printLL(L);
  splitLL(L, &L1, &L2);
  printf("LinkedList 1: ");
  printLL(L1);
  printf("LinkedList 2: ");
  printLL(L2);
  validateMe(N,L1,L2);
  
  /* Test 2 */
  
  node *M;
  N=11;
  M = getRandomLL(N,10);
  node *M1, *M2;
  M1 = M2 = NULL;
  splitLL(M, &M1, &M2);
  validateMe(N,M1,M2);
  return 0;
}

/* Validation */
void validateMe(int N, node *L1, node *L2)
{
  if((totalNode(L1) + totalNode(L2)) != N)
  {
    printlog("ERROR: Split is not proper\n");
    abort();
  }

  return;
}

