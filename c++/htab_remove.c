/********************************************/
/*  Martin Vasko 1.BIT FIT VUTBR 1.BIB      */
/*  zadani cislo 2 IJC  25.4.2016           */
/*  last revision:20.4.2016                 */
/*  prekladac:gcc (GCC) 5.1.1 20150618      */
/*  more information: removes 1 exact key	*/
/*  from hash structure if not existing		*/
/*  nothing is removed fucntion returns void*/
/********************************************/

#include<stdlib.h>
#include<string.h>
#include"htable.h"

void htab_remove(htab_t *t,char *key)
{
	unsigned index = t->hash_fun_ptr(key,t->htab_size);
	/* tmp item to store ->next value */
	htab_listitem *item_ptr= t->ptr[index];
	/* item for iterating in list of listitems */
	htab_listitem *item=NULL;
	///finding key in htab_t
	for(item=t->ptr[index]; item ;)
	{
		/* key found */
		if(strcmp(item->key,key)==0)
		{
			if(item_ptr == item) // tmp is same as item
				t->ptr[index]=item->next; //go to next item
			/* else tmp->next store from item */
			item_ptr->next=item->next;
			free(item); //now we can clear this item
			break;
		}
		else // key not found iterate
		{
			item_ptr=item; //store tmp of item for next iteration
			/* going to next item */
			item=item->next;
		}
	}
}
