typedef struct chamada_t{
    
}chamada_s,*chamada_p;

typedef struct pagina_t{
    int data_do_ultimo_acesso;
    int alterado;
    int presenca;
    unsigned referencia;
    int *chave;
    //chamada_p info;
    //struct pagina_t *prox;
}pagina_s,*pagina_p;

typedef struct hash_t{
    int tamanho;
    //int aux;
    pagina_p virtual;
}hash_s,*hash_p;
