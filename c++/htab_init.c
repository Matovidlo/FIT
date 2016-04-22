/********************************************************/
/*  Martin Vasko 1.BIT FIT VUTBR 1.BIB      			*/
/*  zadani cislo 2 IJC  25.4.2016           			*/
/*  last revision:19.4.2016                 			*/
/*  prekladac:gcc (GCC) 5.1.1 20150618 (Red Hat 5.1.1-4)*/
/*  more information: This module initalize 			*/
/*  hash table with size of ptr's if alloc				*/
/*  failed null returned else size stored				*/
/*  in a table with hash_fun_ptr and n set to 0			*/
/********************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include"htable.h"

	/*
	initalize table with size of ptrs
	null them at start
	*/
htab_t *htab_init(unsigned size)
{
	htab_t* table=(htab_t*)malloc(sizeof(htab_t)+size*sizeof(htab_listitem));

	if(table == NULL)
	{
		fprintf(stderr,"Allocation failed...!\n");
		return NULL;
	}
	table->htab_size=size;
	for (unsigned i = 0 ;i < size; i++)
	{
		table->ptr[i]=NULL;
	}
	table->n=0;
	table->hash_fun_ptr=&hash_function;
	return table;
}

	/*
	same behaviour but hashfn is not implicit as
	above but explicit can choose different hashing function
	*/
htab_t *htab_init2(unsigned size, unsigned int (*hashfn)(const char *key,unsigned value))
{
    htab_t* table=(htab_t*)malloc(sizeof(htab_t)+size*sizeof(htab_listitem));

    if(table == NULL)
    {
        fprintf(stderr,"Allocation failed...!\n");
		return NULL;
    }
    table->htab_size=size;
    for (unsigned i = 0 ;i < size; i++)
    {
        table->ptr[i]=NULL;
    }
    table->n=0;
    table->hash_fun_ptr=hashfn;
    return table;
}

