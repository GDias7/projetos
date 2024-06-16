#include "./include/navigation.h"
#include <stdio.h>
#include <stdlib.h>
#include "./include/list.h"
#include "./include/info.h"

void limpar_arquivo(const char *filepath) {
    FILE *file = fopen(filepath, "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }
    // No need to write anything; opening in "w" mode clears the file
    fclose(file);
    printf("File %s cleared.\n", filepath);
}

void charge_impossible(int actual[2]) {
    // Ler o mapa do arquivo
    tMap map = read_map_from_file();

    // Obter a matriz de dados do mapa
    int **map_data = get_map();

    // Obter a posição atual
    int y = actual[1];
    int x = actual[0];

    // Checando as coordenadas impossiveis para ocorrer a recarga das baterias
    if (map.map_data[8 - y + 1][x] == 1) {

        printf("Impossible to charge the battery in the position (%d, %d)\n", x, y);

        // Abrir o arquivo para escrita
        FILE *file = fopen("C:\\Users\\Davi Barros\\Documents\\Gabriel\\Projetos_codigos\\projeto_LP_c\\data\\charge_impossible.txt", "a");
        if (file == NULL) {
            fprintf(stderr, "Error opening file for writing!\n");
            return;
        }

        // Escrever no arquivo
        fprintf(file, " Impossible to charge the battery in the position (%d, %d)\n ", x, y - 1);
        fclose(file);

    }else if (map.map_data[8 - y - 1][x] == 1) {

        printf("Impossible to charge the battery in the position (%d, %d)\n", x, y);

        // Abrir o arquivo para escrita
        FILE *file = fopen("C:\\Users\\Davi Barros\\Documents\\Gabriel\\Projetos_codigos\\projeto_LP_c\\data\\charge_impossible.txt", "a");
        if (file == NULL) {
            fprintf(stderr, "Error opening file for writing!\n");
            return;
        }

        // Escrever no arquivo
        fprintf(file, " Impossible to charge the battery in the position (%d, %d)\n ", x, y + 1);
        fclose(file);

    } else if (map.map_data[8 - y][x + 1] == 1) {

        printf("Impossible to charge the battery in the position (%d, %d)\n", x, y);

        // Abrir o arquivo para escrita
        FILE *file = fopen("C:\\Users\\Davi Barros\\Documents\\Gabriel\\Projetos_codigos\\projeto_LP_c\\data\\charge_impossible.txt", "a");
        if (file == NULL) {
            fprintf(stderr, "Error opening file for writing!\n");
            return;
        }

        // Escrever no arquivo
        fprintf(file, " Impossible to charge the battery in the position (%d, %d)\n ", x + 1, y);
        fclose(file);

    }else if (map.map_data[8 - y ][x - 1] == 1) {
        

        printf("Impossible to charge the battery in the position (%d, %d)\n", x, y);

        // Abrir o arquivo para escrita
        FILE *file = fopen("C:\\Users\\Davi Barros\\Documents\\Gabriel\\Projetos_codigos\\projeto_LP_c\\data\\charge_impossible.txt", "a");
        if (file == NULL) {
            fprintf(stderr, "Error opening file for writing!\n");
            return;
        }

        // Escrever no arquivo
        fprintf(file, " Impossible to charge the battery in the position (%d, %d)\n ", x - 1, y);
        fclose(file);

    }else if (map.map_data[8 - y + 1][x + 1] == 1) {
        

        printf("Impossible to charge the battery in the position (%d, %d)\n", x, y);

        // Abrir o arquivo para escrita
        FILE *file = fopen("C:\\Users\\Davi Barros\\Documents\\Gabriel\\Projetos_codigos\\projeto_LP_c\\data\\charge_impossible.txt", "a");
        if (file == NULL) {
            fprintf(stderr, "Error opening file for writing!\n");
            return;
        }

        // Escrever no arquivo
        fprintf(file, " Impossible to charge the battery in the position (%d, %d)\n ", x + 1, y - 1);
        fclose(file);

    } else if (map.map_data[8 - y + 1][x - 1] == 1) {

        printf("Impossible to charge the battery in the position (%d, %d)\n", x, y);

        // Abrir o arquivo para escrita
        FILE *file = fopen("C:\\Users\\Davi Barros\\Documents\\Gabriel\\Projetos_codigos\\projeto_LP_c\\data\\charge_impossible.txt", "a");
        if (file == NULL) {
            fprintf(stderr, "Error opening file for writing!\n");
            return;
        }

        // Escrever no arquivo
        fprintf(file, " Impossible to charge the battery in the position (%d, %d)\n ", x - 1, y - 1);
        fclose(file);

    }else if (map.map_data[8 - y - 1][x + 1] == 1) {
        
        printf("Impossible to charge the battery in the position (%d, %d)\n", x, y);

        // Abrir o arquivo para escrita
        FILE *file = fopen("C:\\Users\\Davi Barros\\Documents\\Gabriel\\Projetos_codigos\\projeto_LP_c\\data\\charge_impossible.txt", "a");
        if (file == NULL) {
            fprintf(stderr, "Error opening file for writing!\n");
            return;
        }

        // Escrever no arquivo
        fprintf(file, " Impossible to charge the battery in the position (%d, %d)\n ", x + 1, y + 1);
        fclose(file);
    }

}

void list_way(tList *list, int actual[2]) {

    // Ler o mapa do arquivo
    tMap map = read_map_from_file();

    // Obter a matriz de dados do mapa
    int **map_data = get_map();

    // Obter a posição atual
    int y = actual[1];
    int x = actual[0];
    int color = map.map_data[8 - y][x];
    
    switch (color)
    {
    case 255:  insert_list(list, "go");  break;
    case 191:  insert_list(list, "gold"); break;
    case 127:  insert_list(list, "silver"); break;
    case 63:  insert_list(list, "bronze"); break;
    case 1:   insert_list(list, "charge_impossible"); break;  
    }

    tNode* current = list->first_elem;

    FILE *file = fopen("C:\\Users\\Davi Barros\\Documents\\Gabriel\\Projetos_codigos\\projeto_LP_c\\data\\list_way.txt", "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    fprintf(file, "List elements:\n");
    while (current != NULL) {
        fprintf(file, "%s\n", current->data);
        current = current->next;
    }

    fclose(file);
}
    
void gold(int actual[2]) {
    // Ler o mapa do arquivo
    tMap map = read_map_from_file();

    // Obter a matriz de dados do mapa
    int **map_data = get_map();

    // Obter a posição atual
    int y = actual[1];
    int x = actual[0];

    // Verificar se a cor na posição é igual a 191
    if (map.map_data[8 - y][x] == 191) {

        printf("Mineral found: Gold\n");

        // Abrir o arquivo para escrita
        FILE *file = fopen("C:\\Users\\Davi Barros\\Documents\\Gabriel\\Projetos_codigos\\projeto_LP_c\\data\\gold.txt", "a");
        if (file == NULL) {
            fprintf(stderr, "Error opening file for writing!\n");
            return;
        }

        // Escrever a cor no arquivo
        fprintf(file, "Mineral gold found at position (%d, %d) \n", x, y);
        fclose(file);
    }
}

void silver(int actual[2]) {
    // Ler o mapa do arquivo
    tMap map = read_map_from_file();

    // Obter a matriz de dados do mapa
    int **map_data = get_map();

    // Obter a posição atual
    int y = actual[1];
    int x = actual[0];

    // Verificar se a cor na posição é igual a 127
    if (map.map_data[8 - y][x] == 127) {
        printf("Mineral found: Silver\n");

        // Abrir o arquivo para escrita
        FILE *file = fopen("C:\\Users\\Davi Barros\\Documents\\Gabriel\\Projetos_codigos\\projeto_LP_c\\data\\silver.txt", "a");
        if (file == NULL) {
            fprintf(stderr, "Error opening file for writing!\n");
            return;
        }

        // Escrever a cor no arquivo
        fprintf(file, "Mineral silver found at position(%d, %d) \n", x, y);
        fclose(file);
    }
}

void bronze(int actual[2]) {
    // Ler o mapa do arquivo
    tMap map = read_map_from_file();

    // Obter a matriz de dados do mapa
    int **map_data = get_map();

    // Obter a posição atual
    int y = actual[1];
    int x = actual[0];

    // Verificar se a cor na posição é igual a 63
    if (map.map_data[8 - y][x] == 63) {

        printf("Mineral found: Bronze\n");

        // Abrir o arquivo para escrita
        FILE *file = fopen("C:\\Users\\Davi Barros\\Documents\\Gabriel\\Projetos_codigos\\projeto_LP_c\\data\\bronze.txt", "a");
        if (file == NULL) {
            fprintf(stderr, "Error opening file for writing!\n");
            return;
        }

        // Escrever a cor no arquivo
        fprintf(file, "Mineral bronze found at position(%d, %d)\n", x, y);
        fclose(file);
    }
}

void obstacles(int actual[2]) {
    // Ler o mapa do arquivo
    tMap map = read_map_from_file();

    // Obter a matriz de dados do mapa
    int **map_data = get_map();

    // Obter a posição atual
    int y = actual[1];
    int x = actual[0];

    // Verificar se a obstaculos
    if (map.map_data[8 - y + 1][x] == 0) {

        printf("obstacle_found\n");

        // Abrir o arquivo para escrita
        FILE *file = fopen("C:\\Users\\Davi Barros\\Documents\\Gabriel\\Projetos_codigos\\projeto_LP_c\\data\\obstacles.txt", "a");
        if (file == NULL) {
            fprintf(stderr, "Error opening file for writing!\n");
            return;
        }

        // Escrever no arquivo
        fprintf(file, " obstacle found at position (%d, %d)\n ", x, y - 1);
        fclose(file);

    }else if (map.map_data[8 - y - 1][x] == 0) {

        printf("obstacle_found\n");

        // Abrir o arquivo para escrita
        FILE *file = fopen("C:\\Users\\Davi Barros\\Documents\\Gabriel\\Projetos_codigos\\projeto_LP_c\\data\\obstacles.txt", "a");
        if (file == NULL) {
            fprintf(stderr, "Error opening file for writing!\n");
            return;
        }

        // Escrever no arquivo
        fprintf(file, " obstacle found at position (%d, %d)\n ", x, y + 1);
        fclose(file);

    } else if (map.map_data[8 - y][x + 1] == 0) {

        printf("obstacle_found\n");

        // Abrir o arquivo para escrita
        FILE *file = fopen("C:\\Users\\Davi Barros\\Documents\\Gabriel\\Projetos_codigos\\projeto_LP_c\\data\\obstacles.txt", "a");
        if (file == NULL) {
            fprintf(stderr, "Error opening file for writing!\n");
            return;
        }

        // Escrever no arquivo
        fprintf(file, " obstacle found at position (%d, %d)\n ", x + 1, y);
        fclose(file);

    }else if (map.map_data[8 - y ][x - 1] == 0) {
        

        printf("obstacle_found\n");

        // Abrir o arquivo para escrita
        FILE *file = fopen("C:\\Users\\Davi Barros\\Documents\\Gabriel\\Projetos_codigos\\projeto_LP_c\\data\\obstacles.txt", "a");
        if (file == NULL) {
            fprintf(stderr, "Error opening file for writing!\n");
            return;
        }

        // Escrever no arquivo
        fprintf(file, " obstacle found at position (%d, %d)\n ", x - 1, y);
        fclose(file);

    }else if (map.map_data[8 - y + 1][x + 1] == 0) {
        

        printf("obstacle_found\n");

        // Abrir o arquivo para escrita
        FILE *file = fopen("C:\\Users\\Davi Barros\\Documents\\Gabriel\\Projetos_codigos\\projeto_LP_c\\data\\obstacles.txt", "a");
        if (file == NULL) {
            fprintf(stderr, "Error opening file for writing!\n");
            return;
        }

        // Escrever no arquivo
        fprintf(file, " obstacle found at position (%d, %d)\n ", x + 1, y - 1);
        fclose(file);

    } else if (map.map_data[8 - y + 1][x - 1] == 0) {

        printf("obstacle_found\n");

        // Abrir o arquivo para escrita
        FILE *file = fopen("C:\\Users\\Davi Barros\\Documents\\Gabriel\\Projetos_codigos\\projeto_LP_c\\data\\obstacles.txt", "a");
        if (file == NULL) {
            fprintf(stderr, "Error opening file for writing!\n");
            return;
        }

        // Escrever no arquivo
        fprintf(file, " obstacle found at position (%d, %d)\n ", x - 1, y - 1);
        fclose(file);

    }else if (map.map_data[8 - y - 1][x + 1] == 0) {
        
        printf("obstacle_found\n");

        // Abrir o arquivo para escrita
        FILE *file = fopen("C:\\Users\\Davi Barros\\Documents\\Gabriel\\Projetos_codigos\\projeto_LP_c\\data\\obstacles.txt", "a");
        if (file == NULL) {
            fprintf(stderr, "Error opening file for writing!\n");
            return;
        }

        // Escrever no arquivo
        fprintf(file, " obstacle found at position (%d, %d)\n ", x + 1, y + 1);
        fclose(file);

    }

}

