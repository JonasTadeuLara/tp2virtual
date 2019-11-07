#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"funcoes.h"


void cria_memoria()
{
  memoriaFisica=malloc(relatorio->tamanhoMemoria*sizeof(pagina));//Aloca o tamanho da memoria fisica
  for(int i=0;i<relatorio->tamanhoMemoria;i++)
  {
    memoriaFisica[i].id=-1;//Esse -1 será usado para identificar que a pagina está vazia
  }
}























int insere_cache_conjuntos(Bloco *bloco)
{
    int posicao=bloco->tag%(tamanhocache/viascache);//calcula a posicão da cache em que o bloco será inserido
    int acesso=cache[posicao*viascache].bloco->acesso;;//Pega o valor da variavel acesso da linha da cache que começa o conjunto calculado acima
    int acessomax=acesso;
    int substituto=0;//guarda a posição dentro do conjunto que devera ser substituida
    for(int i=1;i<viascache;i++)
    {
        if(cache[posicao*viascache+i].bloco!=NULL)
        {
            if(acesso>cache[posicao*viascache+i].bloco->acesso)
            {//Quer dizer que o bloco da esquerda tem menos acessos que o da direita ou o acesso foi feito a um maior espaço de tempo
                acesso=cache[posicao*viascache+i].bloco->acesso;
                substituto=posicao*viascache+i;
            }
            if(acesso<cache[posicao*viascache+i].bloco->acesso)
            {//Quer dizer que o bloco da esquerda tem menos acessos que o da direita ou o acesso foi feito a um maior espaço de tempo
                acessomax=cache[posicao*viascache+i].bloco->acesso;
            }
        }
        else
        {//Quer dizer que uma posição do conjunto esta vazia
            cache[posicao*viascache+i].bloco=bloco;
            return posicao*viascache+i;
        }
    }
    if(cache[substituto].bloco->bitsujo==0)
    {//O bloco nunca foi alterado
        cache[substituto].bloco=bloco;
    }

    if(cache[substituto].bloco->bitsujo==1)
    {//O bloco foi alterado
        escreve_ram(cache[substituto].bloco);
        cache[substituto].bloco=bloco;
    }
    if(substituicao==1)
    {//LRU
        cache[substituto].bloco->acesso==acessomax++;
    }

    return substituto;
}
void insere_cache_totalassociativa(Bloco *bloco)
{
    int substituto=0;
    if(cache[tamanhocache-1].bloco==NULL)
    {//quer dizer que nem toda a cache está completa.
        int i=0;
        while(cache[i].bloco!=NULL)
        {//enquanto não achar uma posição vazia na cache
            i++;
        }
        cache[i].bloco=bloco;
        substituto=i;
    }
    else
    {//Quer dizer que toda a cache está cheia
        int acesso=cache[0].bloco->acesso;
        int acessomax=cache[0].bloco->acesso;
        for(int i=1;i<tamanhocache;i++)
        {
            if(acesso>cache[i].bloco->acesso)
            {
                acesso=cache[i].bloco->acesso;
                substituto=i;
            }
            if(acesso<cache[i].bloco->acesso)
            {
                acessomax=acesso<cache[i].bloco->acesso;
            }
        }
        if(cache[substituto].bloco->bitsujo==0)
        {//O bloco nunca foi alterado
            cache[substituto].bloco=bloco;
        }

        else if(cache[substituto].bloco->bitsujo==1)
        {//O bloco foi alterado
            escreve_ram(cache[substituto].bloco);
            cache[substituto].bloco=bloco;
        }

        if(substituicao==1)
        {//LRU
            cache[substituto].bloco->acesso==acessomax++;
        }
    }
}
void insere_cache_diretamentemapeada(Bloco *bloco)
{//Insere o bloco na cache diretamente mapeada
    int posicao=bloco->tag%tamanhocache;//calcula a posicão da cache em que o bloco será inserido
    if(cache[posicao].bitvalidade==0)
    {//Quer dizer que aquela posição da cache está vazia
    cache[posicao].bloco=bloco;//Insere o bloco na cache.
    cache[posicao].bitvalidade=1;
    }
    if(cache[posicao].bitvalidade==1)
    {//Quer dizer que aquela posição da cache já contem um bloco
        if(cache[posicao].bloco->bitsujo==0)
        {//Apesar já existir um bloco, ele ainda não foi alterado
            cache[posicao].bloco=bloco;//Subescreve o bloco novo sobre o antigo.
            cache[posicao].bitvalidade=1;
        }
        if(cache[posicao].bloco->bitsujo==1)
        {//Já existe um bloco e ele foi alterado
            escreve_ram(cache[posicao].bloco);
            cache[posicao].bloco=bloco;
        }
    }
}
void insere_cache(Bloco *bloco)
{//Decide qual das tres funções de inserir acima serão chamadas
    if(tipocache==1)
    {
        insere_cache_diretamentemapeada(bloco);
    }
    if(tipocache==2)
    {
        insere_cache_conjuntos(bloco);
    }
    if(tipocache==3)
    {
        insere_cache_totalassociativa(bloco);
    }

}
int busca_conteudo_cache(float valor,int altera)
{//Busca o valor digitado na ram

    for(int i=0;i<tamanhocache;i++)
    {//Esses comandos de repetição abaixo procuram o valor na cache
        for(int j=0;j<tamanhobloco;j++)
        {
            if(cache[i].bloco!=NULL)
            {
                if(cache[i].bloco->palavras[j].numero==valor)
                {//Quer dizer que foi achado o valor buscado
                    cacheHit++;
                    if(substituicao==2)
                    {//Ou é LRU ou LFU
                        cache[i].bloco->acesso++;//Incrementa a variáve'l acesso
                    }
                    else if(substituicao==1)
                    {
                        if(tipocache==2)
                        {
                            int inicio=(cache[i].bloco->tag%tamanhocache)*viascache;//Acho a linha da cache em que começa o conjunto que possui o bloco com o numero procurado
                            int acessomax=cache[(cache[i].bloco->tag%tamanhocache)*viascache].bloco->acesso;
                            int fim=((cache[i].bloco->tag%tamanhocache)*viascache)+viascache-1;//Indica a posição final da cache
                            for(inicio+1;inicio<=fim;inicio++)
                            {
                                if(cache[inicio].bloco->acesso>acessomax)
                                {
                                    acessomax==cache[inicio].bloco->acesso;
                                }
                            }
                            cache[i].bloco->acesso=acessomax++;
                        }
                        else if(tipocache==3)
                        {
                            int acessomax=cache[0].bloco->acesso;
                            for(int b=1;b<tamanhocache;b++)
                            {
                                if(acessomax<cache[b].bloco->acesso)
                                {
                                    acessomax=cache[b].bloco->acesso;
                                }
                            }
                            cache[i].bloco->acesso=acessomax++;
                        }

                    }
                    if(tipocache==2)
                    {//Print para a cache associativa por conjunto que informa o conjunto em que o bloco se encontra
                        printf("Valor procurado: %f \nBloco: %d Conjunto da Cache: %d\nPosição do bloco no conjunto: %d",valor,cache[i].bloco->tag,i%tamanhocache,i%viascache);
                    }
                    else
                    {
                        printf("Valor procurado: %f \nBloco %d Posição da cache %d\n",valor,cache[i].bloco->tag,i);

                    }
                    if(altera==1)
                    {
                        int posiBloco=j;//J é o slot em que a palavra se encontra
                        int posiCache=i;//i é a posição em que o bloco está na cache
                        altera_conteudo(posiCache,posiBloco,cache[i].bloco->tag);
                    }
                    return 1;//Quer dizer que o número foi achado
                }
            }
        }
    }
    return 0;//Caso o numero não tenha sido achado na cache
}
void imprime_cache()
{//Imprime a cache
    if(tipocache==2)
    {//Esse print é para cache associativa por conjunto, ee irá informar o o conjunto que o bloco faz parte
        int conjuntos=-1,posiconjunto=0;
        for(int i=0;i<tamanhocache;i++)
        {
            posiconjunto++;
            if(i%viascache==0)
            {//Chegamos no inicio de um novo conjunto
                conjuntos++;
                posiconjunto=0;
            }
            if(cache[i].bloco!=NULL)
            {
                printf("\nConjunto: %d posição no conjunto:%d  Tag do bloco:%d \n",conjuntos,posiconjunto,cache[i].bloco->tag);
                for(int j=0;j<tamanhobloco;j++)
                {//Printa todas as palavras do bloco
                    printf("\tPalavra[%d]= %f\n",j,cache[i].bloco->palavras[j].numero);
                }
            }
            else
            {
                printf("\nConjunto: %d posição no conjunto:%d  Está vazia \n",conjuntos,posiconjunto);
            }
        }
    }
    else
    {//Para os outros dois tipos
        for(int i=0;i<tamanhocache;i++)
        {
            if(cache[i].bloco!=NULL)
            {
                printf("\nTag do bloco:%d    Linha da cache:%d\n",cache[i].bloco->tag,i);
                for(int j=0;j<tamanhobloco;j++)
                {//Printa todas as palavras do bloco
                    printf("\tPalavra[%d]= %f\n",j,cache[i].bloco->palavras[j].numero);
                }
            }
            else
            {
                printf("\nLinha da cache:%d Está vazia\n ",i);
            }
        }
    }
    printf("\n");
}
