#ifndef LIST_H
#define LIST_H

#include<stdlib.h>

typedef struct lNode ListNode;

typedef ListNode* ListPtr;



ListPtr ListCreate(void* data, int (*comparator)(void*,void*), void (*destroyer)(void*));
void ListDestroy(ListPtr* list);
void ListInsertBack(ListPtr list, void* data);
void ListDelete(ListPtr* list, void* data);
void* ListGet(ListPtr list,int index);
ListPtr ListGetNode(ListPtr list,int index);
void* ListFind(ListPtr list,void* data);

#endif