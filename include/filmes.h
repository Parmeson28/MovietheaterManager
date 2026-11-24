#ifndef FILMES_H
#define FILMES_H

#include <stdint.h>

typedef struct{
  uint8_t id;
  char * nome;
  uint8_t idade_min;
  uint8_t qnt_publico;
  uint8_t dia_semana; // 1 = domingo
} Filme;

void imprimir_filme(Filme * filme);
