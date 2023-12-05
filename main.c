#include <stdio.h>
#include "module/LinkedList.h"

int main() {
    printf("Hello, World!\n");
    List* list = create_List();
    char b[255] = "hallo";
    int a = 23;
    add(list,  b,STRING);
    add(list,  a, INT);
    printf("position %d\n", searchData(list,b,STRING));
    printNodeData(list->end);
    return 0;
}
