#ifndef DATAHOLDER_H
#define DATAHOLDER_H

typedef struct datastruct DataHolder;

typedef DataHolder* DataPtr;

DataPtr DataCreate(void* data, int (*comparator)(void*,void*), void (*destroyer)(void*));
void    DataDestroy(DataPtr* data);
 //Comparison functions over data, returns 0, 1, -1. 1 for left is greater than right, 0 for equality, -1 for lesser. -2 is used for type mismatch
int     DataCompare(DataPtr left, DataPtr right);
void*   DataGet(DataPtr data);
#endif