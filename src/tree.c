#include "tree.h"
#include "DataHolder.h"
#include "list.h"


void AVLTreeInsert(TreeNodePtr* tree, DataPtr data);
void AVLTreeDelete(TreeNodePtr* tree, DataPtr data);

struct TreeHandler{
    void (*insertMethod)(TreeNodePtr*, DataPtr);
    void (*deleteMethod)(TreeNodePtr*, DataPtr);
    TreeNodePtr tree;
};



TreePtr TreeCreate( void (*insertMethod)(TreeNodePtr*, DataPtr), void deleteMethod(TreeNodePtr*, DataPtr)){
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

    free(*tree);
    *tree = NULL;
}


void TreeNodeDestroy(TreeNodePtr* treeNode){
    TreeNodePtr curr = *treeNode;

    if(curr == NULL) return;

    if( curr->data != NULL){
        DataDestroy(&(curr->data));
    }

    TreeNodeDestroy(&(curr->leaves[0]));
    TreeNodeDestroy(&(curr->leaves[1]));

    free(*treeNode);
    *treeNode = NULL;
}

void TreeInsert(TreePtr tree, DataPtr data){
    if(tree == NULL) return;
    tree->insertMethod(&(tree->tree), data);
}
void TreeDelete(TreePtr tree, DataPtr data){
    if(tree == NULL) return;
    tree->deleteMethod(&(tree->tree), data);
}

DataPtr TreeNodeFind(TreeNodePtr tree, DataPtr data){
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
DataPtr TreeFind(TreePtr tree, DataPtr data){

    if(tree == NULL)return NULL;

    return TreeNodeFind(tree->tree, data);
}


TreePtr TreeAVLCreate(){
    return TreeCreate(AVLTreeInsert, AVLTreeDelete);
}

void RotateRight(TreeNodePtr* parent, TreeNodePtr rightLeaf){
    TreeNodePtr currentParent = *parent; 
    TreeNodePtr RIghtofRightLeaf =rightLeaf->leaves[1];

    currentParent->leaves[0] = RIghtofRightLeaf;
    rightLeaf->leaves[1] = currentParent;
    *parent = rightLeaf;

        //Balance factor Operations
    if(rightLeaf->balanceFactor == 0){
        rightLeaf->balanceFactor= 1;
        currentParent->balanceFactor = -1;

    }else{
        rightLeaf->balanceFactor= 0;
        currentParent->balanceFactor = 0;
    }
}

void RotateLeft(TreeNodePtr* parent, TreeNodePtr leftLeaf){
    TreeNodePtr currentParent = *parent; 
    TreeNodePtr LeftofLeftLeaf = leftLeaf->leaves[0];
    //Swap operations
    currentParent->leaves[1] = LeftofLeftLeaf;
    leftLeaf->leaves[0] = currentParent;
    *parent = leftLeaf;

    //Balance factor Operations
    if(leftLeaf->balanceFactor == 0){
        leftLeaf->balanceFactor= -1;
        currentParent->balanceFactor = 1;

    }else{
        leftLeaf->balanceFactor= 0;
        currentParent->balanceFactor = 0;
    }
}


void AVLTreeInsert(TreeNodePtr* tree, DataPtr data){
    TreeNodePtr curr = *tree;
    ListPtr TraceStack = ListCreate();

    if(curr == NULL){
        *tree = TreeNodeCreate(data);
        return;
    }

    //TODO: Refactor to handle modularity of Dataptrs
    //      1) stack support in equality case
    while(curr!=NULL){
        ListPush(TraceStack, DataCreate(curr, NullComparator,NullDestroyer));
        if(DataCompare(curr->data, data) > 0){
            curr->balanceFactor = curr->balanceFactor-1;
            curr = curr->leaves[0];
        }
        else if (DataCompare(curr->data, data)) {
            curr->balanceFactor = curr->balanceFactor+1;
            curr = curr->leaves[1];
        }
        else{ 
            //Already in tree case. 
            return;
        }
    }
    curr = TreeNodeCreate(data);




}
void AVLTreeDelete(TreeNodePtr* tree, DataPtr data){
    TreeNodePtr curr = *tree;
    if( curr == NULL ) return;

}

