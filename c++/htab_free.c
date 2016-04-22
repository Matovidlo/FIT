/********************************************/
/*  Martin Vasko 1.BIT FIT VUTBR 1.BIB      */
/*  zadani cislo 2 IJC  25.4.2016           */
/*  last revision:20.4.2016                 */
/*  prekladac:gcc (GCC) 5.1.1 20150618      */
/*  more information: free hash table if	*/
/*	it is not NULL							*/
/********************************************/

#include"htable.h"
#include<stdlib.h>


void htab_free(htab_t *t)
{
	/* freeing only if t is not null */
	if(t!=NULL)
	{
		/* calling a functiontion which provide clearing all item's in all ptr's*/
		htab_clear(t);
		free(t);
	}
}
