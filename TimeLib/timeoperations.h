//
// Created by felix on 15.12.2023.
//

#ifndef LINKEDLIST_TIMEOPERATIONS_H
#define LINKEDLIST_TIMEOPERATIONS_H

#include "timeoperations.h"
#include <time.h>
#include <stdio.h>

enum TimeInput {
    NOW,
    S_TIME,     // HH:MM
    F_TIME,     // HH:MM:SS
    DATE,       // DD.MM.YYYY
    //DATE_FULL, // Wortbasierte Eingabe
    TIME_DATE,  // DD.MM.YYYY HH:MM
};

enum RunStartEnd {
    Start = 0,
    End
};

typedef struct {
    clock_t start;
    clock_t end;
    float timeOfRun;
    int isTimeStart;
} TimeOfRun;

extern const TimeOfRun runTime_default;

struct tm timeInput(enum TimeInput timeInput);

void getRunTime(TimeOfRun *timeOfRun, enum RunStartEnd startEnd);

#endif //LINKEDLIST_TIMEOPERATIONS_H
