/********************************************************/
/*  Martin Vasko 1.BIT FIT VUTBR 1.BIB      			*/
/*  zadani cislo 2 IJC  25.4.2016           			*/
/*	prekladac:gcc (GCC) 5.1.1 20150618 (Red Hat 5.1.1-4)*/
/*  last revision:11.4.2016                 			*/
/*  more information: This is POSIX tail in C			*/
/*  void tail is implementation of tail      			*/
/*  FILE *op_file opens file and identify if    		*/
/*  the file was opened or not							*/
/********************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<error.h>
#include<string.h>
#include<stdbool.h>
#include<ctype.h>

#define MAX_LENGTH 510

void tail(int number_of_lines, FILE *open_file)
{
	int count=0,count_last=number_of_lines;
	bool error,over=false;
	char string_read[MAX_LENGTH]; // reading strings
	char pom[MAX_LENGTH]; //tmp for swap
	char lines[number_of_lines+1][MAX_LENGTH]; // array of strings
	int c;

	while ((fgets(string_read,MAX_LENGTH,open_file))!= NULL)
    {
		if(strchr(string_read,'\n')==NULL)
		{
			if (!error) //putting only once Overflow
				fprintf(stderr,"Line(s) too long, truncating...\n");
			error=true;
			string_read[MAX_LENGTH-2]='\n';
			while((c=getc(open_file)) != '\n' && c!= EOF);
		}
		memset(lines[count],0,strlen(lines[count])); //clear array of strings
		strcat(lines[count],string_read);	//concatenate readed char
		if(string_read[strlen(string_read)-1]=='\n') //if end line
        {
			count++;
			if (count > number_of_lines) // already passed over limit
			{
				count=count_last; //concatenate only on last position of array
				over=true;
			}
			if (over==true) //first string is filled
			{
				for(int i=0; i < number_of_lines; i++)
				{
					strcpy(pom,lines[i+1]); // swap strings from 0 - 10 to 0 -9
					strcpy(lines[i],pom); // swap contents of i+1 to i field
					memset(pom,0,strlen(pom)); // clear pom variable for next swap
				}
			}
		}
	}
	//printing queue
	if (over == true)
		for (int i = 0; i < number_of_lines; i++)
			printf("%s",lines[i]); // print if more than number of lines
	else
		for (int i = 0; i < count; i++)
            printf("%s",lines[i]); // printf if less than number of lines
}

FILE *op_file(char *filename)
{
	FILE *f;
	if ((f=fopen(filename,"r")) == NULL)
	{
		f=stdin;
		return f;
	}
	return f;
}

int main(int argc,char *argv[])
{
FILE *open_file;
int num;
int i=0;
bool err=false;
	if (argc == 1)
	{
		tail(10,stdin);
	}
	else if (argc > 4)
		fprintf(stderr,"Too many arguments!\n");
	else if ((open_file=fopen(argv[1],"r")) == NULL)
	{
		if (strncmp(argv[1],"-n",2)==0)
		{
			if (argc == 3 || argc == 4)
			{
				while(argv[2][i] != 0)
				{
					if (argv[2][0] == '-')
					{
						i++;
						continue; // negative number
					}
					if (!isdigit(argv[2][i]))
						err=true;
					i++;
				}
				if (!err)
				{
					num=strtol(argv[2],NULL,10);
					num=abs(num); // POSIX -n option
				}
				else ///implicit num if first number is char
				{
					fprintf(stderr,"Bad number of lines...\n");
					return 1;
				}
			}
			else
			{
				fprintf(stderr,"Option -n found but no number after...\n");
				return 1;
			}
			/// argument -n number passed
			if((open_file=op_file(argv[3]))==NULL)
			{
				tail(num,open_file);
				fclose(open_file);
			}
			else
			{
				tail(num,open_file);
				fclose(open_file);
			}
		}
		else
		{
			fprintf(stderr,"Bad argument option or no Input file given...\n");
           	return 1;
		}
	}
	else /// arguments where first is file
	{
		num=10; //default value
		if(argc == 3 || argc == 4)
		{
			if (strncmp(argv[2],"-n",2)==0)
        	{
				if (argc == 4)
				{
					while(argv[3][i] != 0)
					{
						if(argv[3][0] =='-')
							continue;
						if(!isdigit (argv[3][i]))
							err=true;
						i++;
					}
                	if (!err)
                    {
						num=strtol(argv[3],NULL,10);
               			num=abs(num);//POSIX -n option
					}
					else ///implicit num if first number is char
                    {
						fprintf(stderr,"Bad number of lines...\n");
						return 1;
					}
				}
				else
				{
					fprintf(stderr,"Option -n found but no number after ...\n");
					return 1;
				}
			}
			else
			{
				fprintf(stderr,"Bad argument option...\n");
				return 1;
			}
		}
		tail(num,open_file);
		fclose(open_file);
	}	//tail 1 argv
	return 0;
}
