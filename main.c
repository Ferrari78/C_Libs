#include <stdio.h>
#include "list.h"
#include "stringLib.h"
#include <stdlib.h>
#include "timeoperations.h"

int main() {

    List *list = create_List();
    TimeOfRun timeOfRun = runTime_default;
    TimeOfRun zweite = runTime_default;

    getRunTime(&timeOfRun);

    for (int i = 0; i < 100000000; ++i);

    getRunTime(&timeOfRun);
    getRunTime(&zweite);

    int a = 23;
    add(list, &a, INT);
    add(list, &a, INT);
    add(list, &a, INT);
    add(list, &a, INT);
    add(list, &a, INT);
    add(list, &a, INT);
    printNodeData(list->end);
    deleteList(list);

    getRunTime(&timeOfRun);
    getRunTime(&zweite);


    return 0;
}
