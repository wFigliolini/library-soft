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
void ListDestroy(ListPtr list){
    list->destroyer(list->data);
    if(list->next!= NULL){
        ListDestroy(list->next);
    }
    free(list);
}
void ListInsert(ListPtr list, void* data){
    if(list->next ==NULL){
        list->next = ListCreate(data, list->comparator);
        list->next->last = list;
    }
    else {
        ListInsert(list->next, data);
    }
    return;
}
void ListDelete(ListPtr list, void* data){
    if(list->comparator(list->data, data) == 0){
        ListPtr curr = list;
        if(curr->next != NULL){
            curr->next->last = curr->last;
            curr->next = NULL;
        }
        if (curr->last != NULL) {
            curr->last->next = curr->next;
            curr->last = NULL;
        }
        else if(curr->last == NULL){ //Curr is head of list
            list = curr->next;
        }
        ListDestroy(curr);
    }
    else{
        if(list->next != NULL){
            ListDelete(list->next, data);
        }
    }
    return;
}