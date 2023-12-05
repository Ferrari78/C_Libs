//
// Created by felix on 05.12.2023.
//
#include <stdlib.h>
#include <stdio.h>
#include "LinkedList.h"
#include <string.h>


/*
 * Create a list
 */
List *create_List() {
    List *list = (List *) malloc(sizeof(List));
    list->size = 0;
    list->start = NULL;
    list->end = NULL;
    printf("List was created\n");
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
    Node *new_node = (Node *) malloc(sizeof(Node));
    new_node->data = data;
    new_node->type_data = type_data;
    if (list->start == NULL) {
        list->start = new_node;
        new_node->next = NULL;
        new_node->before = NULL;
    } else {
        new_node->before = list->end;
        list->end->next = new_node;
    }
    printf("Node was added to List with value ");
    printNodeData(new_node);
    list->end = new_node;
    list->size++;

}

void connect(List *list, Node *deletedNode) {
    if (list->start == deletedNode) {
        list->start = deletedNode->next;
    } else if (list->end == deletedNode) {
        list->end = deletedNode->before;
    } else {
        deletedNode->before = deletedNode->next;
    }
}

/*
 * Remove the list item by position
 *
 * @param list the List
 * @param position the position of the item in the list
 */
void remove_Node(List *list, int position) {
    Node *temp = list->start;
    for (int i = 1; i < position; ++i) {
        temp = temp->next;
    }
    connect(list,temp);
    free(temp);
    list->size--;
}

int searchData(List *list,void* data, enum types dataTypes){
    Node *temp = list->start;
    int position= 0;
    for (int i = 1; i <= list->size; i++) {
        if(temp->type_data == dataTypes){
            if(temp->type_data == 1 && temp->data == data){
                position = i;
                break;
            }else if(temp->type_data == 2 && strcmp(temp->data,data) == 0){
                position = i;
                break;
            }else if(temp->type_data == 3 && temp->data == data){
                position = i;
                break;
            }
        }
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
    switch (node->type_data) {
        case 1:
            printf("%d\n", node->data);
            break;
        case 2:
            printf("%s\n", node->data);
            break;
        case 3:
            printf("%f\n", node->data);
            break;
        default:
            printf("(not supported Datatype)\n");
    }
}
