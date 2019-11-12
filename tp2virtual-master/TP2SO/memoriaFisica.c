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

}

void LRU(int endereco)
{
    int i=0;
    int j=0;
    if (relatorio->pesquisas%lru==0)
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
    /* code */
}
