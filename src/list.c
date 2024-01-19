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
    curr->destroyer(curr->data);
    if(curr->next!= NULL){
        ListDestroy(&(curr->next));
    }
    free(*list);
    *list = NULL;
    return;
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
    if(curr->comparator(curr->data, data) == 0){
        ListPtr* OldHead = list;
        if(curr->next != NULL){
            curr->next->last = curr->last;
            curr->next = NULL;
        }
        if (curr->last != NULL) {
            curr->last->next = curr->next;
            curr->last = NULL;
        }
        else if(curr->last == NULL){ //Curr is head of list
            list = &(curr->next);
        }
        ListDestroy(OldHead);
    }
    else{
        if(curr->next != NULL){
            ListDelete(&(curr->next), data);
        }
    }
    return;
}

void* ListGet(ListPtr list,int index){
    if(index == 0){
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