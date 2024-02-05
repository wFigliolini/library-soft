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

DataPtr ListGet(ListPtr list,int index);
DataPtr ListFind(ListPtr list,DataPtr data);

void ListPush(ListPtr* list, DataPtr data);
DataPtr ListPop(ListPtr* list);


#endif