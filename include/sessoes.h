#ifndef SESSOES_H
#define SESSOES_H

#define MAX_FILMES 50
#define TAM_TITULO 100
#define MAX_SESSOES 200
#define COLUNAS_SESSAO 4 

typedef struct {
    char titulos[MAX_FILMES][TAM_TITULO]; 
    int classificacao[MAX_FILMES];     
    int qtd;
} CatalogoFilmes;

typedef struct {
    int dados[MAX_SESSOES][COLUNAS_SESSAO];
    int qtd;
} AgendaSessoes;

#endif
