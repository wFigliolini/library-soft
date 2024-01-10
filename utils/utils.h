#ifndef UTILS_H
#define UTILS_H
#include<stdlib.h>

typedef struct lNode ListNode;

typedef ListNode* ListPtr;

ListPtr ListCreate(void* data, int (*comparator)(void*,void*));
void ListDestroy(ListPtr list);
void ListInsert(ListPtr list, void* data);
void ListDelete(ListPtr list, void* data);

typedef struct tNode TreeNode;

typedef TreeNode* TreePtr;

TreePtr TreeCreate(void* data, int (*comparator)(void*,void*));
void TreeDestroy(TreePtr tree);
void TreeInsert(TreePtr tree, void* data);
void TreeDelete(TreePtr tree, void* data);

#endif