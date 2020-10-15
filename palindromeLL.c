#include "LinkedList.h"

int isPalindromeLL(node *root);

int isPalindromeLL(node *root)
{
  if(root == NULL)
  {
    return 0;
  }

  int flag=0;
  int total = totalNode(root);
  if (total%2 == 0)
  {
    return 0;
  }

  node *tmp = root;
  node *orig = root;
  int i=0;
  while(i < ((total/2) +1))
  {
    tmp = tmp->next;
    i++;
  }
  node *rev = reverseLL(tmp);
  i = 0;
  while(i < total/2)
  {
    flag=0;
    if(orig->data == rev->data)
    {
      flag=1;
    }else{
      flag=0;
      break;
    }
    orig = orig->next;
    rev = rev->next;
    i++;
  }
  return flag;
}


int main()
{
  node *L = createLL(NULL, 1);
  L = createLL(L,4);
  L = createLL(L,7);
  L = createLL(L,4);
  L = createLL(L,1);
  printf("Original: ");
  printLL(L);
  if(isPalindromeLL(L))
  {
    printf("Yes\n");
  }else{
    printf("No\n");
    abort();
  }

  printf("Print L "); 
  printLL(L);
  /* add more element */
  L = createLL(L,1); 
  printf("Original: ");
  printLL(L);
  if(isPalindromeLL(L))
  {
    printf("Yes\n");
  }else{
    printf("No\n");
    abort();
  }
  /* add more element */
  L = createLL(L,4);
  printf("Original: ");
  printLL(L);
  if(isPalindromeLL(L))
  {
    printf("Yes\n");
    abort();
  }else{
    printf("No\n");
  }

  /* NULL test */
  
  if(isPalindromeLL(NULL))
  {
    printf("Yes\n");
    abort();
  }else{
    printf("No\n");
  }

  /* Single node test */
  node *L2 =NULL;
  L2 = createLL(L2,4);
  printf("Original: ");
  printLL(L2);
  if(isPalindromeLL(L2))
  {
    printf("Yes\n");
    abort();
  }else{
    printf("No\n");
  }

  return 0;
}

