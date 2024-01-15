#ifndef LIST_H
#define LIST_H

#include<stdlib.h>

typedef struct lNode ListNode;

typedef ListNode* ListPtr;

ListPtr ListCreate(void* data, int (*comparator)(void*,void*), void (*destroyer)(void*));
void ListDestroy(ListPtr list);
void ListInsert(ListPtr list, void* data);
void ListDelete(ListPtr list, void* data);
void* ListGetVal(ListPtr list);

#endif