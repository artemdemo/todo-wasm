#include <string.h>
#include <emscripten/emscripten.h>

#include "./todoModel.h"

int main(void) {
    initToDoList();
}

char message[] = "hello wasm!";

char* EMSCRIPTEN_KEEPALIVE getMessageRef() { 
  return message;
}

int EMSCRIPTEN_KEEPALIVE getMessageLength() {
  return sizeof(message);
}


int EMSCRIPTEN_KEEPALIVE _addToDo(char title[], bool done) {
    return addToDo(title, done);
}

char* EMSCRIPTEN_KEEPALIVE _getToDo(int indexInList) {
    struct ToDo todoResult;
    int result = getToDo(indexInList, &todoResult);
    return todoResult.title;
}

int EMSCRIPTEN_KEEPALIVE _deleteToDo(int indexInList) {
    return deleteToDo(indexInList);
}

int EMSCRIPTEN_KEEPALIVE _getToDoListLength(void) {
    return getToDoListLength();
}