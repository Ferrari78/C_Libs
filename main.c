#include <stdio.h>
#include "list.h"
#include "stringLib.h"
#include "timeoperations.h"

int main() {

    List *list = createList();

    int a = 23;
    char *b = malloc(sizeof(char) * 4);
    b = "hallo";

    add(list, &a, INT);
    add(list, b, STRING);
    printNodeData(list->end);
    deleteList(list);
    printf("%s", b);
    return 0;
}
