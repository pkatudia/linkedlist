#include "LinkedList.h"
#include <string.h>

/* LinkedList.h test code */

int main()
{
 node *L1 = createLL(NULL, 1);
 L1 = createLL(L1, 2);
 L1 = createLL(L1, 3);
 L1 = createLL(L1, 4);
 L1 = createLL(L1, 5);

 if((findnum(L1,1) == 0) || (findnum(L1,5) == 0)){
   abort();
 }

 printLL(L1);
 printf("total Node = %d\n", totalNode(L1));


 node *L2 = createLL(NULL, 1);
 L2 = createLL(L2, 2);
 L2 = createLL(L2, 3);
 L2 = createLL(L2, 4);
 L2 = createLL(L2, 5);

 /*create LOOP */
/* 
 L1 = createLoop(L1);
 printLL(L1);
*/
 if(isSameLL(L1,L2))
 {
   printf("Same Linked List \n");
 }else {
   printf("Different LinkedList \n");
   abort();
 }


 L1 = reverseLL(L1);
 printf("Reverse LL : ");
 printLL(L1);

 L1 = deleteLL(L1);
 printf("Delete LL \n");
 printf("Testing NULL LinkedList\n");
 printf("total Node = %d\n", totalNode(L1));
 printLL(L1);
 if(totalNode(L1) !=0)
   abort();

 L1 = reverseLL(L1);
 printf("Reverse LL : ");
 printLL(L1);
 if(totalNode(L1) !=0)
   abort();

 /* Random Linkedlist */
 printf("Random LinkedList \n");
 node *Ran1 = getRandomLL(10, 1);
 printf("Ran1: ");
 printLL(Ran1);
 if(totalNode(Ran1) != 10)
   abort();

 node *Ran2=getRandomLL(20, 5);
 printf("Ran2: ");
 printLL(Ran2);
 if(totalNode(Ran2) != 20)
   abort();
 return 0;
}

