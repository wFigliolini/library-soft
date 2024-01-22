#include <assert.h>
#include <stdlib.h>

#include"list.h"

int runTests();
int runListTests();
ListPtr CreateIntList(int IntValue);
int IntComparator(void* int1, void* int2);
int* getIntVal(ListPtr list,  int index);
void IntListInsert(ListPtr list, int IntValue);

int main(int argc, char* argv[]){
    return runTests();
}

int runTests(){
    int result = 0;
    result = result || runListTests();
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
        ListPtr SecondNode = ListGetNode(TestList1,1);
        ListDestroy(&TestList1);
        assert(SecondNode == NULL);
    }

    {   //Test for deletion, Case 1: Head of List
        int testVal1 = 1; int testVal2 = 2; int testVal3 = 3;
        int result1; int result2; int result3;
        ListPtr TestList1 = CreateIntList(testVal1);
        IntListInsert(TestList1, testVal2);
        IntListInsert(TestList1, testVal3);
        ListDelete(&TestList1, &testVal1);
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
        ListDelete(&TestList1, &testVal3);
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
        ListDelete(&TestList1, &testVal2);
        result1 = *(getIntVal(TestList1,0));
        result2 = *(getIntVal(TestList1,1));
        assert(result1 == testVal1);
        assert(result2 == testVal3);
        assert(getIntVal(TestList1, 2) == NULL);
        ListDestroy(&TestList1);
    }

    return 0;
}
int IntComparator(void* int1, void* int2){
    return ((*(int*)int1) -(*(int*)int2));
}


ListPtr CreateIntList(int IntValue){
    void* IntStorage = malloc(sizeof(int));
    *(int*)IntStorage = IntValue;
    return ListCreate(IntStorage, IntComparator, free);
}

int* getIntVal(ListPtr list, int index){
    void* tempholder = ListGet(list, index);
    return (int*) tempholder;
}

void IntListInsert(ListPtr list, int IntValue){
    void* IntStorage = malloc(sizeof(int));
    *(int*)IntStorage = IntValue;
    ListInsertBack(list, IntStorage);
}