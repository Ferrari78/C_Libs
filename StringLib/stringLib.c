//
// Created by felix on 15.12.2023.
//

#include "stringLib.h"
#include <ctype.h>
#include "list.h"
#include <stdio.h>
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

Word *mostLetter(char *string) {
    List *list = create_List();

    for (int i = 0; string[i] != '\0'; i++) {
        string[i] = tolower(string[i]);
        bool found = false;

        for (int j = 0; j < list->size; j++) {
            Node *tempNode = getNode(j, list);

            if (string[i] == ((Word *) tempNode->data)->letter) {
                ((Word *) tempNode->data)->size++;
                found = true;
                break;
            }
        }

        if (!found) {
            Word *temp = malloc(sizeof(Word));
            temp->letter = string[i];
            temp->size = 1;
            add(list, temp, STRUCT);
        }
    }

    Node *tenpHighSizeNode = getNode(0, list);
    for (int i = 1; i < list->size; ++i) {
        if (((Word *) getNode(i, list)->data)->size > ((Word *) tenpHighSizeNode->data)->size) {
            tenpHighSizeNode = getNode(i, list);
        }
    }

    Word *highestNode = malloc(sizeof(Word));
    highestNode->letter = ((Word *) tenpHighSizeNode->data)->letter;
    highestNode->size = ((Word *) tenpHighSizeNode->data)->size;

    deleteList(list);
    return highestNode;
}

