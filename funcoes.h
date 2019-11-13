#ifndef FUNCOES
#define FUNCOES

typedef struct Relatorio {
    char *arquivoEntrada;
    char *reposicao;
    int tecnicaReposicao;//1-LRU 2-NRU 3- Segunda Chance
    int tamanhoMemoria;
    int tamanhoPagina;
    int paginasLidas;
    int paginasEscritas;
    int pesquisas;
}Relatorio;

typedef struct pagina
{
	int id;//-1-vazio 1-pra não vazia
	int enderecoInicio;
	int enderecoFinal;
	int classe;//Variável utilizada no metodo de substituição NRU( Leiam ele no slide) que varia de 0 a 3 ou então segundaChance()
}Pagina;

//Memoriafisica.c
void criaMemoria();
int pesquisaEndereco(int);
void NRU(int );
void LRU(int );
void segundaChance(int );
//--------------------------------------------------------------------------
//Pagina.c

void criaRelatorio(int tamPage,int tamMem,int tecRepo,char *arquivo,char *reposicao);
void calculaPagina(int,int);
void transformaBase(int);
void imprimeRelatorio();
//void executaArquivo();
//void calculaPosicaoPagina();
//-------------------------------------------------------------------------
////Memoriavirtual.c
void executaArquivo();
int iniciaSubstituicao(int);


//-----------------------------------------------------------------------
//Variáveis globais
Relatorio *relatorio;
Pagina *memoriaFisica;
#define clock 10
int op;//1-para escrita,0-para leitura

#endif
