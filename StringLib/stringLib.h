//
// Created by felix on 15.12.2023.
//

#ifndef AUFGABE8_WORDCOUNTER_H
#define AUFGABE8_WORDCOUNTER_H

typedef struct {
    char letter;
    int size;
}Word;

int countUpperCases(const char* string);
int countWords(const char* string);
struct mostWord* mostLetter(char* string);

#endif //AUFGABE8_WORDCOUNTER_H
