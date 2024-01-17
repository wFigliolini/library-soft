#include <assert.h>
#include <stdlib.h>

#include"utils/list.h"

int runTests();
int runListTests();
ListPtr CreateIntList(int IntValue);
int IntComparator(void* int1, void* int2);
int getIntVal(ListPtr list);

int main(int argc, char* argv[]){
    return runTests();
}

int runTests(){
    runListTests();
    return 0;
}

int runListTests(){
    {
    int TestVal1 = 1;
    ListPtr TestList1 = CreateIntList(TestVal1);
    assert(getIntVal(TestList1) == TestVal1);
    ListDestroy(&TestList1);
    assert(TestList1 == NULL);
    }
    return 0;
}
int IntComparator(void* int1, void* int2){
    return ((*(int*)int1) -(*(int*)int2));
}


ListPtr CreateIntList(int IntValue){
    void* dereferencedInt = malloc(sizeof(int));
    dereferencedInt = &IntValue;
    return ListCreate(dereferencedInt, IntComparator, free);
}

int getIntVal(ListPtr list){
    void* tempholder = ListGetVal(list);
    return *(int*) tempholder;
}