#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"funcoes.h"


iniciaSubstituicao(int endereco)
{
    relatorio->pesquisa++;

    if(relatorio->tecnicaReposicao==1){
        LRU(endereco);
    }
    if(relatorio->tecnicaReposicao==2){
        NRU(endereco);
    }

    if(relatorio->tecnicaReposicao==3){
        segundaChance(endereco);
    }
}

void executaArquivo()
{

 char  operacao,*aaaaarg; 
  unsigned addr,aux=0;
  unsigned page;
    

  // unsigned page_size = atoi(argv[3]) * 1024;
  //   unsigned s, tmp;
  //   tmp = page_size;
  //   s = 0;
    
  //   while( tmp > 1 ){
  //       tmp = tmp >> 1;
  //       s++;
  //   }
  //   printf("isso é s: %x \n", s);
  //   tamanho_da_pagina=((atoi(argv[4])*1024/atoi(argv[3])*1024));
  //   printf("Numero de paginas: %x\n",tamanho_da_pagina) ;
    


  FILE *arq= fopen(argv[2], "r");
  while(!feof(arq)){
    fscanf(arq,"%x %c", &addr, &operacao);
    // printf("%x %c \n",addr,operacao);
    // page = addr >> s;
    // printf("isso é page: %x \n", page);
    

    /*
    
    PASSAR ADDR PARA DECIMAL
    
    */


    relatorio->pesquisas++;

    if(operacao==R){
      relatorio->paginasEscritas++;
    }
    else if (operacao==W){
      relatorio->paginasLidas++;
    }

    int aux=pesquisaEndereco(addr);//Essa funçao pesquisa o endereco na memoria
    if(aux==0){//Quer dizer que o endereco precisa ser carregado na memoria
      iniciaSubstituicao(addr);
    }
    // if(relatorio->)

  
  
  
  
    aux++;
  }
  fclose(arq);
              //libera_tabela_hash(table);
//enquanto não chegar ao fim do arquivo
  //int endereco= ler o endereco
  //coverteEndereco()
  //int op=ler se é escita ou leitura (1-escrita 0-leitura)
  


}
