#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "task_manager.h"

int main() {
    // Inicializa o gerenciador com malloc (capacidade para 10)
    TaskManager *tm = create_task_manager(10);
    if (tm == NULL) return 1;

    // Apenas para teste, vamos simular que já existe uma tarefa no índice 0
    // (Em um sistema real, você usaria uma função add_task primeiro)
    tm->count = 1; 
    strcpy(tm->tasks[0].name, "Tarefa Original");
    tm->tasks[0].priority = 5;
    strcpy(tm->tasks[0].due_date, "01/01/2026");

    int opcao = -1;
    while (opcao != 0) {
        printf("\n--- GERENCIADOR DE TAREFAS ---\n");
        printf("1. Editar Nome\n2. Editar Prioridade\n3. Editar Data\n4. Ver Tarefa\n0. Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);
        getchar(); // Limpa o buffer do 'Enter'

        if (opcao == 1) {
            char novo[100];
            printf("Novo nome: ");
            fgets(novo, 100, stdin);
            novo[strcspn(novo, "\n")] = 0;
            update_task_name(tm, 0, novo);
        } 
        else if (opcao == 2) {
            int p;
            printf("Nova prioridade: ");
            scanf("%d", &p);
            update_task_priority(tm, 0, p);
        }
        else if (opcao == 3) {
            char data[11];
            printf("Nova data (DD/MM/AAAA): ");
            scanf("%s", data);
            update_date(tm, 0, data);
        }
        else if (opcao == 4) {
            printf("\nTAREFA [0]: %s | Prio: %d | Data: %s\n", 
                   tm->tasks[0].name, tm->tasks[0].priority, tm->tasks[0].due_date);
        }
    }

    // Liberação final da memória
    free_task_manager(tm);
    printf("Memoria liberada. Saindo...\n");

    return 0;
}