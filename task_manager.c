#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "task_manager.h"

TaskManager* create_task_manager() {
    TaskManager *tm = malloc(sizeof(TaskManager));
    tm->count = 0;
    tm->capacity = 10;
    tm->tasks = malloc(sizeof(Task) * tm->capacity);
    return tm;
}

void add_task(TaskManager *tm, const char *name, int priority, const char *date) {
    if (tm->count < tm->capacity) {
        strcpy(tm->tasks[tm->count].name, name);
        tm->tasks[tm->count].priority = priority;
        strcpy(tm->tasks[tm->count].due_date, date);
        tm->count++;
    }
}

// --- SUAS NOVAS FUNÇÕES DE ATUALIZAÇÃO ---

void update_task_name(TaskManager *tm, int index, const char *new_name) {
    if (index >= 0 && index < tm->count) {
        strcpy(tm->tasks[index].name, new_name);
        printf("Nome da tarefa %d atualizado!\n", index);
    }
}

void update_task_priority(TaskManager *tm, int index, int new_priority) {
    if (index >= 0 && index < tm->count) {
        tm->tasks[index].priority = new_priority;
        printf("Prioridade da tarefa %d atualizada!\n", index);
    }
}

void update_date(TaskManager *tm, int index, const char *new_date) {
    if (index >= 0 && index < tm->count) {
        strcpy(tm->tasks[index].due_date, new_date);
        printf("Data da tarefa %d atualizada!\n", index);
    }
}

void list_tasks(TaskManager *tm) {
    for (int i = 0; i < tm->count; i++) {
        printf("%d. [%d] %s - Vence em: %s\n", i, tm->tasks[i].priority, tm->tasks[i].name, tm->tasks[i].due_date);
    }
}

void free_task_manager(TaskManager *tm) {
    free(tm->tasks);
    free(tm);
}