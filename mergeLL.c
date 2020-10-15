#include "LinkedList.h"

node * mergeLL(node *L1, node *L2);
node * moveNode(node *root, node *L);

node * moveNode(node *root, node *N)
{
  if(root == NULL)
  {
    node *root = N;
    printf("LLMRG_DEBUG: Moving first node \n");
    root->next = NULL;
#if DEEP_DEBUG
    printLL(root);
#endif
    return root;
  }
  node * tmp = root;
  while(tmp->next != NULL)
  {
    tmp = tmp->next;
  }
  tmp->next = N;
  N->next = NULL;
#if DEEP_DEBUG
  printLL(root);
#endif
  return root;
}


node * mergeLL(node *L1, node *L2){
  if(L1 == NULL)
    return L2;
  if(L2 == NULL)
    return L1;

  node *L = NULL;
  node *lt1 = L1;
  node *lt2 = L2;
  while(1)
  {
    if(lt1 == NULL)
    { 
      node *last = L;
      while(last->next != NULL )
      {
        last = last->next;
      }
      last->next = lt2;
      break;
    }
    if(lt2 == NULL)
    {
      node *last = L;
      while(last->next != NULL )
      {
        last = last->next;
      }
      last->next = lt1;
      break;
    }

    if(lt1->data < lt2->data)
    {
      node *tmp1 = lt1->next;
      L = moveNode(L,lt1);
      lt1 = tmp1;
    }else if(lt1->data > lt2->data){
      node *tmp2 = lt2->next;
      L = moveNode(L,lt2);
      lt2 = tmp2;
    }else {
      /* if data is same */
      node *t1= lt1->next;
      node *t2 = lt2->next;
      L = moveNode(L, lt1);
      lt1 = t1;
      lt2 = t2;
    }
  }
  return L;
}


int main(){

  node *L1;
  L1 = createLL(NULL, 1);
  L1 = createLL(L1, 5);
  L1 = createLL(L1, 9);
  L1 = createLL(L1, 12);
  L1 = createLL(L1, 16);
  L1 = createLL(L1, 55);

  node *L2;
  L2 = createLL(NULL, 2);
  L2 = createLL(L2, 4);
  L2 = createLL(L2, 8);
  L2 = createLL(L2, 12);
  L2 = createLL(L2, 50);

  node *L3;
  L3 = createLL(NULL, 0);
  L3 = createLL(L3, 2);
  L3 = createLL(L3, 4);
  
  printf("L1: ");
  printLL(L1);
  printf("L2: ");
  printLL(L2);
  printf("L3: ");
  printLL(L3);

  node *R1; 
  R1 = mergeLL(L2, L1);
  printf("OUTPUT R1 [L1,L2]: ");
  printLL(R1);

  /* Validation */

  if((findnum(R1,50)== 0) || (findnum(R1,12) == 0) || (findnum(R1,2)==0 ) || (findnum(R1,55)==0))
  {
    abort();
  }

  node *R2; 
  R2 = mergeLL(L2, L3);
  printf("OUTPUT R2 [L2, L3]: ");
  printLL(R2);

  if((findnum(R2,50)== 0) || (findnum(R2,12) == 0) || (findnum(R2,2)==0 ) || (findnum(R2,4)==0))
  {
    abort();
  }


  node *L4, *L5, *R3;
  L4 = createLL(NULL,7);
  L5 = createLL(NULL,1);
  printf("L4: ");
  printLL(L4);
  printf("L5: ");
  printLL(L5);
  R3 = mergeLL(L4,L5);
  printf("OUTPUT R3 [L4,L5]: ");
  printLL(R3);


  printf("NULL TEST\n");
  node *R4, *R5;
  R4 = mergeLL(NULL, NULL);
  printLL(R4);

  R5 = mergeLL(L4, NULL);
  printf("OUTPUT R5 [L4, NULL]: ");
  printLL(R5);

  return 0;
}

