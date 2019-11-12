#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#include"funcoes.h"

int iniciaSubstituicao(int endereco)
{
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
//enquanto não chegar ao fim do arquivo

  int endereco;  //int endereco= ler o endereco
  //coverteEndereco()
  int op=1;//int op=ler se é escita ou leitura (1-escrita 0-leitura)
  scanf("%d",&endereco);
  for(int endereco=-1;endereco<30;endereco=endereco+3){
  printf("endereço=%d\n",endereco);
  relatorio->pesquisas++;

  if(op==1)
  {
    relatorio->paginasEscritas++;
  }
  else if (op==0)
  {
    relatorio->paginasLidas++;
  }

  int aux=pesquisaEndereco(endereco);//Essa funçao pesquisa o endereco na memoria
  if(aux==0)
  {//Quer dizer que o endereco precisa ser carregado na memoria
        iniciaSubstituicao(endereco);

  }
}
iniciaSubstituicao(300);

  imprimeRelatorio();
}
