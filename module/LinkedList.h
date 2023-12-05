//
// Created by felix on 05.12.2023.
//

#ifndef LINKEDLIST_LINKEDLIST_H
#define LINKEDLIST_LINKEDLIST_H

enum types {
    INT = 1,
    STRING,
    FLOAT
};

typedef struct node {
    void *data;
    enum types type_data;
    struct node *next;
    struct node *before;
} Node;

typedef struct list {
    struct node *start;
    struct node *end;
    int size;
} List;


List *create_List();

void add(List *list, void *data, enum types type_data);

void printNodeData(Node *node);

void remove_Node(List *list, int position);

int searchData(List *list,void* data, enum types dataTypes);

#endif //LINKEDLIST_LINKEDLIST_H
