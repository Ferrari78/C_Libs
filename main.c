#include <stdio.h>
#include "list.h"
#include "stringLib.h"
#include "timeoperations.h"

int main() {

    List *list = createList();

    int a = 23;
    char *stringa1 = malloc(255 * sizeof(char));
    strcpy(stringa1, "Hallo");

    add(list, &a, INT);
    add(list, stringa1, STRING);
    printNodeData(list->end);
    deleteList(list);
    printf("%s", stringa1);
    return 0;
}
