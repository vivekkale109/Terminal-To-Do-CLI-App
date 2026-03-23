#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "tasks.json"
#define MAX_TASKS 100
#define MAX_TITLE 256

// ANSI colors
#define GREEN "\033[0;32m"
#define RED "\033[0;31m"
#define YELLOW "\033[0;33m"
#define RESET "\033[0m"

typedef struct {
    int id;
    char title[MAX_TITLE];
    int completed; // 0 = pending, 1 = done
} Task;

Task tasks[MAX_TASKS];
int taskCount = 0;

// Load tasks from JSON file (basic parsing)
void loadTasks() {
    FILE *file = fopen(FILE_NAME, "r");
    if (!file) return;

    char line[512];
    while (fgets(line, sizeof(line), file)) {
        Task t;
        if (sscanf(line, "{\"id\":%d,\"title\":\"%[^\"]\",\"completed\":%d}",
                   &t.id, t.title, &t.completed) == 3) {
            tasks[taskCount++] = t;
        }
    }

    fclose(file);
}

// Save tasks to JSON file
void saveTasks() {
    FILE *file = fopen(FILE_NAME, "w");
    if (!file) {
        printf(RED "Error saving tasks!\n" RESET);
        return;
    }

    for (int i = 0; i < taskCount; i++) {
        fprintf(file, "{\"id\":%d,\"title\":\"%s\",\"completed\":%d}\n",
                tasks[i].id, tasks[i].title, tasks[i].completed);
    }

    fclose(file);
}

// Add new task
void addTask(char *title) {
    if (taskCount >= MAX_TASKS) {
        printf(RED "Task limit reached!\n" RESET);
        return;
    }

    Task t;
    t.id = (taskCount == 0) ? 1 : tasks[taskCount - 1].id + 1;
    strcpy(t.title, title);
    t.completed = 0;

    tasks[taskCount++] = t;
    saveTasks();

    printf(GREEN "Task added successfully!\n" RESET);
}

// List tasks
void listTasks() {
    if (taskCount == 0) {
        printf(YELLOW "No tasks found.\n" RESET);
        return;
    }

    printf("\n--- To-Do List ---\n");
    for (int i = 0; i < taskCount; i++) {
        printf("%d. [%s] %s\n",
               tasks[i].id,
               tasks[i].completed ? "✔" : " ",
               tasks[i].title);
    }
}

// Mark task as done
void markDone(int id) {
    for (int i = 0; i < taskCount; i++) {
        if (tasks[i].id == id) {
            tasks[i].completed = 1;
            saveTasks();
            printf(GREEN "Task marked as completed!\n" RESET);
            return;
        }
    }
    printf(RED "Task not found!\n" RESET);
}

// Delete task
void deleteTask(int id) {
    int found = 0;

    for (int i = 0; i < taskCount; i++) {
        if (tasks[i].id == id) {
            found = 1;
            for (int j = i; j < taskCount - 1; j++) {
                tasks[j] = tasks[j + 1];
            }
            taskCount--;
            saveTasks();
            printf(GREEN "Task deleted!\n" RESET);
            return;
        }
    }

    if (!found) {
        printf(RED "Task not found!\n" RESET);
    }
}

// Main CLI handler
int main(int argc, char *argv[]) {
    loadTasks();

    if (argc < 2) {
        printf(YELLOW "Usage:\n" RESET);
        printf("  add \"task\"\n");
        printf("  list\n");
        printf("  done <id>\n");
        printf("  delete <id>\n");
        return 0;
    }

    if (strcmp(argv[1], "add") == 0) {
        if (argc < 3) {
            printf(RED "Please provide a task.\n" RESET);
            return 1;
        }
        addTask(argv[2]);

    } else if (strcmp(argv[1], "list") == 0) {
        listTasks();

    } else if (strcmp(argv[1], "done") == 0) {
        if (argc < 3) {
            printf(RED "Provide task ID.\n" RESET);
            return 1;
        }
        markDone(atoi(argv[2]));

    } else if (strcmp(argv[1], "delete") == 0) {
        if (argc < 3) {
            printf(RED "Provide task ID.\n" RESET);
            return 1;
        }
        deleteTask(atoi(argv[2]));

    } else {
        printf(RED "Unknown command!\n" RESET);
    }

    return 0;
}