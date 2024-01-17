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
    {   //Test for basic creation and destruction
        int TestVal1 = 1;
        ListPtr TestList1 = CreateIntList(TestVal1);
        assert(getIntVal(TestList1) == TestVal1);
        ListDestroy(&TestList1);
        assert(TestList1 == NULL);
    }
    {   //Test for insertion and non-basic Destroy cases
        int testVal1 = 1; int testVal2 = 2;
        ListPtr TestList1 = CreateIntList(testVal1);
        ListInsertBack(TestList1, &testVal2);
        assert(getIntVal(TestList1) == testVal1);
        assert(getIntVal(TestList1->next) == testVal2);
        assert(TestList1->next->next == NULL);
        ListPtr SecondNode = TestList1->next;
        ListDestroy(&TestList1);
        assert(SecondNode == NULL);
    }

    {   //Test for deletion, Case 1: Head of List
        int testVal1 = 1; int testVal2 = 2; int testVal3 = 3;
        ListPtr TestList1 = CreateIntList(testVal1);
        ListInsertBack(TestList1, &testVal2);
        ListInsertBack(TestList1, &testVal3);
        ListDelete(&TestList1, &testVal1);
        assert(getIntVal(TestList1) == testVal2);
        assert(getIntVal(TestList1->next) == testVal3);
        ListDestroy(&TestList1);
    }
    {   //Test for deletion, Case 2: Tail of List
        int testVal1 = 1; int testVal2 = 2; int testVal3 = 3;
        ListPtr TestList1 = CreateIntList(testVal1);
        ListInsertBack(TestList1, &testVal2);
        ListInsertBack(TestList1, &testVal3);
        ListDelete(&TestList1, &testVal3);
        assert(getIntVal(TestList1) == testVal1);
        assert(getIntVal(TestList1->next) == testVal2);
        assert(TestList1->next->next == NULL);
        ListDestroy(&TestList1);
    }
    {   //Test for deletion, Case 3: Center of List
        int testVal1 = 1; int testVal2 = 2; int testVal3 = 3;
        ListPtr TestList1 = CreateIntList(testVal1);
        ListInsertBack(TestList1, &testVal2);
        ListInsertBack(TestList1, &testVal3);
        ListDelete(&TestList1, &testVal2);
        assert(getIntVal(TestList1) == testVal1);
        assert(getIntVal(TestList1->next) == testVal3);
        ListDestroy(&TestList1);
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
    void* tempholder = list->data;
    return *(int*) tempholder;
}