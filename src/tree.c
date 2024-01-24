#include "tree.h"

struct tNode{
    void* data;
    //Comparison functions over tNode.data, returns 0, 1, -1. 1 for greater, 0 for equality, -1 for less 
    int (*comparator)(void*,void*);
    void (*insertMethod)(TreePtr*, void*);
    void (*destroyer)(void*);
    TreePtr leaves[2];
    int balanceFactor;
};

TreePtr TreeCreate(void* data, int (*comparator)(void*,void*), void (*insertMethod)(TreePtr*, void*), void (*destroyer)(void*)){
    TreePtr out = (TreePtr) malloc(sizeof(TreeNode));

    if(out != NULL){
        out->data = data;
        out->comparator = comparator;
        out->insertMethod = insertMethod;
        out->destroyer = destroyer;
        out->leaves[0] = NULL;
        out->leaves[1] = NULL;
        out->balanceFactor = 0;
    }
    return out;
}
void TreeDestroy(TreePtr* tree){

    TreePtr curr = *tree;

    if( curr == NULL ) return;

    if( curr->data != NULL){
        curr->destroyer(curr->data);
    }


    TreeDestroy(&(curr->leaves[0]));
    TreeDestroy(&(curr->leaves[1]));
}

void TreeInsert(TreePtr* tree, void* data){
    (*tree)->insertMethod(tree, data);
}
void TreeDelete(TreePtr tree, void* data){
    return;
}
void* TreeFind(TreePtr tree, void* data){

    if(tree == NULL)return NULL;

    if(tree->comparator(tree->data, data) < 0){
        return TreeFind(tree->leaves[0], data);
    }
    else if(tree->comparator(tree->data, data) > 0){
        return TreeFind(tree->leaves[1], data);
    }
    else {
        return data;
    }
}
