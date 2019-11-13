all:
	gcc main.c memoriaFisica.c memoriaVirtual.c pagina.c -o tp2virtual
	./tp2virtual lru simulador.log 4 128

