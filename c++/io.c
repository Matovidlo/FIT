/****************************************************/
/*  Martin Vasko 1.BIT FIT VUTBR 1.BIB      		*/
/*  zadani cislo 2 IJC  25.4.2016           		*/
/*  last revision:16.4.2016                 		*/
/*  prekladac:gcc (GCC) 5.1.1 20150618      		*/
/*  more information: input of stream where			*/
/*  we getchar from file or stdin till its not EOF	*/
/*  chars are stored in *s with restriction of max	*/
/* 	number if overflow of s occurs error printed to	*/
/*	stderr and cuts the characters after max		*/
/*	return: fucntion returns integer from -1 to 127	*/
/****************************************************/

#include"io.h"

int get_word(char *s,int max, FILE* f)
{
	int i=0;
	int c;
	bool error=false;
	//set string s to zero
	memset(s,0,max);

	/* read by char to EOF */
	while((c=fgetc(f)) != EOF)
	{
		if(i >= max-1)
		{
			/* if maximum reached */
			if (!error)
				fprintf(stderr,"Overflow of line, cutting line!\n");
			error=true;
			while((c=fgetc(f)) != '\n' && c != EOF); //limit over
		}
		/* reading till isspace occurs */
		if (isspace(c))
		{
			return i;
		}
		/* adding char to s */
		s[i]=c;
		i++;
	}

	return c; // return EOF
}
