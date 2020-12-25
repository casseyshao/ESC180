// lab 9

struct llnode {
   int val;   
   struct llnode *next;
};
typedef struct llnode llnode;

/*Given Function*/
int ll_add_to_head(llnode **head, int val);
int ll_add_to_tail(llnode **head, int val);
int ll_print(llnode *p);
int ll_free(llnode *p);

/*Added Functions*/
int ll_find_by_value(llnode *pList,int val);
int ll_del_from_tail(llnode **ppList);
int ll_del_from_head(llnode **ppList);
int ll_del_by_value(llnode **ppList,int val);
int ll_insert_in_order(llnode **ppList,int val);
int ll_concat(llnode **pSrcA,llnode **pSrcB);
int ll_sort(llnode **ppList);
