#include <stdio.h>
#include "./include/navigation.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include "./include/bateria.h"
#include "./include/list.h"
#include "./include/info.h"

int main() {
    Pilha bateria;
    inicializar(&bateria);
    tList lista = create_list();
    Posicao pos_final = {7, 6};

    int tempo_total = 0;
    int **map_data = get_map();
    int actual[2] = {0, 0};
    int next_pos[2] = {-1, -1};

    limpar_arquivo("C:\\Users\\Davi Barros\\Documents\\Gabriel\\Projetos_codigos\\projeto_LP_c\\data\\gold.txt");
    limpar_arquivo("C:\\Users\\Davi Barros\\Documents\\Gabriel\\Projetos_codigos\\projeto_LP_c\\data\\silver.txt");
    limpar_arquivo("C:\\Users\\Davi Barros\\Documents\\Gabriel\\Projetos_codigos\\projeto_LP_c\\data\\obstacles.txt");
    limpar_arquivo("C:\\Users\\Davi Barros\\Documents\\Gabriel\\Projetos_codigos\\projeto_LP_c\\data\\bronze.txt");
    limpar_arquivo("C:\\Users\\Davi Barros\\Documents\\Gabriel\\Projetos_codigos\\projeto_LP_c\\data\\charge_impossible.txt");
    limpar_arquivo("C:\\Users\\Davi Barros\\Documents\\Gabriel\\Projetos_codigos\\projeto_LP_c\\data\\charging.txt");
    print_map();

    while (actual[0] != pos_final.x || actual[1] != pos_final.y) {
        
        printf("Actual Coordinate: (%d,%d)\n", actual[0], actual[1]);
        obstacles(actual);
        list_way(&lista,actual);
        charge_impossible(actual);
        gold(actual);
        silver(actual);
        bronze(actual);
        
        get_next_pos(map_data, actual, next_pos);
            if (next_pos[0] != -1 && next_pos[1] != -1) { // Check for invalid position
                //printf("Next Coordinate: (%d,%d)\n", next_pos[0], next_pos[1]);
            }
        actual[0] = next_pos[0];
        actual[1] = next_pos[1];

        descarregar(&bateria);
        tempo_total = tempo_total + TRAVEL_TIME;
        if (bateria.Capacity <= LIMIT_RELOAD  * Capacity_Maximum && map_data[actual[0]][actual[1]] != IMPOSSIBILIDADE) {
            charging(actual);
            recarregar(&bateria);
            tempo_total = tempo_total + RECHARGE_TIME;
        }
    }
    char* status = (actual[0] == pos_final.x && actual[1] == pos_final.y) ? "success" : "failure";
    printf("total_time: %d\n", tempo_total);
    printf("status: %s\n", status);

    return 0;
} 