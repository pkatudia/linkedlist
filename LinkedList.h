/* LinkedList Header file
 * Author : Prakash Katudia <prakash.katudia@gmail.com>
 * 
 */

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<sys/syscall.h>

#define YES 1
#define NO 0

#define DEBUG YES
#define DEEP_DEBUG NO


#define myabort() { \
	printf("Fail-------> %s:%d\n",__FILE__, __LINE__); \
	abort();					   \
	system("touch core.X"); 			   \
}

typedef struct node{
  int data;
  struct node *next;
}node;


void printlog(char *s1)
{
  printf("DEBUGLOG: %s. %s:%d\n",s1,__FILE__, __LINE__);
}

/*List of LinkedList  API*/
node* createLL(node *root, int num);
int totalNode(node *root);
void printLL();
node * deleteLL(node *root);
node * reverseLL(node *root);
node * createLoop(node *root);
int  isSameLL(node *L1, node *L2);
node * getRandomLL(int total, int t);
int findnum(node *root, int num);

/* API definations */
node * createLL(node *root, int num){
  if(root == NULL)
  {
    struct node *tmp = (node *)calloc(1,sizeof(node)); 
    tmp->data = num;
    tmp->next = NULL;
    return tmp;
  }
  /* Add data in last */
  node *tmp = root;
  while(tmp->next != NULL)
  {
    tmp=tmp->next;
  }
  struct node *newNode = (node *)calloc(1,sizeof(node));
  newNode->data = num;
  newNode->next = NULL;
  tmp->next = newNode;
  return root;
}

/* PrintLL */
void printLL(node *root)
{
#if DEBUG
  if(root == NULL)
  {
    printlog("Empty Linkedlist");
    return;
  }
  node *tmp = root;
  while(tmp != NULL)
  {
    printf("%d ",tmp->data);
    tmp = tmp->next;
  }
  printf("\n");
#endif
  return;
}

/* Total Node count */
int totalNode(node * root)
{
  node *tmp = root;
  int count=0;
  while(tmp != NULL)
  {
    count++;
    tmp = tmp->next;
  }
  return count;
}

/* Delete LinkedList */
node * deleteLL(node *root)
{
  if(root == NULL){
    printlog("Already empty");
    return NULL;
  }
  node * tmp = root;
  node *t1;
  while(tmp != NULL){
    t1 = tmp->next;
    free(tmp);
    tmp = t1;
  }
  root = NULL;
  return root;
}

/* Reverse LinkedList */
node * reverseLL(node *root)
{
  if(root == NULL)
  {
    return root;
  }
  node *tmp = root;
  node *prev = NULL;
  while(tmp->next != NULL)
  {
    node *n = tmp->next;
    tmp->next = prev;
    prev = tmp;
    tmp =n;
  }
  tmp->next = prev;
  return tmp;
}

/* Create LOOP in LinkedList [circle] */
node * createLoop(node *root)
{
  if (root == NULL)
  {
    return root;
  }
  node *tmp = root;
  while(tmp->next != NULL)
  {
    tmp = tmp->next;
  }
  tmp ->next = root;
  return root;

}

/* LinkedList is same or not with data matching*/
int isSameLL(node *L1, node *L2)
{
  if(L1 == L2)
  {
    return 1;
  }
  if (totalNode(L1) != totalNode(L2))
  {
    return 0;
  }

  node *t1 = L1;
  node *t2 = L2;
  int ret = 0;
  while(t1->next != NULL)
  {
    ret =0;
    if(t1->data != t2->data)
    {
      break;
    }else{
      ret = 1;
    }
    t1 = t1->next;
    t2 = t2->next;
  }
  return ret;
}


int findnum(node *root, int num){
  if(root == NULL)
  {
    return 0;
  }
  node *tmp = root;
  int count=0;
  while(tmp != NULL)
  {
    if(tmp->data == num)
    {
      count++;
    }
    tmp = tmp->next;
  }
  return count;
}



/* Random LinkedList generator
 * total = number of node
 * t = unsigned int num to keep generate random data
 */
node * getRandomLL(int total, int t)
{
  int i=0;
  srand(t);
  node *L = NULL; 
  for(i =0; i< total; i++)
  {
      L = createLL(L,rand() %100);
  }
  return L;
}
 
