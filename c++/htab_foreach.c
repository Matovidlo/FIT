/************************************************/
/*  Martin Vasko 1.BIT FIT VUTBR 1.BIB      	*/
/*  zadani cislo 2 IJC  25.4.2016           	*/
/*  last revision:20.4.2016                 	*/
/*  prekladac:gcc (GCC) 5.1.1 20150618      	*/
/*  more information: For all items in hash		*/
/*  uses function which takes 2 arguemnts		*/
/*  a key and a value this function returns		*/
/*  void. Can be used for example to print hash	*/
/************************************************/

#include<stdio.h>
#include"htable.h"

/* hash table and fucntion is a parameter of this function*/
void htab_foreach(htab_t *t, void (*func)(const char *key,unsigned value))
{
	htab_listitem *item=NULL;
	unsigned id=0;
	/* while identification is less than size of table*/
	while(id < t->htab_size)
	{
		item=t->ptr[id];
		/* while items in ptr are not NULL execute a fucntion with item contents */
		while(item != NULL)
		{
			func(item->key,item->data);
			item=item->next; // next item in ptr
		}
		id++; //next ptr index
	}

}
