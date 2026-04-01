#include <stdio.h>
#include "task_manager.h"

int main() {
    TaskManager manager = create_task_manager();

    add_task(&manager, 1, "Adicionar tarefas", 2, "2026-04-01");
    add_task(&manager, 2, "Enviar email", 1, "2026-04-02");

    update_task_name(&manager, 1, "Atualizar tarefas");
    update_task_priority(&manager, 2, 3);
    update_date(&manager, 1, "2026-04-03");

    list_tasks(&manager);

    free_task_manager(&manager);

    return 0;
}