#include <stdio.h>
#include <stdlib.h>
#include "string.h"

int main(int argc,char *argv[]){
    
    char  operacao,*aaaaarg; 
    unsigned addr,aux=0;
    unsigned page;
    FILE *arq= fopen(argv[2], "r");
    system("clear");
    printf("Executando o simulador...\n");
    printf("Arquivo de entrada: %s\n",argv[2]);
    printf("Tamanho da memoria: %s\n",argv[4]);
    printf("Tamanho de paginas: %s\n",argv[3]);
    printf("Tecnica de reposicao: %s\n",argv[1]);
    while(!feof(arq)){
        fscanf(arq,"%x %c\n", &addr, &operacao);
        //printf("%x %c linha\n",addr,operacao);
        aux++;
    }
    printf("linhas no arquivo: %x\n",aux);
    printf("Numero de paginas: %x\n",(atoi(argv[4])/atoi(argv[3]))) ;
    fclose(arq);
    unsigned page_size = atoi(argv[3]) * 1024;
    unsigned s, tmp;
    tmp = page_size;
    s = 0;
    while( tmp > 1 ){
        tmp = tmp >> 1;
        s++;
    }
    page = addr >> s;

    printf("isso é s: %x \n", s);
    printf("isso é page: %x \n", page);
    
    
















    return 0;
}
