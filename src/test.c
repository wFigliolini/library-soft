#include <assert.h>
#include <stdlib.h>

#include"DataHolder.h"
#include"list.h"

int runTests();
int runDataHolderTests();
int runListTests();

DataPtr CreateIntData(int IntValue);
ListPtr CreateIntList(int IntValue);
int IntComparator(void* int1, void* int2);
int* getIntVal(ListPtr list,  int index);
void IntListInsert(ListPtr list, int IntValue);
void IntListDelete(ListPtr* list, int IntValue);

int main(int argc, char* argv[]){
    return runTests();
}

int runTests(){
    int result = 0;
    result = result || runListTests();
    return 0;
}

int runDataHolderTests(){

    return 0;
}

int runListTests(){
    {   //Test for basic creation and destruction
        int TestVal1 = 1;
        int result1;
        ListPtr TestList1 = CreateIntList(TestVal1);
        result1 = *(getIntVal(TestList1,0));
        assert(result1 == TestVal1);
        ListDestroy(&TestList1);
        assert(TestList1 == NULL);
    }
    {   //Test for insertion and non-basic Destroy cases
        int testVal1 = 1; int testVal2 = 2;
        int result1; int result2;
        ListPtr TestList1 = CreateIntList(testVal1);
        IntListInsert(TestList1, testVal2);
        result1 = *(getIntVal(TestList1,0));
        result2 = *(getIntVal(TestList1,1));
        assert(result1 == testVal1);
        assert(result2 == testVal2);
        assert(getIntVal(TestList1, 2) == NULL);
        ListDestroy(&TestList1);
    }

    {   //Test for deletion, Case 1: Head of List
        int testVal1 = 1; int testVal2 = 2; int testVal3 = 3;
        int result1; int result2; int result3;
        ListPtr TestList1 = CreateIntList(testVal1);
        IntListInsert(TestList1, testVal2);
        IntListInsert(TestList1, testVal3);
        IntListDelete(&TestList1, testVal1);
        result1 = *(getIntVal(TestList1,0));
        result2 = *(getIntVal(TestList1,1));
        assert(result1 == testVal2);
        assert(result2 == testVal3);
        assert(getIntVal(TestList1, 2) == NULL);
        ListDestroy(&TestList1);
    }
    {   //Test for deletion, Case 2: Tail of List
        int testVal1 = 1; int testVal2 = 2; int testVal3 = 3;
        int result1; int result2; int result3;
        ListPtr TestList1 = CreateIntList(testVal1);
        IntListInsert(TestList1, testVal2);
        IntListInsert(TestList1, testVal3);
        IntListDelete(&TestList1, testVal3);
        result1 = *(getIntVal(TestList1,0));
        result2 = *(getIntVal(TestList1,1));
        assert(result1 == testVal1);
        assert(result2 == testVal2);
        assert(getIntVal(TestList1, 2) == NULL);
        ListDestroy(&TestList1);
    }
    {   //Test for deletion, Case 3: Center of List
        int testVal1 = 1; int testVal2 = 2; int testVal3 = 3;
        int result1; int result2; int result3;
        ListPtr TestList1 = CreateIntList(testVal1);
        IntListInsert(TestList1, testVal2);
        IntListInsert(TestList1, testVal3);
        IntListDelete(&TestList1, testVal2);
        result1 = *(getIntVal(TestList1,0));
        result2 = *(getIntVal(TestList1,1));
        assert(result1 == testVal1);
        assert(result2 == testVal3);
        assert(getIntVal(TestList1, 2) == NULL);
        ListDestroy(&TestList1);
    }
    {   //Test for deletion, Case 4: Deletion of Value that is not in list
        int testVal1 = 1; int testVal2 = 2; int testVal3 = 3;
        int result1; int result2; int result3;
        ListPtr TestList1 = CreateIntList(testVal1);
        IntListInsert(TestList1, testVal2);
        IntListInsert(TestList1, testVal3);
        IntListDelete(&TestList1, 4);
        result1 = *(getIntVal(TestList1,0));
        result2 = *(getIntVal(TestList1,1));
        result3 = *(getIntVal(TestList1,2));
        assert(result1 == testVal1);
        assert(result2 == testVal2);
        assert(result3 == testVal3);
        assert(getIntVal(TestList1, 3) == NULL);
        ListDestroy(&TestList1);
    }

    return 0;
}
int IntComparator(void* int1, void* int2){
    return ((*(int*)int1) -(*(int*)int2));
}

DataPtr CreateIntData(int IntValue){
    void* IntStorage = malloc(sizeof(int));
    *(int*)IntStorage = IntValue;
    return DataCreate(IntStorage, IntComparator, free);
}

ListPtr CreateIntList(int IntValue){
    DataPtr IntStorage = CreateIntData(IntValue); 
    return ListCreate(IntStorage);
}

int* getIntVal(ListPtr list, int index){
    DataPtr tempholder = ListGet(list, index);
    void* result = DataGet(tempholder);
    return (int*) result;
}

void IntListInsert(ListPtr list, int IntValue){
    DataPtr IntStorage = CreateIntData(IntValue);
    ListInsert(list, IntStorage);
}

void IntListDelete(ListPtr* list, int IntValue){
    DataPtr IntStorage = CreateIntData(IntValue);
    ListDelete(list, IntStorage);
    DataDestroy(&IntStorage);
}