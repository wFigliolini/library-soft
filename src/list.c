#include "list.h"

struct lNode{
    void* data;
    //Comparison functions over lNode.data, returns 0, 1, -1. 1 for greater, 0 for equality, -1 for less 
    int (*comparator)(void*,void*);
    void (*destroyer)(void*);
    ListPtr next;
    ListPtr last;
};

ListPtr ListCreate(void* data, int (*comparator)(void*,void*), void (*destroyer)(void*)){
    ListPtr out = (ListPtr) malloc(sizeof(ListNode));

    if(out != NULL){
        out->data = data;
        out->comparator = comparator;
        out->destroyer = destroyer;
        out->next = NULL;
        out->last = NULL;
    }
    return out;
}
void ListDestroy(ListPtr* list){
    ListPtr curr = *list;

    if(curr == NULL) return;

    ListPtr* next = &(curr->next);
    curr->destroyer(curr->data);
    curr->data = NULL;
    curr->comparator = NULL;
    curr->destroyer = NULL;
    curr->last = NULL;
    curr->next = NULL;
    free(*list);
    *list = NULL;
    ListDestroy(next);
}
void ListInsertBack(ListPtr list, void* data){
    if(list->next ==NULL){
        list->next = ListCreate(data, list->comparator, list->destroyer);
        list->next->last = list;
    }
    else {
        ListInsertBack(list->next, data);
    }
    return;
}
void ListDelete(ListPtr* list, void* data){
    ListPtr curr = *list;
    if(curr == NULL) return; //Found end of list case
    if(curr->comparator(curr->data, data) == 0){ //Found data
        *list = curr->next;
        if (curr->next != NULL) curr->next->last = *list;
        curr->next = NULL;
        curr->last = NULL;
        ListDestroy(&curr);
        return;
    }
    ListDelete(&(curr->next), data); //Continue down the list
}

void* ListGet(ListPtr list,int index){
    if(index == 0){
        if(list == NULL) return NULL;
        return list->data;
    }
    else{
        if(list->next ==NULL) return NULL;
        return ListGet(list->next, index-1);
    }
}

ListPtr ListGetNode(ListPtr list,int index){
    if(index == 0){
        return list;
    }
    else{
        if(list->next ==NULL) return NULL;
        return ListGetNode(list->next, index-1);
    }
}

void* ListFind(ListPtr list,void* data){
    if(list->comparator(list->data, data) == 0){
        return list->data;
    }
    else{
        if(list->next == NULL) return NULL;
        return ListFind(list->next, data);
    }
}

void ListPush(ListPtr* list, void* data){
    ListPtr curr = *list;
    ListPtr NewTop = ListCreate(data, curr->comparator, curr->destroyer);
}
void* ListPop(ListPtr* list);