#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "./todoModel.h"

int main(void) {
    initToDoList();
	addToDo("Some title", false);
	addToDo("Some other title", true);
	addToDo("This should be deleted", true);
	addToDo("Another title", true);

	printf("%s\n", getToDoJsonString(0));
	printf("%s\n", getAllToDoJsonString());
	deleteToDoById(2);
	printf("%s\n", getToDoJsonString(20));
	printf("%s\n", getAllToDoJsonString());

	//updateToDoById(2, "Some title -2 updated", true);

	
	

	return EXIT_SUCCESS;
}
