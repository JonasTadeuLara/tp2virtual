all: 
	gcc main.c hash.c -o tp2virtual
	./tp2virtual lru arquivo.txt 4 128
 