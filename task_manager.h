#ifndef TASK_MANAGER_H
#define TASK_MANAGER_H

#define MAX_TASKS 100
#define NAME_LENGTH 50
#define DATE_LENGTH 11  // YYYY-MM-DD + '\0'

typedef struct {
    int id;
    char name[NAME_LENGTH];
    int priority;
    char date[DATE_LENGTH];
} Task;

typedef struct {
    Task tasks[MAX_TASKS];
    int task_count;
} TaskManager;

// Funções do gerenciador
TaskManager create_task_manager();
void add_task(TaskManager *manager, int id, const char *name, int priority, const char *date);
void update_task_name(TaskManager *manager, int id, const char *new_name);
void update_task_priority(TaskManager *manager, int id, int new_priority);
void update_date(TaskManager *manager, int id, const char *new_date);
void list_tasks(TaskManager *manager);
void free_task_manager(TaskManager *manager);  // só para compatibilidade, não precisa liberar memória dinâmica

#endif