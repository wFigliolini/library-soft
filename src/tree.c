#include "tree.h"

struct tNode{
    void* data;
    //Comparison functions over tNode.data, returns 0, 1, -1. 1 for greater, 0 for equality, -1 for less 
    int (*comparator)(void*,void*);
    TreePtr leaves[2];
    int balanceFactor;
};

TreePtr TreeCreate(void* data, int (*comparator)(void*,void*)){
    TreePtr out = (TreePtr) malloc(sizeof(TreeNode));

    if(out != NULL){
        out->data = data;
        out->comparator = comparator;
        out->leaves[0] = NULL;
        out->leaves[1] = NULL;
        out->balanceFactor = 0;
    }
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
