#include <stdio.h>
#include <stdlib.h>
#include "string.h"

typedef struct pagina_t{
    int data_do_ultimo_acesso;
    int alterado;
    int presenca;
    // unsigned referencia;
    // int *chave;
}pagina_s,*pagina_p;

typedef struct hash_t{
    int tamanho_da_tabela;
    int aux;
    pagina_p *virtual;
}hash_s,*hash_p;

hash_p cria_tabela_hash(int pag_mem_virtual);
void libera_tabela_hash(hash_p table_aux);
pagina_p cria_hash(int pag_mem_virtual);