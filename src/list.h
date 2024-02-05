#ifndef LIST_H
#define LIST_H

#include<stdlib.h>

#include "DataHolder.h"

typedef struct lNode ListNode;

typedef ListNode* ListPtr;



ListPtr ListCreate(DataPtr data);
void ListDestroy(ListPtr* list);
void ListInsert(ListPtr list, DataPtr data);
void ListDelete(ListPtr* list, DataPtr data);

void* ListGet(ListPtr list,int index);
ListPtr ListGetNode(ListPtr list,int index);
void* ListFind(ListPtr list,DataPtr data);

void ListPush(ListPtr* list, void* data);
void* ListPop(ListPtr* list);


#endif