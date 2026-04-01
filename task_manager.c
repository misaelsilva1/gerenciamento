#include <stdio.h>
#include <string.h>
#include "task_manager.h"

TaskManager create_task_manager() {
    TaskManager manager;
    manager.task_count = 0;
    return manager;
}

void add_task(TaskManager *manager, int id, const char *name, int priority, const char *date) {
    if (manager->task_count >= MAX_TASKS) {
        printf("Erro: limite de tarefas atingido!\n");
        return;
    }

    Task *t = &manager->tasks[manager->task_count];
    t->id = id;
    strncpy(t->name, name, NAME_LENGTH - 1);
    t->name[NAME_LENGTH - 1] = '\0';
    t->priority = priority;
    strncpy(t->date, date, DATE_LENGTH - 1);
    t->date[DATE_LENGTH - 1] = '\0';

    manager->task_count++;
}

void update_task_name(TaskManager *manager, int id, const char *new_name) {
    for (int i = 0; i < manager->task_count; i++) {
        if (manager->tasks[i].id == id) {
            strncpy(manager->tasks[i].name, new_name, NAME_LENGTH - 1);
            manager->tasks[i].name[NAME_LENGTH - 1] = '\0';
            return;
        }
    }
    printf("Tarefa com ID %d não encontrada.\n", id);
}

void update_task_priority(TaskManager *manager, int id, int new_priority) {
    for (int i = 0; i < manager->task_count; i++) {
        if (manager->tasks[i].id == id) {
            manager->tasks[i].priority = new_priority;
            return;
        }
    }
    printf("Tarefa com ID %d não encontrada.\n", id);
}

void update_date(TaskManager *manager, int id, const char *new_date) {
    for (int i = 0; i < manager->task_count; i++) {
        if (manager->tasks[i].id == id) {
            strncpy(manager->tasks[i].date, new_date, DATE_LENGTH - 1);
            manager->tasks[i].date[DATE_LENGTH - 1] = '\0';
            return;
        }
    }
    printf("Tarefa com ID %d não encontrada.\n", id);
}

void list_tasks(TaskManager *manager) {
    printf("Lista de Tarefas:\n");
    for (int i = 0; i < manager->task_count; i++) {
        Task *t = &manager->tasks[i];
        printf("ID: %d | Nome: %s | Prioridade: %d | Data: %s\n",
               t->id, t->name, t->priority, t->date);
    }
}

void free_task_manager(TaskManager *manager) {
    // Nenhuma alocação dinâmica foi feita, então não há nada para liberar
    (void)manager;  // para evitar warnings de variável não usada
}