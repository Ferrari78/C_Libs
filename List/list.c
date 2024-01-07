//
// Created by felix on 05.12.2023.
//
#include <stdlib.h>
#include <stdio.h>
#include "list.h"
#include <string.h>

int debug = 0;

/*
 * Create a list
 */
List *createList() {
    List *list = malloc(sizeof(List));
    list->size = 0;
    list->start = NULL;
    list->end = NULL;
    if (debug) {
        printf("List was created\n");
    }
    return list;
}

/*
 * Add a new Item in the list
 *
 * @param list the List
 * @param data the data which will be saved in the list item
 * @param type_data is the type of the saved data.
 */
void add(List *list, void *data, enum types type_data) {

    Node *new_node = malloc(sizeof(Node));
    //new_node->data = malloc(sizeof(void *));
    new_node->data = data;
    new_node->type_data = type_data;

    if (list->start == NULL) {
        list->start = new_node;
        new_node->next = NULL;
        new_node->before = NULL;
    } else {
        list->end->next = new_node;
        new_node->before = list->end;
        new_node->next = NULL;
    }
    if (debug) {
        printf("Node was added to List with value ");
        printNodeData(new_node);
    }
    list->end = new_node;
    list->size++;

}

/* Connect the node before and after the specified node.
 *
 * Be careful with this function because of memory leaks.
 * @param list List item
 * @param node The node which lies in the middle
 */
void linkNodes(List *list, Node *node) {
    if (list->start == node) {
        list->start = node->next;
    } else if (list->end == node) {
        list->end = node->before;
    } else {
        node->before = node->next;
    }
}

/*
 * Remove the list item by position
 *
 * @param list the List
 * @param position the position of the item in the list
 */
void removeNode(List *list, int position) {
    Node *temp = list->start;
    for (int i = 1; i < position; ++i) {
        temp = temp->next;
    }

    linkNodes(list, temp);
    if (temp->type_data == STRUCT) {
        free(temp->data);
    }
    free(temp);
    list->size--;
    if (list->size == 0) {
        list->start = NULL;
        list->end = NULL;
    }
}

int searchData(List *list, void *data, enum types dataTypes) {
    Node *temp = list->start;
    int position = 0;
    for (int i = 1; i <= list->size; i++) {
        if (temp->type_data == dataTypes) {
            if (temp->type_data == 1 && temp->data == data) {
                break;
            } else if (temp->type_data == 2 && strcmp(temp->data, data) == 0) {
                break;
            } else if (temp->type_data == 3 && temp->data == data) {
                break;
            } else {
                return -1;
            }
        }
        position++;
        temp = temp->next;
    }
    return position;
}

/*
 * Print the value of the list element
 *
 * @param node the list item
 */
void printNodeData(Node *node) {
    if (node == NULL) {
        return;
    }
    switch (node->type_data) {
        case 1:
            printf("%d\n", *(int *) node->data);
            break;
        case 2:
            printf("%s\n", (char *) node->data);
            break;
        case 3:
            printf("%f\n", *(float *) node->data);
            break;
        default:
            printf("(not supported Datatype)\n");
    }
}

Node *getNode(int position, List *list) {
    Node *temp = list->start;
    if (position == 0) {
        return temp;
    }
    for (int i = 0; i < position; i++) {
        temp = temp->next;
    }

    return temp;
}

void deleteList(List *list) {
    while (list->size >= 1) {
        removeNode(list, 0);
    }
    free(list);
}

