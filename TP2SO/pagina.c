#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"funcoes.h"


void criaRelatorio()
{//cria a struct que deverá ser exibida no final da execução
  relatorio=malloc(sizeof(Relatorio));
  relatorio->paginasLidas=0;
  relatorio->paginasEscritas=0;
  relatorio->pesquisas=0;
}
void calculaPagina(int posicao, int endereco)
{
    memoriaFisica[posicao].enderecoInicio=endereco-endereco%relatorio->tamanhoMemoria;
    memoriaFisica[posicao].enderecoFinal=memoriaFisica[posicao].enderecoInicio+ relatorio->tamanhoMemoria;
}
void transformaBase(int inicial)
{
  int i,k,base_a,aux_i = 0,total_int;
  char aux_int[1]={},aux_frac[1] = {};
  float total_frac,aux = 0,resultado = 0;
  sinal = inicial.numero_c[0];
  //para evitar conflito de tipos,criei uma variavel auxiliar para receber o valor da base atual
  base_a = 16;
  printf("base a %d\n",base_a);
  //metodo tradicional de conversão para decimal numero*base_atual elevado ao expoente posicional
  for(k = 1 ;inicial.numero_c[i]!= '.';i++){
  aux_int[0] = inicial.numero_c[i];
  aux_i = atoi(&aux_int[0]);
  aux_i = aux_i * base_a;
  total_int = total_int + aux_i + k;
  k++;
}
