#include <stdio.h>
#include "list.h"
#include "stringLib.h"
#include "timeoperations.h"

int main() {

    List *list = createList();

    int a = 23;
    char hallo[] = "hallo";
    add(list, &a, INT);
    add(list, hallo, STRING);
    printNodeData(list->end);
    deleteList(list);

    return 0;
}
