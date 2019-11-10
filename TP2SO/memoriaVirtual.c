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

//enquanto não chegar ao fim do arquivo
  //int endereco= ler o endereco
  //coverteEndereco()
  //int op=ler se é escita ou leitura (1-escrita 0-leitura)
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
  if(relatorio->)


}
