#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "./todoModel.h"

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

int addToDo(char *title, bool done) {
    // If array is full, we should reallocate memory for addition items
    if (todosListCurrentIndex == todosListSize - 1) {
        todosListSize += TODOS_START_LENGTH;
        todosList = (struct ToDo*) realloc(todosList, todosListSize * sizeof(struct ToDo));
    }
    //todosList[todosListCurrentIndex].title = (char*)malloc(sizeof(char*));
    todosList[todosListCurrentIndex].title = strdup(title);
    todosList[todosListCurrentIndex].done = done;
    todosList[todosListCurrentIndex].id = todosListCurrentIndex;
    todosListCurrentIndex++;
	return EXIT_SUCCESS;
}

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

int getToDo(int indexInList, struct ToDo *todoResult) {
    if (checkGivenIndex(indexInList) == EXIT_FAILURE) {
        return EXIT_FAILURE;
    }
    *todoResult = todosList[indexInList];
    return EXIT_SUCCESS;
}

char* getToDoJsonString(int indexInList) {
    struct ToDo todoResult;
    int result = getToDo(indexInList, &todoResult);
    if (result == EXIT_FAILURE) {
        return "";
    }

    char *jsonStr = (char*)malloc(sizeof(char*));

	strcat(jsonStr, "{\"title\": \"");
	strcat(jsonStr, todoResult.title);
	strcat(jsonStr, "\", \"done\": ");
	if (todoResult.done) {
		strcat(jsonStr, "true");
	} else {
		strcat(jsonStr, "false");
	}
	strcat(jsonStr, ", \"id\": ");
	char id[10];
	sprintf(id, "%d", todoResult.id);
	strcat(jsonStr, id);
	strcat(jsonStr, "}");
    return jsonStr;
}

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

int getToDoListLength(void) {
    return todosListCurrentIndex;
}
