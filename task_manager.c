#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "task_manager.h"

// Aloca memória para o gerenciador e para o array de tarefas
TaskManager* create_task_manager(int initial_capacity) {
    TaskManager *tm = (TaskManager*) malloc(sizeof(TaskManager));
    if (tm == NULL) return NULL;

    tm->count = 0;
    tm->capacity = initial_capacity;
    tm->tasks = (Task*) malloc(tm->capacity * sizeof(Task));
    
    if (tm->tasks == NULL) {
        free(tm);
        return NULL;
    }
    return tm;
}

// Implementação das atualizações solicitadas
void update_task_name(TaskManager *tm, int index, const char *new_name) {
    if (index >= 0 && index < tm->count) {
        strncpy(tm->tasks[index].name, new_name, 99);
        tm->tasks[index].name[99] = '\0';
    } else {
        printf("Erro: Indice %d invalido.\n", index);
    }
}

void update_task_priority(TaskManager *tm, int index, int new_priority) {
    if (index >= 0 && index < tm->count) {
        tm->tasks[index].priority = new_priority;
    }
}

void update_date(TaskManager *tm, int index, const char *new_date) {
    if (index >= 0 && index < tm->count) {
        strncpy(tm->tasks[index].due_date, new_date, 10);
        tm->tasks[index].due_date[10] = '\0';
    }
}

// Libera toda a memória alocada (Evita Memory Leak)
void free_task_manager(TaskManager *tm) {
    if (tm != NULL) {
        free(tm->tasks);
        free(tm);
    }
}