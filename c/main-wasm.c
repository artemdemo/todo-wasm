#include <string.h>
#include <stdlib.h>
#include <string.h>
#include <emscripten/emscripten.h>

#include "./todoModel.h"

int main(void) {
    initToDoList();
}

int EMSCRIPTEN_KEEPALIVE _addToDo(char title[], bool done) {
    return addToDo(title, done);
}

char* EMSCRIPTEN_KEEPALIVE _getToDo(int indexInList) {
    return getToDoJsonString(indexInList);
}

int EMSCRIPTEN_KEEPALIVE _deleteToDo(int todoId) {
    return deleteToDoById(todoId);
}

int EMSCRIPTEN_KEEPALIVE _getToDoListLength(void) {
    return getToDoListLength();
}
