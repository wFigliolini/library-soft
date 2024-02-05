#ifndef TREE_H
#define TREE_H

#include<stdlib.h>

#include "DataHolder.h"
#include "list.h"

typedef struct TreeHandler Tree;
typedef Tree* TreePtr;

typedef struct tNode TreeNode;
typedef TreeNode* TreeNodePtr;

struct tNode{
    DataPtr data;
    TreeNodePtr leaves[2];
    short balanceFactor;
};


TreePtr TreeCreate(void insertMethod(TreeNodePtr*, DataPtr), void deleteMethod(TreeNodePtr*, DataPtr));
void TreeDestroy(TreePtr* tree);
void TreeNodeDestroy(TreeNodePtr* treeNode);
void TreeInsert(TreePtr tree, DataPtr data);
void TreeDelete(TreePtr tree, DataPtr data);
DataPtr TreeFind(TreePtr tree, DataPtr data);

TreePtr TreeAVLCreate();


#endif