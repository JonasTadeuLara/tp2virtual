#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#include"funcoes.h"

void criaRelatorio(int tamPage,int tamMem,int tecRepo,char *arquivo, char *tecReposicao) {//cria a struct que deverá ser exibida no final da execução
    relatorio=malloc(sizeof(Relatorio));
    relatorio->paginasLidas=0;
    relatorio->paginasEscritas=0;
    relatorio->pesquisas=0;
    relatorio->tecnicaReposicao=tecRepo;
    relatorio->tamanhoMemoria=tamMem;
    relatorio->tamanhoPagina=tamPage;
    relatorio->arquivoEntrada=arquivo;
    relatorio->reposicao=tecReposicao;
}
void calculaPagina(int posicao, int endereco) {
    memoriaFisica[posicao].enderecoInicio=endereco-(endereco%relatorio->tamanhoPagina);
    memoriaFisica[posicao].enderecoFinal=memoriaFisica[posicao].enderecoInicio+relatorio->tamanhoPagina-1;
    memoriaFisica[posicao].id=1;
}

void imprimeRelatorio() {
    printf("Nome do arquivo de entrada= %s\n",relatorio->arquivoEntrada);
    printf("tecnicaReposicao= %s\n",relatorio->reposicao);
    printf("tamanho da memória= %d espaços\n",relatorio->tamanhoMemoria);
    printf("tamanho da pagina %d\n",relatorio->tamanhoPagina);
    printf("Paginas Lidas= %d\n",relatorio->paginasLidas);
    printf("Paginas Escritas= %d\n",relatorio->paginasEscritas);
    printf("Pesquisas=%d\n",relatorio->pesquisas);
}

