#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./include/list.h"


// Inserir elemento no início
void insert_list(tList *list, const char* new_data) {
    tNode* new_node = (tNode*) malloc(sizeof(tNode));
    if (new_node == NULL) {
        printf("Error: No space left in memory.\n");
        return;
    }

    // Alocar memória para a cadeia de caracteres e copiar dados
    new_node->data = strdup(new_data);
    new_node->next = list->first_elem; // Definir o próximo nó do novo nó
    list->first_elem = new_node; // Atualizar ponteiro externo da lista para o novo nó
}

// Remover um elemento de valor del_data
void remove_list(tList *list, const char* del_data) {
    if (list->first_elem == NULL) {
        printf("Cannot delete from an empty list.\n");
        return;
    }

    tNode* current = list->first_elem;
    tNode* prev = NULL;

    while (current != NULL && strcmp(current->data, del_data) != 0) {
        prev = current;
        current = current->next;
    }

    if (current != NULL) {
        if (prev == NULL) {
            list->first_elem = current->next;  
        } else {
            prev->next = current->next;  
        }
    
        free(current->data); // Memória livre alocada para a cadeia de caracteres
        free(current);  
    } else {
        printf("Node with data %s not found in the list.\n", del_data);
    }
}

// Liberar memória alocada para a lista
void free_list(tList *list) {
    tNode* current = list->first_elem;
    tNode* temp;

    while (current != NULL) {
        temp = current;
        current = current->next;
        free(temp->data);  // Memória livre alocada para a cadeia de caracteres
        free(temp);  
    }

    list->first_elem = NULL;  
}

// Imprimir todos os elementos da lista
void print_list(tList *list) {
    tNode* current = list->first_elem;

    printf("List elements: ");
    while (current != NULL) {
        printf("%s ", current->data);
        current = current->next;
    }
    printf("\n");
}

// List constructor
tList create_list() {
    tList list;
    list.first_elem = NULL;  // Inicializar a lista com ponteiro NULL
    return list;
}
