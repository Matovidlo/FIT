/* HEADER 											*/
/* SOLVE IJC-DU1, priklad a) , 2.3.2016 			*/
/* Author : Martin Vaško, FIT VUTBR 1.BIT 			*/
/* Přeloženo : gcc 		*/
/* parametry prekladu: -O2 -std=c99 -Wall -pedantic */
/*	popis prikladu - poznamky */ /* */
/* */ // // // // // // // // //

#include <limits.h>
#include "error.h"

#ifndef BIT_ARRAY_H
#define BIT_ARRAY_H

typedef unsigned long bit_array_t [];
/* definition of our bit_array */

#define UNSG_BITS (CHAR_BIT*sizeof(unsigned long))
/* Count of bits in unsigned long  CHAR_BIT == 8*/

#define UNSG_ELEMENTS(size) ((size/(sizeof(unsigned long)))+(size % (sizeof(unsigned long))) > 0 ? 1 : 0)
/* number of elements */

#define ba_create(name_of_array, size) unsigned long name_of_array [UNSG_ELEMENTS(size) + 1] = {(unsigned long) size,0}
/* creating bit array of some size */


/* start of INLINE - size of bit array */
#ifdef USE_INLINE
		static inline unsigned long ba_size (bit_array_t name_of_array)
		{
			return name_of_array[0];
		}

	#else
	/* Macro size of bit array */
		#define ba_size(name_of_array) name_of_array [0]

#endif

/* inline SetBit */

#ifdef USE_INLINE
	 	inline void ba_set_bit (name_of_array , index, expression)
		{
			if (index > ba_size(name_of_array)-1 || index < 0)
				fatal_error("Index %lu mimo rozsah 0 - %lu", (unsigned long) index , ba_size(name_of_array)-1);
			if (expression)
				/* any expression other than 0 set bit to 1 */
				name_of_array[index / (sizeof(*name_of_array)*CHAR_BIT)+1] |= ((unsigned long)1 << (index % (sizeof(*name_of_array)*CHAR_BIT));
			else
				name_of_array[index / (sizeof(*name_of_array)*CHAR_BIT)+1] &= ~((unsigned long)1 << (index % (sizeof(*name_of_array)*CHAR_BIT));
				/* bit inversion after shifting 1 bit to left */
		}
#else
#define ba_set_bit (name_of_array, index, expression) \
		do \
		{ \
			if (expression) \
			{ \
				name_of_array[index / (sizeof(*name_of_array)*CHAR_BIT)+1] |= ((unsigned long)1 << (index % (sizeof(*name_of_array)*CHAR_BIT)); \
			} \
			else \
			{ \
				name_of_array[index / (sizeof(*name_of_array)*CHAR_BIT)+1] &= ~((unsigned long)1 << (index % (sizeof(*name_of_array)*CHAR_BIT)); \
			} \
		} \
		while (0) \
#endif

#define DU1_SET_BIT_(p,i,b) \
		if (b) \
			p [i / (sizeof(*p)*CHAR_BIT)] |= (1 << (i % (sizeof(*p)*CHAR_BIT))); \
		else \
			p [i / (sizeof(*p)*CHAR_BIT)] &= (1 << (i %(sizeof(*p)*CHAR_BIT))); \

#define DU1_GET_BIT (p,i) ( p[i/(sizeof(*p) * CHAR_BIT) ] & ( 1 << (i %(sizeof(*p)*CHAR_BIT)) ) > 0 );

#ifdef USE_INLINE
	static inline unsigned long ba_get_bit (name_of_array, index)
	{
		if (index > (ba_size(name_of_array)-1) || index < 0)
		{
			fatal_error("Index %lu mimo rozsah 0 - %lu",(unsigned long) index , ba_size(name_of_array)-1);
			return 1;
		}
		else
		{
			ba_get_bit(name_of_array, index) (unsigned long)((name_of_array[index / (sizeof(*name_of_array)*CHAR_BIT) + 1] & ((unsigned long) 1 << (index%(sizeof(*name_of_array)*CHAR_BIT))) ) > 0);
		}
	}

	#else
		#define ba_get_bit(name_of_array, index) \
			if (index > (ba_size(name_of_array)-1) || index < 0) \
				fatal_error ("Index %lu mimo rozsah 0 - %lu",(unsigned long) index , ba_size (name_of_array)-1); \
			else \
				(unsigned long)((name_of_array[index / (sizeof(*name_of_array)*CHAR_BIT) + 1] & ((unsigned long)1 << (index%(sizeof(*name_of_array)*CHAR_BIT))) ) > 0); \

#endif /* end of INLINE*/
#endif
#endif /* BIT_ARRAY define */
