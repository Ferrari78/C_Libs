//
// Created by felix on 15.12.2023.
//

#include "timeoperations.h"
#include <time.h>
#include <stdio.h>

const TimeOfRun runTime_default = {0, 0, 0, 0};

struct tm timeInput(enum TimeInput timeInput) {

    time_t t = time(NULL);
    struct tm time1;
    int year = 0;

    time1 = *localtime(&t);

    switch (timeInput) {
        case S_TIME:
            scanf("%2d:%2d", &time1.tm_hour, &time1.tm_min);
            break;
        case F_TIME:
            scanf("%2d:%2d:%2d", &time1.tm_hour, &time1.tm_min);
            break;
        case DATE:
            scanf("%2d.%2d.%4d", &time1.tm_mday, &time1.tm_mon - 1, &year);
            break;
            /* case DATE_FULL:
                 scanf("%d:%d",&time.tm_hour,&time.tm_min);
                 break;*/
        case TIME_DATE:
            scanf("%2d.%2d.%4d %2d:%2d", &time1.tm_mday, &time1.tm_mon - 1, &year, &time1.tm_hour, &time1.tm_min);
            break;
        case NOW:
            break;
    }

    if ((int) DATE <= (int) timeInput) {
        time1.tm_year = year - 1900;
    }

    return time1;
}

void getRunTime(TimeOfRun *timeOfRun) {

    if (!timeOfRun->isTimeStart) {
        timeOfRun->start = clock();
        timeOfRun->isTimeStart++;
    } else {
        timeOfRun->end = clock();
        timeOfRun->timeOfRun = ((float) (timeOfRun->end - timeOfRun->start)) / CLOCKS_PER_SEC;
        printf("Run time: %fs\n", timeOfRun->timeOfRun);
    }

}

