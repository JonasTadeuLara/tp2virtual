
#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "hash.h"

hash_p cria_tabela_hash(int pag_mem_virtual){
    hash_p table_aux=( hash_p)malloc(sizeof( hash_s));
    if(table_aux!= NULL){
        table_aux->tamanho_da_tabela = pag_mem_virtual;
        table_aux->virtual = (struct pagina_t**)malloc(pag_mem_virtual*sizeof(struct pagina_s*));
        if(table_aux->virtual == NULL){
            free(table_aux);
            return NULL;
        }
        table_aux->aux=0;
        for(int i = 0; i < pag_mem_virtual ; i++){
        	table_aux->virtual[i] = NULL;
            table_aux->virtual[i]->alterado=1;
            printf("criei %d",table_aux->virtual[i]->alterado);
        }
    }
    
    return table_aux;
}
pagina_p cria_hash(int pag_mem_virtual){
    pagina_p table_aux=( pagina_p)malloc(sizeof( pagina_s));
    if(table_aux!= NULL){
        
        for(int i = 0; i < pag_mem_virtual ; i++){
        	table_aux->data_do_ultimo_acesso = 0;
            table_aux->alterado=0;
            table_aux->presenca=0;
        }
    }
    
    return table_aux;
}
void libera_tabela_hash(hash_p table_aux){
    if(table_aux!=NULL){
        
        for(int i=0;i<table_aux->tamanho_da_tabela;i++){
            if(table_aux->virtual[i] != NULL){
                free(table_aux->virtual[i]);
            }
        }
        free(table_aux->virtual);
        free(table_aux);
    }
    printf("TA REPREENDIDO\n");
}