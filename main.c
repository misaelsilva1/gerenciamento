#include "task_manager.h"
#include <stdio.h>

int main() {
    TaskManager *tm = create_task_manager();

    // Adicionando tarefas iniciais
    add_task(tm, "Adicionar tarefas", 1, "2026-03-30");
    add_task(tm, "Gerenciar Tarefas", 2, "2026-03-31");

    printf("--- Lista Original ---\n");
    list_tasks(tm);

    // Testando suas novas funções de atualização
    update_task_name(tm, 0, "Analisar Tarefas");
    update_task_priority(tm, 1, 2); // Mudando prioridade das tarefas
    update_date(tm, 0, "2026-04-05");

    printf("\n--- Lista Atualizada ---\n");
    list_tasks(tm);

    free_task_manager(tm);
    return 0;
}