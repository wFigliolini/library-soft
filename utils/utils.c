#include "utils.h"

struct lNode{
    void* data;
    //Comparison functions over lNode.data, returns 0, 1, -1. 1 for greater, 0 for equality, -1 for less 
    int (*comparator)(void*,void*);
    ListPtr next;
    ListPtr last;
};

struct tNode{
    void* data;
    //Comparison functions over tNode.data, returns 0, 1, -1. 1 for greater, 0 for equality, -1 for less 
    int (*comparator)(void*,void*);
    TreePtr leaves[2];
    int balanceFactor;
};

ListPtr ListCreate(void* data, int (*comparator)(void*,void*)){
    ListPtr out = (ListPtr) malloc(sizeof(ListNode));
    out->data = data;
    out->comparator = comparator;
    out->next = NULL;
    out->last = NULL;
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

TreePtr TreeCreate(void* data, int (*comparator)(void*,void*)){
    TreePtr out = (TreePtr) malloc(sizeof(TreeNode));
    out->data = data;
    out->comparator = comparator;
    out->leaves[0] = NULL;
    out->leaves[1] = NULL;
    out->balanceFactor = 0;
    return out;
}
void TreeDestroy(TreePtr tree){
    if( tree->data != NULL){
        free(tree->data);
    }
    TreeDestroy(tree->leaves[0]);
    TreeDestroy(tree->leaves[1]);
}

void TreeInsert(TreePtr tree, void* data){
    return;
}
void TreeDelete(TreePtr tree, void* data){
    return;
}
