#include <stdio.h>
#include "module/LinkedList.h"

int main() {
    List *list = create_List();
    char b[255] = "hallo";
    int* a = (int *) 23;
    add(list, b, STRING);
    add(list,  a, INT);
    add(list,"Hallo",STRING);
    add(list,"Haallo",STRING);
    add(list,"asd",STRING);
    add(list,"af",STRING);
    printNodeData(list->end->next);

    return 0;
}
