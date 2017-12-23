#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "./todoModel.h"
#include "./format.h"

// Dynamic array: https://arduino.stackexchange.com/a/3778
struct ToDo *todosList = 0;
int todosListCurrentIndex = 0;
int todosListSize = TODOS_START_LENGTH;

int initToDoList(void) {
    // `todosList` can be initiated only once
    if (todosList == 0) {
        todosList = (struct ToDo*) malloc(todosListSize * sizeof(struct ToDo));
    }
    return EXIT_SUCCESS;
}

int checkGivenIndex(int indexInList) {
    if (indexInList > todosListCurrentIndex || indexInList < 0) {
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

/**
 * Create
 */

int addToDo(char *title, bool done) {
    // If array is full, we should reallocate memory for addition items
    if (todosListCurrentIndex == todosListSize - 1) {
        todosListSize += TODOS_START_LENGTH;
        todosList = (struct ToDo*) realloc(todosList, todosListSize * sizeof(struct ToDo));
    }

    todosList[todosListCurrentIndex].title = strdup(title);
    todosList[todosListCurrentIndex].done = done;
    todosList[todosListCurrentIndex].id = todosListCurrentIndex;
    todosListCurrentIndex++;
    return EXIT_SUCCESS;
}

/**
 * Update
 */

int updateToDoByIndex(int indexInList, char *title, bool done) {
    if (checkGivenIndex(indexInList) == EXIT_FAILURE) {
        return EXIT_FAILURE;
    }
    todosList[indexInList].title = strdup(title);
    todosList[indexInList].done = done;
    return EXIT_SUCCESS;
}

int updateToDoById(int todoId, char *title, bool done) {
    for (int i = 0; i < todosListCurrentIndex; i++) {
        if (todosList[i].id == todoId) {
            updateToDoByIndex(i, title, done);
            return EXIT_SUCCESS;
        }
    }
    return EXIT_FAILURE;
}

/**
 * Read
 */

int getToDoByIndex(int indexInList, struct ToDo *todoResult) {
    if (checkGivenIndex(indexInList) == EXIT_FAILURE) {
        return EXIT_FAILURE;
    }
    *todoResult = todosList[indexInList];
    return EXIT_SUCCESS;
}

int getToDoById(int todoId, struct ToDo *todoResult) {
    for (int i = 0; i < todosListCurrentIndex; i++) {
        if (todosList[i].id == todoId) {
            *todoResult = todosList[i];
            return EXIT_SUCCESS;
        }
    }
    return EXIT_FAILURE;
}

char* getToDoJsonString(int todoId) {
    struct ToDo todoResult;
    int result = getToDoById(todoId, &todoResult);
    if (result == EXIT_FAILURE) {
        return "";
    }

    return todoToJsonString(todoResult);
}

char* getAllToDoJsonString() {
    int jsonStrSizeStep = 200;
    int jsonStrSize = jsonStrSizeStep;
    int jsonStrUsedSize = 0;
    char *jsonStr = (char*)malloc(jsonStrSize * sizeof(char*));
    strcpy(jsonStr, "");
    strcat(jsonStr, "[");
    for (int i = 0; i < todosListCurrentIndex; i++) {
        char *todoJsonStr = todoToJsonString(todosList[i]);
        int nextBlockSize = strlen(todoJsonStr) + 1;
        if (jsonStrSize < jsonStrUsedSize + nextBlockSize) {
            jsonStrSize += jsonStrSizeStep;
            jsonStr = (char*) realloc(jsonStr, jsonStrSize * sizeof(char*));
        }
        jsonStrUsedSize += nextBlockSize;
        strcat(jsonStr, todoJsonStr);
        if (i + 1 < todosListCurrentIndex) {
            strcat(jsonStr, ",");
        }
    }
    strcat(jsonStr, "]");
    return jsonStr;
}

/**
 * Delete
 */

int deleteToDoByIndex(int indexInList) {
    if (checkGivenIndex(indexInList) == EXIT_FAILURE) {
        return EXIT_FAILURE;
    }
    for (int i = indexInList - 1; i < todosListCurrentIndex - 1; i++) {
        todosList[i] = todosList[i + 1];
    }
    todosListCurrentIndex--;
    return EXIT_SUCCESS;
}

int deleteToDoById(int todoId) {
    for (int i = 0; i < todosListCurrentIndex; i++) {
        if (todosList[i].id == todoId) {
            deleteToDoByIndex(i);
            return EXIT_SUCCESS;
        }
    }
    return EXIT_FAILURE;
}

/**
 * List length
 */

int getToDoListLength(void) {
    return todosListCurrentIndex;
}
