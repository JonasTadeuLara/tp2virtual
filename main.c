 #include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "hash.h"

int main(int argc,char *argv[]){
    
    char  operacao,*aaaaarg; 
    unsigned addr,aux=0;
    unsigned page;
    unsigned tamanho_da_pagina;
    
    //system("clear");
    printf("Executando o simulador...\n");
    printf("Arquivo de entrada: %s\n",argv[2]);
    printf("Tamanho da memoria: %s\n",argv[4]);
    printf("Tamanho de paginas: %s\n",argv[3]);
    printf("Tecnica de reposicao: %s\n",argv[1]);
    
    unsigned page_size = atoi(argv[3]) * 1024;
    unsigned s, tmp;
    tmp = page_size;
    s = 0;
    
    while( tmp > 1 ){
        tmp = tmp >> 1;
        s++;
    }
    printf("isso é s: %x \n", s);
    tamanho_da_pagina=((atoi(argv[4])*1024/atoi(argv[3])*1024));
    printf("Numero de paginas: %x\n",tamanho_da_pagina) ;
    
    
    printf("\n");
    FILE *arq= fopen(argv[2], "r");
    while(!feof(arq)){
        fscanf(arq,"%x %c", &addr, &operacao);
        printf("%x %c \n",addr,operacao);
        page = addr >> s;
        printf("isso é page: %x \n", page);
        aux++;
    }
    
    printf("linhas no arquivo: %x\n",aux);
    
    fclose(arq);
    //libera_tabela_hash(table);
    return 0;
}
