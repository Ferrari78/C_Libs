#include <stdio.h>
#include "list.h"
#include "stringLib.h"

int main() {

    List *list = create_List();
    char b[255] = "Hello World";
    printf("%d", countUpperCases(b));
/*    int* a = (int *) 23;
    add(list, b, STRING);
    add(list,  a, INT);
    add(list,"Hallo",STRING);
    add(list,"Haallo",STRING);
    add(list,"asd",STRING);
    add(list,"af",STRING);
    printNodeData(list->end);
    deleteList(list);*/

    return 0;
}
