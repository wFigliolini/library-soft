#include "utils.h"

struct lNode{
    void* data;
    ListPtr next;
    ListPtr last;
};

struct tNode{
    void* data;
    TreePtr leaves[2];
};

ListPtr ListCreate(void* data){
    ListPtr out = (ListPtr) malloc(sizeof(ListNode));
    out->data = data;
    out->next = NULL;
    out->last = NULL;
    return out;
}
void ListInsert(ListPtr list, void* data){
    if(list->next ==NULL){
        list->next = ListCreate(data);
        list->next->last = list;
    }
    else {
        ListInsert(list->next, data);
    }
}
void ListDelete(ListPtr list, void* data){
    return;
}

TreePtr TreeCreate(void* data){
    TreePtr out = (TreePtr) malloc(sizeof(TreeNode));
    out->data = data;
    out->leaves[0] = NULL;
    out->leaves[1] = NULL;
    return out;
}
void TreeInsert(TreePtr list, void* data){
    return;
}
void TreeDelete(TreePtr list, void* data){
    return;
}
