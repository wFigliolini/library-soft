#ifndef UTILS_H
#define UTILS_H
#include<stdlib.h>

typedef struct lNode ListNode;

typedef ListNode* ListPtr;

ListPtr ListCreate(void* data);
void ListInsert(ListPtr list, void* data);
void ListDelete(ListPtr list, void* data);

typedef struct tNode TreeNode;

typedef TreeNode* TreePtr;

TreePtr TreeCreate(void* data);
void TreeInsert(TreePtr list, void* data);
void TreeDelete(TreePtr list, void* data);

#endif