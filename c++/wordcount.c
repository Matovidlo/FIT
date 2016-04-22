/************************************************/
/*  Martin Vasko 1.BIT FIT VUTBR 1.BIB      	*/
/*  zadani cislo 2 IJC  25.4.2016           	*/
/*  last revision:19.4.2016                 	*/
/*  prekladac:gcc (GCC) 5.1.1 20150618      	*/
/*  more information: Count of words in file	*/
/*  or standard input calling prepared func		*/
/*  of hash table init,lookup for adding,		*/
/*  foreach to printf hash with stored values	*/
/*	and at the end freeing whole table with its	*/
/*	contents.									*/
/************************************************/

#include"htable.h"
#include"io.h"

/*
	function which is called by htab_foreach(htab_t *t ,and type of funtion)
	returns on standard output keys and values of keys
*/
void print_key(const char *key, unsigned value)
{
	printf("%s\t%u\n",key,value);
}


int main()
{
	htab_listitem *item=NULL;
	htab_t *hash_table;

	//why 12289?
	/* 	funkcia by mala zabezpecit rovnomerne rozdelenie hash hodnoty v tabulke. nejednotna distribucia
        zvysuje pocet kolizii, a naklady na ich riesenie
		pouzivame prvocisla v rozmedzi s mocninou 2 -
		Na zaklade hladania bolo zistene ze velkost tabulky by malo byt prvocislo
 		http://planetmath.org/goodhashtableprimes
 	* 	Statistika: testovane na /usr/share/dict/words
 	* 12289:	Min = 0
					Max = 22 		*
					Avg = 8.07 		*
					ERR = 0.008138 	*
 	* 24593:	Min = 0
					Max = 13
					Avg = 4.03
					ERR = 0.069173
 	* 49157:	Min = 0
					Max = 11
					Avg = 2.02
					ERR = 0.010173
 	* Priemer sa znizuje nasobkom dvoch min zostava 0, max u 24593 bolo skoro 2x mensie ako u 12289,
	u 49157 to bolo len o 2menej. Tak som sa rozhodol pre 12289 s tym ze je nizsia chyba nez pri 24593 */

	hash_table=htab_init(12289);
	if(hash_table==NULL)
		return 1;

	int max = 128;
    char str[max];

	/* using io.c get_word function which returns value of reading in a file*/
	while(get_word(str,max-1,stdin)!=EOF)
	{
		/* adding item to hash_table */
		item=htab_lookup_add(hash_table,str);
		/* incrementing data to a specific key value */
		item->data++;
	}

	htab_foreach(hash_table, &print_key);
	/* control of n and size of table can be commented out to point how many ptr you have*/
	//printf("%u\t%u\n",hash_table->n,hash_table->htab_size);
	/* clearing table */
	htab_free(hash_table);
	return 0;
}

