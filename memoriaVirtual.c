#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#include"funcoes.h"

int iniciaSubstituicao(int endereco) {
    if(relatorio->tecnicaReposicao==1) {
        LRU(endereco);
    }
    if(relatorio->tecnicaReposicao==2) {
        NRU(endereco);
    }
    if(relatorio->tecnicaReposicao==3) {
        segundaChance(endereco);
    }
}

void executaArquivo() {
    //enquanto não chegar ao fim do arquivo
    char  operacao; 
    unsigned addr;

    int endereco;  //int endereco= ler o endereco
    int linhas=0;
    FILE *arq= fopen(relatorio->arquivoEntrada, "r");
    while(!feof(arq)){
        fscanf(arq,"%x %c\n", &addr, &operacao);
        
        relatorio->pesquisas++;
        if(operacao == 'R') {
            op=0;
            relatorio->paginasEscritas++;
        }
        else if (operacao == 'W') {
            op=1;
            relatorio->paginasLidas++;
        }
        endereco=addr;
        
        int aux=pesquisaEndereco(endereco);//Essa funçao pesquisa o endereco na memoria
        if(aux==0) {//Quer dizer que o endereco precisa ser carregado na memoria
                iniciaSubstituicao(endereco);

        }
        linhas++;
    }
    fclose(arq);
    imprimeRelatorio();
   
}

 
