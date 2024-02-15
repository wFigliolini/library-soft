#include "DataHolder.h"
#include <stdlib.h>

struct datastruct{
    void* data;
   
    int (*comparator)(void*,void*);
    void (*destroyer)(void*);
};

DataPtr DataCreate(void* data, int (*comparator)(void*,void*), void (*destroyer)(void*)){
    DataPtr out = malloc(sizeof(DataHolder));
    if(out != NULL){
        out->data = data;
        out->comparator = comparator;
        out->destroyer = destroyer;
    }
    return out;
}
void DataDestroy(DataPtr* data){
    DataPtr curr = *data;
    if( curr == NULL) return;
    curr->destroyer(curr->data);
    curr->data = NULL;
    curr->comparator = NULL;
    curr->destroyer = NULL;
    free(curr);
    *data = NULL;
}

int DataCompare(DataPtr left, DataPtr right){
    if(left->comparator != right->comparator || left->comparator == NULL) return -2;
    
    int result = left->comparator(left->data, right->data); 

    if( result > 0){
        return 1;
    }
    if( result < 0){
        return -1;
    }
    return 0;
}
void* DataGet(DataPtr data){
    if(data == NULL) return NULL;
    return data->data;
}

int NullComparator(void* left, void* right){
    return -2;
}
void NullDestroyer(void* data){
    return;
}
