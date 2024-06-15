#include <stdio.h>
#include "./include/navigation.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include "./include/bateria.h" 

void inicializar_fila(Fila* fila, int Capacity) {
    fila->elements = (Nodo*)malloc(Capacity * sizeof(Nodo));
    fila->Capacity = Capacity;
    fila->tamanho = 0;
}

void enfileirar(Fila* fila, Nodo nodo) {
    if (fila->tamanho == fila->Capacity) {
        return;
    }
    fila->elements[fila->tamanho++] = nodo;
}

Nodo desenfileirar(Fila* fila) {
    Nodo nodo = fila->elements[0];
    for (int i = 0; i < fila->tamanho - 1; ++i) {
        fila->elements[i] = fila->elements[i + 1];
    }
    --fila->tamanho;
    return nodo;
}

bool fila_vazia(Fila* fila) {
    return fila->tamanho == 0;
}

void liberar_fila(Fila* fila) {
    free(fila->elements);
}

void inicializar(Pilha *pilha) {
    pilha->Capacity = Capacity_Maximum;
}

void descarregar(Pilha *pilha) {
    if (pilha->Capacity > Capacity_Minimum) {
        pilha->Capacity--;
    }
}

void recarregar(Pilha *pilha) {

    if (pilha->Capacity <= LIMIT_RELOAD  * Capacity_Maximum) {
        printf("Reloading...\n");
        for (int i = 0; i < RECHARGE_TIME; i++) {
            printf("Time Remaining: %d Seconds\n", RECHARGE_TIME - i);
            sleep(1);
        }
        pilha->Capacity = Capacity_Maximum;
        printf("Battery recharged!\n");
    }
}

void charging(int actual[2]) {
    // Ler o mapa do arquivo
    tMap map = read_map_from_file();

    // Obter a matriz de dados do mapa
    int **map_data = get_map();

    // Obter a posição atual
    int y = actual[1];
    int x = actual[0];
    int color = map.map_data[8 - y][x];

    // Abrir o arquivo para escrita
    FILE *file = fopen("C:\\Users\\Davi Barros\\Documents\\Gabriel\\Projetos_codigos\\projeto_LP_c\\data\\charging.txt", "a");
    if (file == NULL) {
        fprintf(stderr, "Error opening file for writing!\n");
        return;
    }

    // Escrever a cor no arquivo
    fprintf(file, "Reloading into position (%d, %d)\n", x, y);
    fclose(file);
}