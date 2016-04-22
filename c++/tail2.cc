/********************************************************/
/*  Martin Vasko 1.BIT FIT VUTBR 1.BIB      			*/
/*  zadani cislo 2 IJC  25.4.2016           			*/
/*  last revision:11.4.2016                 			*/
/*  more information: This is POSIX tail in C++			*/
/*  implemented with deque pushing to number of lines	*/
/*  poping deque if it is over limit 					*/
/*  works with stdin file and -n argument				*/
/********************************************************/

#include <unistd.h>
#include<iostream>
#include<deque>
#include<fstream>
#include<string>
#include<sstream>
using namespace std;

#define LENGTH_TAIL 10

void tail(int count,istream &open_file)
{
	deque<string> buffer;
	string line;

	while(getline(open_file,line))
	{
		buffer.push_front(line);
		if (count == 0) // over limit of lines
		{
			buffer.pop_back();
			count++;
		}
		count--;
	}
	while(!buffer.empty())
	{
		cout << buffer.back() << endl;
		buffer.pop_back();
	}
}

int main(int argc,char *argv[])
{
	fstream file_stream; // file stream
	bool in_file=false;
	istream *std_inp=&cin; //standard input
	string par_n;
	int lines_count=LENGTH_TAIL;
	bool error=false;

	if (argc == 1)
	{
		tail(LENGTH_TAIL,*std_inp);
	}
	else if (argc > 4)
	{
		cerr << "Too many arguments were given...\n";
		return 1;
	}
	else
	{
		if(argc == 2)
		{
			file_stream.open(argv[1],ios::in);
			in_file=true;
		}
		if (argc == 3 || argc == 4)
		{
			par_n=argv[1];
			if(par_n.compare("-n")==0)
			{
				par_n=argv[2];
				//declaration of number by parsed variable "par_n"
				istringstream sin (par_n,istringstream::in);
				sin >> lines_count; // number of lines that should be written
				lines_count=abs(lines_count);
				if (lines_count == 0)
					return 0; // no number to print ending
				if (argc == 4)
				{
					file_stream.open(argv[3],ios::in);
					if (!file_stream.is_open())
					{
						cerr << "Could not open the file\n" << endl;
						return 1;
					}
					tail(lines_count,file_stream);
					file_stream.close();
					return 0;
				}
			}
			else
				error=true;
		}
	}
	if(!file_stream.is_open() && in_file)
	{
		cerr << "Could not open the file\n";
		return 1;
	}
	if(error || lines_count == 0)
	{
		file_stream.close();
		cerr << "Error occurrs . Bad parameters were given!\n";
		return 1;
	}
	if (in_file)
		std_inp=&file_stream; // file were given instead of standard input

	tail(lines_count,*std_inp);
	file_stream.close();

	return 0;
}
