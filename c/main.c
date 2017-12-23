#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "./todoModel.h"

int main(void) {
    initToDoList();
	addToDo("Some title -0", false);
	addToDo("Some title -1", true);
	addToDo("Some title -2", true);

	deleteToDoById(1);

	updateToDoById(2, "Some title -2 updated", true);

	printf("%s\n", getToDoJsonString(2));
	printf("%s\n", getToDoJsonString(12));
	printf("%s\n", getAllToDoJsonString());

	return EXIT_SUCCESS;
}
