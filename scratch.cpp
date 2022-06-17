#include <bits/stdc++.h>
using namespace std;

class returnClass
{
    private:
        string item1, item2;
        int item3;
    public:
        returnClass()
        {
            item1 = "This is item 1";
            item2 = "This is item 2";
            item3 = 10;
        }

        void print()
        {
            cout << "Item1 = " << item1 << endl;
            cout << "Item2 = " << item2 << endl;
            cout << "Item3 = " << item3 << endl;
        }
};

class test
{
    private:
        int testItem;
        returnClass* returnClassObj;
    public:
        test(int n)
        {
            testItem = n;
        }

        int getItem()
        {
            return testItem;
        }

        void setReturnClass(returnClass obj)
        {
            returnClassObj = &obj;
        }

        returnClass* getReturnClass()
        {
            return returnClassObj;
        }
};

int main()
{
    test objTestArray[4] = {test(1), test(2), test(3), test(4)}; // create array of "test" class

    test *ptrObj;
    ptrObj = &objTestArray[1];                      // create pointer that points to 2nd element in test class array

    returnClass objReturn[2];                       // create array of returnClass class

    objTestArray[0].setReturnClass(objReturn[0]);   // the returnClass pointer in test class to 1st element in objReturn array

    objTestArray[0].getReturnClass()->print();      // prints  objReturn[0] using print() method

    cout << ptrObj->getItem() << endl;              // using the pointer to 2nd element in objTestArray, get the item variable and output to console

    system("PAUSE");

    return 0;
}