#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "./todoModel.h"

char* todoToJsonString(struct ToDo todoResult) {
    char id[10];
    sprintf(id, "%d", todoResult.id);
    int length = strlen(todoResult.title) + strlen(id) + 25;
    char *jsonStr = (char*)malloc(length * sizeof(char*));
    strcpy(jsonStr, "");

    strcat(jsonStr, "{\"title\": \"");
    strcat(jsonStr, todoResult.title);
    strcat(jsonStr, "\", \"done\": ");
    if (todoResult.done) {
        strcat(jsonStr, "true");
    } else {
        strcat(jsonStr, "false");
    }
    strcat(jsonStr, ", \"id\": ");
    strcat(jsonStr, id);
    strcat(jsonStr, "}");
    return jsonStr;
}