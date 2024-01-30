#include "tree.h"


void AVLTreeInsert(TreePtr* tree, void* data);
void AVLTreeDelete(TreePtr* tree, void* data);

struct tNode{
    void* data;
    //Comparison functions over tNode.data, returns 0, 1, -1. 1 for greater, 0 for equality, -1 for less 
    int (*comparator)(void*,void*);
    void (*insertMethod)(TreePtr*, void*);
    void (*deleteMethod)(TreePtr*, void*);
    void (*destroyer)(void*);
    TreePtr leaves[2];
    int balanceFactor;
};

TreePtr TreeCreate(DataPtr data,
                    void (*insertMethod)(TreePtr*, void*), void deleteMethod(TreePtr*, void*)){
    TreePtr out = (TreePtr) malloc(sizeof(TreeNode));

    if(out != NULL){
        out->data = data;
        out->insertMethod = insertMethod;
        out->deleteMethod = deleteMethod;
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

void TreeInsert(TreePtr* tree, DataPtr data){
    (*tree)->insertMethod(tree, data);
}
void TreeDelete(TreePtr* tree, DataPtr data){
    (*tree)->deleteMethod(tree, data);
}
void* TreeFind(TreePtr tree, DataPtr data){

    if(tree == NULL)return NULL;

    int result = DataCompare(tree->data, data);

    if( result == -2 ) return NULL;

    if(result < 0){
        return TreeFind(tree->leaves[0], data);
    }
    else if(result > 0){
        return TreeFind(tree->leaves[1], data);
    }
    else {
        return data;
    }
}

TreePtr TreeAVLCreate(DataPtr data){
    return TreeCreate(data, AVLTreeInsert, AVLTreeDelete);
}

void AVLTreeInsert(TreePtr* tree, void* data){
    TreePtr curr = *tree;
    
}
void AVLTreeDelete(TreePtr* tree, void* data){
    TreePtr curr = *tree;
}