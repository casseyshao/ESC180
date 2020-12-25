// Lab 9
// Linked List
// compile with gcc -pedantic

#include <stdio.h>
#include <stdlib.h>
#include "ll.h"

int ll_add_to_head(llnode **head, int val) {
   llnode *old_head;
   if (head == NULL) {
      return -1;
   }
	old_head = *head;

   *head = (llnode *) malloc(sizeof( llnode));
   (*head) -> val = val;
	(*head) -> next = old_head;
	return 0;
}

int ll_add_to_tail(llnode **head, int val) {
   if (head == NULL) {
      return -1;
   }
   if (*head == NULL) {
      *head = ( llnode *) malloc(sizeof(llnode));
      (*head) -> val = val;
      (*head) -> next = NULL;
      return 0;
   } else { /* recursively call ll_add_to_tail until we get to the tail
					which is the point where the pointer is NULL */
      return ll_add_to_tail(&((*head)->next), val);
   }
}

int ll_print(llnode *p) {
   if (p==NULL) {
      return 0;
   } else {
      printf("val = %d\n",p->val);
      return ll_print(p->next);
   }
}

int ll_free(llnode *p) {
   if (p==NULL) {
      return -1;
   } else {
      llnode *f=p->next;
      free(p);
      return ll_free(f);
   }
}

/* searches list (pointed at by pList) for a node with value val
 * return success/failure based on search */
int ll_find_by_value(llnode *pList,int val) {
   if (pList == NULL) {
      return -1;
   }
   while(pList != NULL) {
      if ((pList->val) == val) {
         return 0;
      }
      else  {
         pList = pList->next;
      }
   }
   return -1;
}

/* finds tail node, if it exists, and removes it from list, adjusting the list
 * free any dynamic structures that are deleted */
int ll_del_from_tail(llnode **ppList) {
   if (ppList == NULL || *ppList == NULL) {
      return -1;
   }

   llnode *curr = *ppList;
   llnode *pre = NULL;
   while(curr->next != NULL) {
      pre = curr;
      curr = curr -> next;
   }

   pre->next = NULL;
   ll_free(curr);
   return 0;
}

/* find head node, if it exists, and removes it from list, adjusting the list
 * free any dynamic structures that are deleted */
int ll_del_from_head(llnode **ppList) {
   if (ppList == NULL || *ppList == NULL) {
      return -1;
   }

   llnode *oldHead = *ppList;
   *ppList = (*ppList)->next;
   free(oldHead);
   return 0;
}   

/* search for node with value val and if it exists, remove it */
int ll_del_by_value(llnode **ppList,int val) {
   if (ppList == NULL || *ppList == NULL) {
      return -1;
   }

   llnode *curr = *ppList;
   llnode *pre = NULL;
   while (curr != NULL) {
      if (curr->val == val) {
         break;
      }
      pre = curr;
      curr = curr->next;
   }

   pre->next = curr->next;
   free(curr);
   return 0;
}        

/* insert a new node into list, ensuring that it is inserted in order, as per
 * <this node has value <= next> <this node has value >= prior> */
int ll_insert_in_order(llnode **ppList,int val) {
   if (ppList == NULL || *ppList == NULL) {
      return -1;
   }

   llnode *curr = *ppList;
   /* case 1: val < head value */
   if (curr->val > val) {
      ll_add_to_head(ppList,val);
      return 0;
   }

   llnode *pre = NULL;
   /* case 2: val is some place in middle of list */
   while (curr != NULL) {
      if (curr->val > val) {
         llnode *newNode = (llnode *)malloc(sizeof(llnode));
         newNode->val = val;
         newNode->next = curr;
         pre->next = newNode;
         return 0;
      } else if (curr->val <= val) {
         pre = curr;
         curr = curr->next;
      }
   }

   /* case 3: val > tail value */
   ll_add_to_tail(ppList, val);
   return 0;

}

/* will merge SrcA and SrcB so that SrcA consists of SrcA and SrcB concatenated
 * in Python: string(SrcA = SrcA+SrcB) */
int ll_concat( llnode **pSrcA,llnode **pSrcB) {
   if (pSrcA == NULL || *pSrcA == NULL || pSrcB == NULL || *pSrcB == NULL) {
      return -1;
   }

   llnode *findEnd = *pSrcA;
   while (findEnd->next != NULL) {
      findEnd = findEnd->next;
   }
   findEnd->next = *pSrcB;

   return 0;
}

/* will run Bubble Sort on list pointed at by ppList */
int ll_sort(llnode **ppList) {
   if (ppList == NULL || *ppList == NULL) {
      return -1;
   }

   int swapped = -1;

   llnode *curr = (*ppList)->next;
   llnode *pre = *ppList;
   while (1) {
      swapped = -1;
      curr = (*ppList)->next;
      pre = *ppList;

      while (curr != NULL) {
         if ((pre->val) > (curr->val)) {
            /* swap the values */
            int tempVal = curr->val;
            curr->val = pre->val;
            pre->val = tempVal;
            swapped = 0;
         }

         pre = curr;
         curr = curr->next;
      }
      
      if (swapped == -1) {
         break; 
      }  
   }
   
   return 0;
}
