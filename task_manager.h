#ifndef TASK_MANAGER_H
#define TASK_MANAGER_H

// Estrutura de uma tarefa individual
typedef struct {
    char name[100];
    int priority;
    char due_date[11];
} Task;

// Estrutura do Gerenciador (Controle do Malloc)
typedef struct {
    Task *tasks;    // Ponteiro para o bloco de memória
    int count;      // Total de tarefas cadastradas
    int capacity;   // Espaço total alocado
} TaskManager;

// Assinaturas das funções (Essencial para tirar o erro de 'implicit declaration')
TaskManager* create_task_manager(int initial_capacity);
void free_task_manager(TaskManager *tm);

// Funções de Atualização (Seu Objetivo)
void update_task_name(TaskManager *tm, int index, const char *new_name);
void update_task_priority(TaskManager *tm, int index, int new_priority);
void update_date(TaskManager *tm, int index, const char *new_date);

#endif