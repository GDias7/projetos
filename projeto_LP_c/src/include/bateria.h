#ifndef BATERIA_H
#define BATERIA_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

#define Capacity_Maximum 4
#define Capacity_Minimum 1
#define Capacity_Minimum2 2
#define RECHARGE_TIME 4
#define LIMIT_RELOAD  0.25
#define TRAVEL_TIME 2


typedef struct {
    int x;
    int y;
} Posicao;

typedef struct {
    Posicao pos;
    int distancia;
} Nodo;

typedef struct {
    Nodo* elements;
    int tamanho;
    int Capacity;
} Fila;

typedef struct {
    int Capacity ;
} Pilha;

void inicializar_fila(Fila* fila, int Capacity);
void enfileirar(Fila* fila, Nodo nodo);
Nodo desenfileirar(Fila* fila);
bool fila_vazia(Fila* fila);
void liberar_fila(Fila* fila);
void inicializar(Pilha *pilha);
void descarregar(Pilha *pilha);
void recarregar(Pilha *pilha);
void charging(int actual[2]);

//void charging(Pilha *pilha, int next_pos[2], int actual[2], int **map_data);

#endif
