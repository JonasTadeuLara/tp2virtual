
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"string.h"

#include"funcoes.h"

int main(int argc,char *argv[]) {

    int tecRepo;
    
    
    if(atoi(argv[3])>=2 && atoi(argv[3])<=64 ){
        if(atoi(argv[4])>=128 && atoi(argv[4])<=16384){
            
            if(strcmp(argv[1],"lru")==0){
                tecRepo=1;
            }
            else if(strcmp(argv[1],"nru")==0) {
                tecRepo=2;
            }
            else if(strcmp(argv[1],"segunda_chance")==0) {
                tecRepo=3;
            }
            
            criaRelatorio(atoi(argv[3]),atoi(argv[4]), tecRepo,argv[2],argv[1]);
            criaMemoria();
            system("clear");
            printf("prompt> %s %s %d %d\n",relatorio->reposicao,relatorio->arquivoEntrada,relatorio->tamanhoPagina,relatorio->tamanhoMemoria);
            printf("executando...\n");
            executaArquivo(argv[2]);

            printf("pl=%d \npE=%d\npesq=%d\n",relatorio->paginasLidas,relatorio->paginasEscritas,relatorio->pesquisas);
            // for(int i=0;i<relatorio->tamanhoMemoria;i++) {
            //     if(memoriaFisica[i].id!=-1){printf("posicao=%d  && EI=%d && EF=%d\n",i,memoriaFisica[i].enderecoInicio,memoriaFisica[i].enderecoFinal);}
            // }
            
        
        }
        
    } 
   

}
