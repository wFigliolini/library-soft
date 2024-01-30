#ifndef DATAHOLDER_H
#define DATAHOLDER_H

typedef struct datastruct DataHolder;

typedef DataHolder* DataPtr;

DataPtr DataCreate(void* data, int (*comparator)(void*,void*), void (*destroyer)(void*));
void    DataDestroy(DataPtr* data);
int     DataCompare(DataPtr left, DataPtr right);
void*   DataGet(DataPtr data);
#endif