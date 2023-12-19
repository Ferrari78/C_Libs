#include <stdio.h>
#include "list.h"
#include "stringLib.h"
#include "timeoperations.h"

int main() {

    List *list = create_List();

    int a =  23;
    add(list,  &a, INT);
    add(list,&"Hallo1",STRING);
    add(list,&"Hallo",STRING);
    add(list,&"asd",STRING);
    add(list,&"af",STRING);
    printNodeData(list->end);
    deleteList(list);

    return 0;
}
