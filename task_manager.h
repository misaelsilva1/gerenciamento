#ifndef TASK_MANAGER_H
#define TASK_MANAGER_H

// Estrutura de uma tarefa individual
typedef struct {
    char name[100];
    int priority;
    char due_date[11]; // Formato: YYYY/MM/DD
} Task;

// Estrutura do Gerenciador
typedef struct {
    Task *tasks;
    int count;
    int capacity;
} TaskManager;

// Declaração das funções (Assinaturas)
TaskManager* create_task_manager();
void add_task(TaskManager *tm, const char *name, int priority, const char *date);
void update_task_name(TaskManager *tm, int index, const char *new_name);
void update_task_priority(TaskManager *tm, int index, int new_priority);
void update_date(TaskManager *tm, int index, const char *new_date);
void list_tasks(TaskManager *tm);
void free_task_manager(TaskManager *tm);

#endif