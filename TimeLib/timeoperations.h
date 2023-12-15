//
// Created by felix on 15.12.2023.
//

#ifndef LINKEDLIST_TIMEOPERATIONS_H
#define LINKEDLIST_TIMEOPERATIONS_H

enum TimeInput {
    NOW,
    S_TIME ,     // HH:MM
    F_TIME,     // HH:MM:SS
    DATE,       // DD.MM.YYYY
    //DATE_FULL, // Wortbasierte Eingabe
    TIME_DATE,  // DD.MM.YYYY HH:MM


};

struct tm timeInput(enum TimeInput timeInput);

#endif //LINKEDLIST_TIMEOPERATIONS_H
