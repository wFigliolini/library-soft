#include "DataHolder.h"
#include <stdlib.h>

struct datastruct{
    void* data;
    //Comparison functions over data, returns 0, 1, -1. 1 for greater, 0 for equality, -1 for less. -2 is used for type mismatch
    int (*comparator)(void*,void*);
    void (*destroyer)(void*);
};

DataPtr CreateData(void* data, int (*comparator)(void*,void*), void (*destroyer)(void*)){
    DataPtr out = malloc(sizeof(DataHolder));
    if(out != NULL){
        out->data = data;
        out->comparator = comparator;
        out->destroyer = destroyer;
    }
    return out;
}
void DestroyData(DataPtr* data){
    DataPtr curr = *data;
    curr->destroyer(curr->data);
    free(*data);
}

int CompareData(DataPtr left, DataPtr right){
    if(left->comparator != right->comparator) return -2;
    
    int result = left->comparator(left->data, right->data); 

    if( result > 0){
        return 1;
    }
    if( result < 0){
        return -1;
    }
    return 0;
}
void* GetData(DataPtr data){
    return data->data;
}