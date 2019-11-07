typedef struct Relatorio
{
char arquivoEntrada;
char tecnicaReposicao;//1-LRU 2-NRU 3- Segunda Chance
int tamanhoMemoria;
int tamanhoPaginas;
int paginasLidas;
int paginasEscritas;
}Relatorio;

void criaRelatorio();
//void imprimeRelatorio();


//--------------------------------------------------------------------------
typedef struct pagina
{
	int id;
	int enderecoInicio;
	int enderecoFinal;
	int classe;//Variável utilizada no metodo de substituição NRU( Leiam ele no slide) que varia de 0 a 3 ou então segundaChance()
}Pagina;

//void executaArquivo();
//void calculaPosicaoPagina();

//Variáveis globais
Relatorio *relatorio;
Pagina *memoriaFisica;
int lru=0;

/*OBS:

1-funções comentadas nesse arquivo ainda devem ser feitas



*/
