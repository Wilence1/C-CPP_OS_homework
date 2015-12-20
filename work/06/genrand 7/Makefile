СС=gcc
CFLAGS=-O2 -Wall -Werror -Wno-pointer-sign -std=gnu11

all: main.o rand.o
	$(CC)  $(CFLAGS) main.o rand.o -o genrand

rand.o: rand.c rand.h 
	$(CC) $(CFLAGS) -c rand.c

main.o:  main.c
	$(CC) $(CFLAGS) -c main.c
  
clean:
	rm  -f genrand 
	rm  -f *.bak 
	rm  -f *~
	rm  -f *.o
