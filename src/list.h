#ifndef LIST_H
#define LIST_H

#include<stdlib.h>

#include "DataHolder.h"

typedef struct lNode ListNode;
typedef struct lHandler ListHandler;

typedef ListNode* ListNodePtr;
typedef ListHandler* ListPtr;



ListPtr ListCreate();
void ListDestroy(ListPtr* list);
void ListInsert(ListPtr list, DataPtr data, int index);
void ListAppend(ListPtr list, DataPtr data);
void ListDelete(ListPtr list, DataPtr data);

DataPtr ListGet(ListPtr list,int index);
DataPtr ListFind(ListPtr list,DataPtr data);

void ListPush(ListPtr list, DataPtr data);
DataPtr ListPop(ListPtr list);


#endif