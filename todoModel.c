#include <stdio.h>
#include <stdlib.h>

#include "./todoModel.h"

// Dynamic array: https://arduino.stackexchange.com/a/3778
struct ToDo *todosList = 0;
int todosListCurrentIndex = 0;
int todosListSize = TODOS_START_LENGTH;

int checkGivenIndex(int indexInList) {
    if (indexInList > todosListCurrentIndex || indexInList < 0) {
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

int initToDoList(void) {
    // `todosList` can be initiated only once
    if (todosList == 0) {
        todosList = (struct ToDo*) malloc(todosListSize * sizeof(struct ToDo));
    }
    return EXIT_SUCCESS;
}

int addToDo(char title[], bool done) {
    // If array is full, we should reallocate memory for addition items
    if (todosListCurrentIndex == todosListSize - 1) {
        todosListSize += TODOS_START_LENGTH;
        todosList = (struct ToDo*) realloc(todosList, todosListSize * sizeof(struct ToDo));
    }
    todosList[todosListCurrentIndex].title = (char*)malloc(sizeof(char*));
    todosList[todosListCurrentIndex].title = title;
    todosList[todosListCurrentIndex].done = done;
    todosList[todosListCurrentIndex].id = todosListCurrentIndex;
    todosListCurrentIndex++;
	return EXIT_SUCCESS;
}

int getToDo(int indexInList, struct ToDo *todoResult) {
    if (checkGivenIndex(indexInList) == EXIT_FAILURE) {
        return EXIT_FAILURE;
    }
    *todoResult = todosList[indexInList];
    return EXIT_SUCCESS;
}

int deleteToDo(int indexInList) {
    if (checkGivenIndex(indexInList) == EXIT_FAILURE) {
        return EXIT_FAILURE;
    }
    for(int i = indexInList - 1; i < todosListCurrentIndex - 1; i++){
        todosList[i] = todosList[i + 1];
    }
    todosListCurrentIndex--;
    return EXIT_SUCCESS;
}

int getToDoListLength(void) {
    return todosListCurrentIndex;
}
