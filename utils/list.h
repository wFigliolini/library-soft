#ifndef LIST_H
#define LIST_H

#include<stdlib.h>

typedef struct lNode ListNode;

typedef ListNode* ListPtr;

struct lNode{
    void* data;
    //Comparison functions over lNode.data, returns 0, 1, -1. 1 for greater, 0 for equality, -1 for less 
    int (*comparator)(void*,void*);
    void (*destroyer)(void*);
    ListPtr next;
    ListPtr last;
};

ListPtr ListCreate(void* data, int (*comparator)(void*,void*), void (*destroyer)(void*));
void ListDestroy(ListPtr* list);
void ListInsertBack(ListPtr list, void* data);
void ListDelete(ListPtr* list, void* data);

#endif