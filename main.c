#include <stdio.h>
#include <stdlib.h>

#include "./todoModel.h"

int main(void) {
    initToDoList();
	addToDo("Some title -0", false);
	addToDo("Some title -1", true);
	addToDo("Some title -2", true);
	struct ToDo someToDo;

	deleteToDo(1);
	getToDo(1, &someToDo);
	return EXIT_SUCCESS;
}
