############################
## 	Martin Vasko xvasko12 ###
# 	FIT VUTBR 1.BIT = 1.BIB ###
## 	IJC = 2.projekt hash,tail ###
##	Date of creation = 4.8.2016	#######
# 	Makefile usage = make , make all ##
##	make clean make zip		##########
#############################

CPP=g++
CC=gcc
CFLAG=-std=c99 -pedantic -Wall -Wextra #optimalizace -O0 -O2
CPPFLAG=-std=c++11 -pedantic -Wall
CDYNFLAG=-shared -fPIC -c
EXECUTABLE=tail tail2 wordcount wordcount_dynamic
OBJECTS=htable.h hash_function.c htab_init.c htab_lookup_add.c htab_foreach.c htab_remove.c htab_clear.c htab_free.c

all: $(EXECUTABLE)

tail: tail.c
	$(CC) $(CFLAG) tail.c -o tail

tail2: tail2.cc
	$(CPP) $(CPPFLAG) tail2.cc -o tail2

#####objective files and libraries static - dynamic so/a#########

libhtable.a: $(OBJECTS)
	$(CC) $(CFLAG) -c hash_function.c -o hash_function-static.o
	$(CC) $(CFLAG) -c htab_init.c -o htab_init-static.o
	$(CC) $(CFLAG) -c htab_lookup_add.c -o htab_lookup_add-static.o
	$(CC) $(CFLAG) -c htab_foreach.c -o htab_foreach-static.o
	$(CC) $(CFLAG) -c htab_remove.c -o htab_remove-static.o
	$(CC) $(CFLAG) -c htab_clear.c -o htab_clear-static.o
	$(CC) $(CFLAG) -c htab_free.c -o htab_free-static.o
	ar crvs libhtable.a hash_function-static.o htab_init-static.o htab_lookup_add-static.o htab_foreach-static.o htab_remove-static.o htab_clear-static.o htab_free-static.o
	ranlib libhtable.a

libhtable.so: $(OBJECTS)	#LD_LIBRARY_PATH="." on linux ; viz"man ld.so"
	$(CC) $(CFLAG) $(CDYNFLAG) hash_function.c -o hash_function-shared.o
	$(CC) $(CFLAG) $(CDYNFLAG) htab_init.c -o htab_init-shared.o
	$(CC) $(CFLAG) $(CDYNFLAG) htab_lookup_add.c -o htab_lookup_add-shared.o
	$(CC) $(CFLAG) $(CDYNFLAG) htab_foreach.c -o htab_foreach-shared.o
	$(CC) $(CFLAG) $(CDYNFLAG) htab_remove.c -o htab_remove-shared.o
	$(CC) $(CFLAG) $(CDYNFLAG) htab_clear.c -o htab_clear-shared.o
	$(CC) $(CFLAG) $(CDYNFLAG) htab_free.c -o htab_free-shared.o
	$(CC) $(CFLAG) -shared -o libhtable.so hash_function-shared.o htab_init-shared.o htab_lookup_add-shared.o htab_foreach-shared.o htab_remove-shared.o htab_clear-shared.o htab_free-shared.o

####not shared files

io.o: io.c
	$(CC) $(CFLAG) -c io.c
wordcount.o: wordcount.c
	$(CC) $(CFLAG) -c wordcount.c

##### wordcount with libraries #####
wordcount: io.o wordcount.o libhtable.a
	$(CC) $(CFLAG) -o $@ -static io.o wordcount.o libhtable.a

wordcount_dynamic: io.o wordcount.o libhtable.so
	$(CC) $(CFLAG) io.o wordcount.o -o $@ -L. -lhtable

clean:
	rm -f *.o wordcount wordcount_dynamic libhtable.so libhtable.a
	rm -f tail
	rm -f tail2
	rm -f xvasko12.zip
zip:
	zip xvasko12.zip *.c *.cc *.h Makefile
