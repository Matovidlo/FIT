/********************************************/
/*  Martin Vasko 1.BIT FIT VUTBR 1.BIB      */
/*  zadani cislo 2 IJC  25.4.2016           */
/*  last revision:19.4.2016                 */
/*  more information: This is implicit hash */
/*  function which calculate index of key in*/
/*  hash table to index ptr's				*/
/********************************************/

#include"hash_function.h"

unsigned int hash_function(const char *str, unsigned htab_size)
{
    unsigned int h=0;
    const unsigned char *p;
    for(p=(const unsigned char*)str; *p!='\0'; p++)
       	h = 65599*h + *p;
    return h % htab_size;
}

