#include <bits/stdc++.h>
using namespace std;

class test
{
    private:
        int testItem;
    public:
        test(int n)
        {
            testItem = n;
        }

        int getItem(){
            return testItem;
        }
};

int main()
{
    test objArray[4] = {test(1), test(2), test(3), test(4)};

    test *ptrObj;
    ptrObj = &objArray[1];


    cout << ptrObj->getItem();

    return 0;
}