#ifndef TREE_H
#define TREE_H

#include<stdlib.h>

typedef struct tNode TreeNode;

typedef TreeNode* TreePtr;

TreePtr TreeCreate(void* data, int (*comparator)(void*,void*));
void TreeDestroy(TreePtr tree);
void TreeInsert(TreePtr tree, void* data);
void TreeDelete(TreePtr tree, void* data);

#endif