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