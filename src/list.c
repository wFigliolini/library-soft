#include "list.h"
#include "DataHolder.h"

struct lNode{
    DataPtr data;
    ListPtr next;
    ListPtr last;
};

void ListIsolate(ListPtr list){
    list->next = NULL;
    list->last = NULL;
}

ListPtr ListCreate(DataPtr data){
    ListPtr out = (ListPtr) malloc(sizeof(ListNode));

    if(out != NULL){
        out->data = data;
        out->next = NULL;
        out->last = NULL;
    }
    return out;
}
void ListDestroy(ListPtr* list){
    ListPtr curr = *list;

    if(curr == NULL) return;

    ListPtr* next = &(curr->next);
    DataDestroy(&(curr->data));
    ListDestroy(next);
    free(*list);
    *list = NULL;
}
void ListInsert(ListPtr list, DataPtr data){
    if(list->next ==NULL){
        list->next = ListCreate(data);
        list->next->last = list;
    }
    else {
        ListInsert(list->next, data);
    }
    return;
}
void ListDelete(ListPtr* list, DataPtr data){
    ListPtr curr = *list;
    if(curr == NULL) return; //Found end of list case
    if(DataCompare(curr->data,data) == 0){ //Found data
        *list = curr->next;
        if (curr->next != NULL) curr->next->last = *list;
        ListIsolate(curr); 
        ListDestroy(&curr);
        return;
    }
    ListDelete(&(curr->next), data); //Continue down the list
}

DataPtr ListGet(ListPtr list,int index){
    if(index == 0){
        if(list == NULL) return NULL;
        return list->data;
    }
    else{
        if(list->next ==NULL) return NULL;
        return ListGet(list->next, index-1);
    }
}

DataPtr ListFind(ListPtr list,DataPtr data){
    if(DataCompare(list->data, data) == 0){
        return list->data;
    }
    else{
        if(list->next == NULL) return NULL;
        return ListFind(list->next, data);
    }
}

void ListPush(ListPtr* list, DataPtr data){
    ListPtr OldTop = *list;
    ListPtr NewTop = ListCreate(data);
    NewTop->next = OldTop;
    OldTop->last = NewTop;
    *list = NewTop;
}
DataPtr ListPop(ListPtr* list){
    ListPtr curr = *list;
    DataPtr output = curr->data;
    *list = curr->next;
    ListIsolate(curr);
    curr->data = NULL;
    ListDestroy(&curr);
    return output;
}