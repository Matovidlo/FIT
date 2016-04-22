/********************************************/
/*  Martin Vasko 1.BIT FIT VUTBR 1.BIB      */
/*  zadani cislo 2 IJC  25.4.2016           */
/*  last revision:20.4.2016                 */
/*  prekladac:gcc (GCC) 5.1.1 20150618		*/
/*  more information: create a new listitem	*/
/*  if not exits when it is existing in hash*/
/*  it look for specific key in hash then 	*/
/*  return this item if key is not found	*/
/*	make item and return it also returns NULL*/
/*	if allocation of item failed			*/
/********************************************/

#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include"htable.h"
#include<string.h>

/* creating new item in list with key */
htab_listitem *htab_create(const char *key)
{
	htab_listitem* create_new=(htab_listitem*)malloc(sizeof(htab_listitem)+ sizeof(char)*(strlen(key)+1));
	if(create_new==NULL)
	{
		return NULL;
	}
	//initalize values
	memcpy(create_new->key,key,strlen(key)+1);
	create_new->data=0;
	create_new->next=NULL;

	return create_new;
}

	/*
	adding item to t->ptr[index] with specific key
	if key exists in t->ptr[index] t->ptr[index] is returned
	*/
htab_listitem *htab_lookup_add(htab_t *t,const char *key)
{
	unsigned index = t->hash_fun_ptr(key, t->htab_size);
	htab_listitem *item_ptr=NULL;
	htab_listitem *item=t->ptr[index];

	if(t->ptr[index] == NULL) //item not found
	{
		item=t->ptr[index]=htab_create(key); // creating new record of key item
		(t->n)++; //increments because new record appeared
		//if t->ptr or item is NULL is returned so no if statement needed
	}
	else
	{ ///Is item already in list
		for(item=t->ptr[index];item;) // finding
		{
			if(strcmp(item->key,key)==0) // found item, break
			{
				item_ptr=item; /* item_ptr stores founded item */
				break;
			}
			else
			{
				item_ptr=item; //not found
				item=item->next; //next iteration
			}
		}
	// item not found in loop so create again new item
		if (item_ptr != NULL && item != item_ptr)//create item if not existing
		{
			/* creating new item and increments records*/
			item=htab_create(key);
			(t->n)++;
			/* fail alocation */
			if(t->ptr[index] == NULL)
				return NULL;
			item_ptr->next=item;//link list
		}
	}
	return item; // return even alloc failed or returns item
}

