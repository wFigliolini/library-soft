#include "list.h"

struct lNode{
    void* data;
    //Comparison functions over lNode.data, returns 0, 1, -1. 1 for greater, 0 for equality, -1 for less 
    int (*comparator)(void*,void*);
    ListPtr next;
    ListPtr last;
};


ListPtr ListCreate(void* data, int (*comparator)(void*,void*)){
    ListPtr out = (ListPtr) malloc(sizeof(ListNode));

    if(out != NULL){
        out->data = data;
        out->comparator = comparator;
        out->next = NULL;
        out->last = NULL;
    }
    return out;
}
void ListDestroy(ListPtr list){
    free(list->data);
    
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
        //point the adjacent list nodes to eachother
        list->last->next = list->next;
        list->next->last = list->last;
        //isolate the current node
        list->next = NULL;
        list->last = NULL;
        ListDestroy(list);
    }
    else{
        ListDelete(list->next, data);
    }
    return;
}