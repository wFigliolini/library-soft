#ifndef TREE_H
#define TREE_H

#include<stdlib.h>

#include "DataHolder.h"

typedef struct tNode TreeNode;

typedef TreeNode* TreePtr;

TreePtr TreeCreate(DataPtr data,
                    void insertMethod(TreePtr*, void*), void deleteMethod(TreePtr*, void*));
void TreeDestroy(TreePtr* tree);
void TreeInsert(TreePtr* tree, DataPtr data);
void TreeDelete(TreePtr* tree, DataPtr data);
void* TreeFind(TreePtr tree, DataPtr data);

TreePtr TreeAVLCreate(DataPtr data);


#endif