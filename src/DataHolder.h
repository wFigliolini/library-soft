#ifndef DATAHOLDER_H
#define DATAHOLDER_H

typedef struct datastruct DataHolder;

typedef DataHolder* DataPtr;

DataPtr CreateData(void* data, int (*comparator)(void*,void*), void (*destroyer)(void*));
void    DestroyData(DataPtr* data);
int     CompareData(DataPtr left, DataPtr right);
void*   GetData(DataPtr data);
#endif