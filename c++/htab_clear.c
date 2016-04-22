/************************************************/
/*  Martin Vasko 1.BIT FIT VUTBR 1.BIB      	*/
/*  zadani cislo 2 IJC  25.4.2016           	*/
/*  last revision:20.4.2016                 	*/
/*  prekladac:gcc (GCC) 5.1.1 20150618      	*/
/*  more information: Clear all items in hash	*/
/*  if table has no items wont clear anythin	*/
/************************************************/

#include"htable.h"
#include<stdlib.h>

void htab_clear (htab_t *t)
{
	/* hash table is clear so no effect should be assigned to table */
	if(t==NULL)
		return;
	htab_listitem *item=NULL;
	/* freeing only if t is not null going for each item in table */
	for(unsigned i=0; i< t->htab_size; i++)
	{
		if(t->ptr[i]==NULL)
			continue; //ptr is not assigned go on next item
		/* loop for every item in list */
		while((item=t->ptr[i])!=NULL)
		{
			// calling previous method which find exact item
			htab_remove(t,item->key); /* there is "incerementation", item->next */
		}
	}
}
