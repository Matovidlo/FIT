/********************************************************/
/*	Martin Vasko 1.BIT FIT VUTBR 1.BIB					*/
/*	zadani cislo 2 IJC 	25.4.2016						*/
/*	last revision:19.4.2016								*/
/*  prekladac:gcc (GCC) 5.1.1 20150618 (Red Hat 5.1.1-4)*/
/*	more information: This is hash table				*/
/*	interface structure of list which					*/
/*	contains key and values and 						*/
/*	functions which work with hash table				*/
/********************************************************/
#ifndef HASH
#define HASH

#include "hash_function.h"

typedef struct htab_listitem htab_listitem;

struct htab_listitem{
/* number of occurences of exact key in ptr/hashtable */
unsigned data;
htab_listitem *next; /* pointer to next item in list */
char key[];/* key which is hashed */
};
/* struct of hash table */
typedef struct htab_t htab_t;

struct htab_t{
unsigned htab_size; /* size of ptr in table*/
unsigned int (*hash_fun_ptr)(const char *,unsigned); /* hash function stored */
unsigned n; /*count of items in ptr*/
htab_listitem *ptr[]; /* flexible array member of ptr's */
};

 /* initialization of table with implicit hash function above */
htab_t *htab_init(unsigned size);
/* initializing table with hashfunction as second argument */
htab_t *htab_init2(unsigned size, unsigned int (*hashfn)(const char *key,unsigned value));

htab_listitem *htab_lookup_add(htab_t *t,const char *key); // dobre premysliet chovani teto funkce k parametru key
/* vracejici ukazatel nebo NULL pri chybe*/
void htab_foreach(htab_t *t, void (*func)(const char *key,unsigned value));
/* removing 1 key from t */
void htab_remove (htab_t *t, char *key);
/* clearing table from ptr's using loop with remove function */
void htab_clear (htab_t *t);
/* free table using clear function */
void htab_free (htab_t *t);

#endif
