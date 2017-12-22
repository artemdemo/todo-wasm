#include <stdio.h>
#include <stdlib.h>

#include "./todoModel.h"

char* _getToDo(int indexInList) {
    struct ToDo todoResult;
    int result = getToDo(indexInList, &todoResult);
    return todoResult.title;
}

int main(void) {
    initToDoList();
	addToDo("Some title -0", false);
	addToDo("Some title -1", true);
	addToDo("Some title -2", true);

	deleteToDo(1);
	char *title = _getToDo(1);

	printf("%s", title);

	return EXIT_SUCCESS;
}
