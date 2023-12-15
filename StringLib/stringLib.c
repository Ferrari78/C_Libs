//
// Created by felix on 15.12.2023.
//

#include "stringLib.h"
#include <ctype.h>
#include "list.h"
#include <stdlib.h>
#include <stdbool.h>


int countUpperCases(const char *string) {
    int counter = 0;
    for (int i = 0; string[i] != '\0'; i++) {
        if (isupper(string[i])) {
            counter++;
        }
    }
    return counter;
}

int countWords(const char *string) {
    int counter = 0;
    if (string[0] != '\0') {
        counter++;
    } else {
        return 0;
    }

    for (int i = 0; string[i] != '\0'; i++) {
        if (string[i] == ' ') {
            counter++;
        }
    }

    return counter;
}

Letter *mostLetter(char *string) {
    List *list = create_List();

    for (int i = 0; string[i] != '\0'; i++) {
        if( string[i] == ' '){
            continue;
        }
        string[i] = tolower(string[i]);
        bool found = false;

        for (int j = 0; j < list->size; j++) {
            Node *tempNode = getNode(j, list);

            if (string[i] == ((Letter *) tempNode->data)->letter) {
                ((Letter *) tempNode->data)->size++;
                found = true;
                break;
            }
        }

        if (!found) {
            Letter *temp = malloc(sizeof(Letter));
            temp->letter = string[i];
            temp->size = 1;
            add(list, temp, STRUCT);
        }
    }

    Node *tempHighSizeNode = getNode(0, list);
    for (int i = 1; i < list->size; ++i) {
        if (((Letter *) getNode(i, list)->data)->size > ((Letter *) tempHighSizeNode->data)->size) {
            tempHighSizeNode = getNode(i, list);
        }
    }

    Letter *highestNode = malloc(sizeof(Letter));
    highestNode->letter = ((Letter *) tempHighSizeNode->data)->letter;
    highestNode->size = ((Letter *) tempHighSizeNode->data)->size;

    deleteList(list);
    return highestNode;
}

