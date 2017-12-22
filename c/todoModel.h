// I'm using `bool` type of data
// @source https://en.wikibooks.org/wiki/C_Programming/stdbool.h
#include <stdbool.h>

#ifndef TODO_MODEL_H_
#define TODO_MODEL_H_

#define TODOS_START_LENGTH 2

struct ToDo {
    int id;
    char *title;
    bool done;
};

int initToDoList(void);
int addToDo(char[], bool);
int deleteToDo(int);
int getToDo(int, struct ToDo*);
int deleteToDo(int);
int getToDoListLength(void);

#endif