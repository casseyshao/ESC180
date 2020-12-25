// Lab 9

#include <stdio.h>
#include "ll.h"

int main(void) {
   llnode *root = NULL;
   int r=0;
   int i=0;

   printf("List A\n");
   r=ll_add_to_tail(&root,100);
   r=ll_add_to_tail(&root,200);
   r=ll_add_to_tail(&root,300);
   for(i=0;i<10;i=i+1){
      r=ll_add_to_tail(&root,i*100);
   }
   r=ll_print(root);

   /* testing added functions */

   /* testing ll_find_by_value */
   printf("Should be 0: %d\n", ll_find_by_value(root,300));
   printf("Should be -1: %d\n", ll_find_by_value(root,340));

   /* testing ll_del_from_tail */
   ll_del_from_tail(&root);

   /* testing ll_del_from_head */
   ll_del_from_head(&root);

   /* testing ll_del_by_value */
   ll_del_by_value(&root,500);

   /* testing ll_insert_in_order */
   ll_insert_in_order(&root,250);

   /* testing ll_concat */
   llnode *secondRoot = NULL;
   ll_add_to_tail(&secondRoot,180);
   ll_concat(&root,&secondRoot);

   printf("Updated list:\n");
   /* tail, head, and node with value 500 should be deleted */
   /* node with value 250 should be inserted in order */
   /* after concatenating the two lists, tail should have value 180 */
   ll_print(root);
   printf("Sorted list:\n");
   ll_sort(&root);
   ll_print(root);

   r=ll_free(root);

   printf("List B\n");
	root=NULL;
   r=ll_add_to_tail(&root,100);
   r=ll_add_to_tail(&root,200);
   r=ll_add_to_tail(&root,300);
   for(i=0;i<10;i=i+1){
      r=ll_add_to_head(&root,i*100);
   }
   r=ll_print(root);
   r=ll_free(root);
   return 0;
}
