#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"funcoes.h"


void criaMemoria()
{
  memoriaFisica=malloc(relatorio->tamanhoMemoria*sizeof(Pagina));//Aloca o tamanho da memoria fisica
  for(int i=0;i<relatorio->tamanhoMemoria;i++)
  {
    memoriaFisica[i].id=-1;//Esse -1 será usado para identificar que a pagina está vazia
  }
}

int pesquisaEndereco(int endereco)
{
    for(int i=0;i<relatorio->tamanhoMemoria && memoriaFisica[i].id!=-1;i++)
    {
        if(endereco>=memoriaFisica[i].enderecoInicio && endereco<=memoriaFisica[i].enderecoFinal)
        {
            return 1;//Quer dizer que o endereço já está na memória
        }
    }
    return 0;//Quer dizer que o endereço não está na memória
}

void NRU(int endereco)
{
  if (relatorio->pesquisas%clock==0)
  {//zera o clock
    for(int i=0;i<relatorio->tamanhoMemoria;i++)
    {
      if(memoriaFisica[i].classe>1)
      {//disferencia todas as paginas
      memoriaFisica[i].classe-=2;//Esse -1 será usado para identificar que a pagina está vazia
      }
    }
  }
    printf("34354235254235423");
  int j=0;
  while(memoriaFisica[j].id==1 && j<relatorio->tamanhoMemoria)
  {//pesquisa posição vazia
      j++;
  }
  if(j<relatorio->tamanhoMemoria)
  {
    calculaPagina(j,endereco);
    if(op==1)
    {
      memoriaFisica[j].classe=4;
    }else
    {
      memoriaFisica[j].classe=3;
    }
  }else
  {

    int i=0;
    int posicao=0;
    int class=5;
    while (class>0 &&i<relatorio->tamanhoMemoria)
    {
      if(class>memoriaFisica[i].classe)
      {
        class=memoriaFisica[i].classe;
        posicao=i;
      }
      i++;
    }
    calculaPagina(posicao,endereco);
    if(op==1)
    {
      memoriaFisica[posicao].classe=4;
    }else
    {
      memoriaFisica[posicao].classe=3;
    }
  }
}
void LRU(int endereco)
{
    int i=0;
    int j=0;
    if (relatorio->pesquisas%clock==0)
    {//zera o clock
        for(;i<relatorio->tamanhoMemoria;i++)
        {
          memoriaFisica[i].classe=0;//Esse -1 será usado para identificar que a pagina está vazia
        }
    }
    i=0;
    while(memoriaFisica[j].id==1 && j<relatorio->tamanhoMemoria)
    {//pesquisa posição vazia
        j++;
    }

    if(j<relatorio->tamanhoMemoria)
    {
        calculaPagina(j,endereco);
        memoriaFisica[j].classe=1;
    }
    else
    {
        while(memoriaFisica[i].classe==1)
        {
            i++;
        }

        calculaPagina(i,endereco);
        memoriaFisica[i].classe=1;
    }
}

void segundaChance(int endereco)
{
  int j=0;
  while(memoriaFisica[j].id==1 && j<relatorio->tamanhoMemoria)
  {//pesquisa posição vazia
      j++;
  }

  if(j<relatorio->tamanhoMemoria)
  {
      calculaPagina(j,endereco);
      memoriaFisica[j].classe=1;
  }
  else
  {
    int i=0;
    while(memoriaFisica[i].classe==1&& i<relatorio->tamanhoMemoria)
    {
      memoriaFisica[i].classe=0;
      i++;
    }
    if(i==relatorio->tamanhoMemoria)
    {
      calculaPagina(0,endereco);
      memoriaFisica[0].classe=1;
    }
    else
    {
      calculaPagina(i,endereco);
      memoriaFisica[i].classe=1;
    }
  }
}
