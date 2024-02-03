#ifndef TREE_H
#define TREE_H

#include<stdlib.h>

#include "DataHolder.h"

typedef struct TreeHandler Tree;
typedef Tree* TreePtr;

typedef struct tNode TreeNode;
typedef TreeNode* TreeNodePtr;

struct tNode{
    DataPtr data;
    TreeNodePtr leaves[2];
    short balanceFactor;
};


TreePtr TreeCreate(void insertMethod(TreeNodePtr*, void*), void deleteMethod(TreeNodePtr*, void*));
void TreeDestroy(TreePtr* tree);
void TreeNodeDestroy(TreeNodePtr* treeNode);
void TreeInsert(TreePtr tree, DataPtr data);
void TreeDelete(TreePtr tree, DataPtr data);
void* TreeFind(TreePtr tree, DataPtr data);

TreePtr TreeAVLCreate();


#endif