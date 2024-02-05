#include "tree.h"


void AVLTreeInsert(TreeNodePtr* tree, void* data);
void AVLTreeDelete(TreeNodePtr* tree, void* data);

struct TreeHandler{
    void (*insertMethod)(TreeNodePtr*, void*);
    void (*deleteMethod)(TreeNodePtr*, void*);
    TreeNodePtr tree;
};



TreePtr TreeCreate( void (*insertMethod)(TreeNodePtr*, void*), void deleteMethod(TreeNodePtr*, void*)){
    TreePtr out = (TreePtr) malloc(sizeof(Tree));

    if(out != NULL){
        out->insertMethod = insertMethod;
        out->deleteMethod = deleteMethod;
        out->tree = NULL;
    }
    return out;
}

TreeNodePtr TreeNodeCreate( DataPtr data){
    TreeNodePtr out = (TreeNodePtr) malloc(sizeof(TreeNode));

    if(out != NULL){
        out->data = data;
        out->leaves[0] = NULL;
        out->leaves[1] = NULL;
        out->balanceFactor = 0;
    }
    return out;
}

void TreeDestroy(TreePtr* tree){

    TreePtr curr = *tree;

    if( curr == NULL ) return;

    TreeNodeDestroy(&(curr->tree));

    free(tree);
}


void TreeNodeDestroy(TreeNodePtr* treeNode){
    TreeNodePtr curr = *treeNode;

    if(curr == NULL) return;

    if( curr->data != NULL){
        DataDestroy(&(curr->data));
    }

    TreeNodeDestroy(&(curr->leaves[0]));
    TreeNodeDestroy(&(curr->leaves[1]));

}

void TreeInsert(TreePtr tree, DataPtr data){
    if(tree == NULL) return;
    tree->insertMethod(&(tree->tree), data);
}
void TreeDelete(TreePtr tree, DataPtr data){
    if(tree == NULL) return;
    tree->deleteMethod(&(tree->tree), data);
}

void* TreeNodeFind(TreeNodePtr tree, DataPtr data){
    if( tree == NULL ) return NULL;

    int result = DataCompare(tree->data, data);

    if( result == -2 ) return NULL;

    if(result < 0){
        return TreeNodeFind(tree->leaves[0], data);
    }
    else if(result > 0){
        return TreeNodeFind(tree->leaves[1], data);
    }
    else {
        return data;
    }
}
void* TreeFind(TreePtr tree, DataPtr data){

    if(tree == NULL)return NULL;

    return TreeNodeFind(tree->tree, data);
}


TreePtr TreeAVLCreate(){
    return TreeCreate(AVLTreeInsert, AVLTreeDelete);
}

void AVLTreeInsert(TreeNodePtr* tree, void* data){
    TreeNodePtr curr = *tree;
    
}
void AVLTreeDelete(TreeNodePtr* tree, void* data){
    TreeNodePtr curr = *tree;
}