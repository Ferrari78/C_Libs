//
// Created by felix on 05.12.2023.
//

#ifndef LINKEDLIST_LIST_H
#define LINKEDLIST_LIST_H

enum types {
    INT = 1,
    STRING,
    FLOAT,
    STRUCT
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

void removeNode(List *list, int position);

int searchData(List *list,void* data, enum types dataTypes);

void linkNodes(List *list, Node *node);

Node* getNode(int position, List* list);

void deleteList(List* list);

#endif //LINKEDLIST_LIST_H
