c=gcc
op=-Wall -Wextra

all : es.o liste.o constitution.c	
	$(c) $(op)  es.o liste.o constitution.c  -o constitution

liste.o : liste.c liste.h
	$(c) $(op) -c liste.c	

es.o : es.c es.h
	$(c) $(op) -c es.c	

clean :
	rm -f *.o
	rm -f constitution
