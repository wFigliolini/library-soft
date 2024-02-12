#include "list.h"
#include "DataHolder.h"

struct lNode{
    DataPtr data;
    ListNodePtr next;
    ListNodePtr last;
};

struct lHandler{
    ListNodePtr list;
    unsigned int size;
};

void ListNodeIsolate(ListNodePtr list){
    list->next = NULL;
    list->last = NULL;
}

ListPtr ListCreate(){
    ListPtr out = (ListPtr) malloc(sizeof(ListHandler));

    if(out != NULL){
        out->list = NULL;
        out->size = 0;
    }
    return out;
}

ListNodePtr ListNodeCreate(DataPtr data){
    ListNodePtr out = (ListNodePtr) malloc(sizeof(ListNode));

    if(out != NULL){
        out->data = data;
        out->next = NULL;
        out->last = NULL;
    }
    return out;
}

void ListNodeDestroy(ListNodePtr* list){
    ListNodePtr curr = *list;

    if(curr == NULL) return;

    ListNodePtr* next = &(curr->next);
    DataDestroy(&(curr->data));
    ListNodeDestroy(next);
    free(*list);
    *list = NULL;
}

void ListDestroy(ListPtr* list){
    ListPtr curr = *list;
    ListNodeDestroy(&(curr->list));
    free(*list);
    *list = NULL;
}

void ListNodeInsert(ListNodePtr* list, DataPtr data, int index){
    ListNodePtr curr = *list; ListNodePtr newNode;

    if(curr == NULL){
        *list = ListNodeCreate(data);
        return;
    }
    else if( index == 0){//middle of list case
        newNode = ListNodeCreate(data);
        newNode->next = curr;
        newNode->last = curr->last;
        curr->last = newNode;
        *list = newNode;
        return;
    }
    else if(curr->next == NULL){ // end of list case
        curr->next = ListNodeCreate(data);
        curr->next->last = curr;
        return;
    }
    ListNodeInsert((&curr->next), data, index-1);
}

void ListInsert(ListPtr list, DataPtr data, int index){
    ListNodeInsert(&(list->list), data, index);
    list->size++;
}

void ListAppend(ListPtr list, DataPtr data){
    ListNodeInsert(&(list->list), data, list->size);
    list->size++;
}

void ListNodeDelete(ListNodePtr* list, DataPtr data){
    ListNodePtr curr = *list;
    if(curr == NULL) return; //Found end of list case
    if(DataCompare(curr->data,data) == 0){ //Found data
        *list = curr->next;
        if (curr->next != NULL) curr->next->last = *list;
        ListNodeIsolate(curr); 
        ListNodeDestroy(&curr);
        return;
    }
    ListNodeDelete(&(curr->next), data); //Continue down the list
}

void ListDelete(ListPtr list, DataPtr data){
    ListNodeDelete(&(list->list), data);
    list->size--;
}

DataPtr ListNodeGet(ListNodePtr list, int index){
    if(index == 0){
        if(list == NULL) return NULL;
        return list->data;
    }
    if(list->next ==NULL) return NULL;
    return ListNodeGet(list->next, index-1);

}

DataPtr ListGet(ListPtr list,int index){
    return ListNodeGet(list->list, index);
}

DataPtr ListNodeFind(ListNodePtr list, DataPtr data){
    if(DataCompare(list->data, data) == 0){
        return list->data;
    }
    if(list->next == NULL) return NULL;
    return ListNodeFind(list->next, data);

}

DataPtr ListFind(ListPtr list,DataPtr data){
    return ListNodeFind(list->list, data);
}

void ListPush(ListPtr list, DataPtr data){
    ListNodeInsert(&(list->list), data, 0);
}
DataPtr ListPop(ListPtr list){
    DataPtr output = ListNodeGet(list->list, 0);
    ListNodePtr curr = list->list;
    list->list = curr->next;
    ListNodeIsolate(curr);
    curr->data = NULL;
    ListNodeDestroy(&curr);
    return output;
}