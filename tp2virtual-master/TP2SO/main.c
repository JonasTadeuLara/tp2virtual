
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#include"funcoes.h"

int main()
{
  criaRelatorio();
  criaMemoria();
  executaArquivo();

    printf("pl=%d \npE=%d\npesq=%d\n",relatorio->paginasLidas,relatorio->paginasEscritas,relatorio->pesquisas);
  for(int i=0;i<relatorio->tamanhoMemoria;i++)
  {
    if(memoriaFisica[i].id!=-1){printf("posicao=%d  && EI=%d && EF=%d\n",i,memoriaFisica[i].enderecoInicio,memoriaFisica[i].enderecoFinal);}
  }
}
