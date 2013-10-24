#include "unique_ptr.h"
#include <iostream>
#include <memory>

using namespace std;

int main()
{
    my::unique_ptr<int> p1;
    int *a = new int;
    my::unique_ptr<int> p2(a);// = new my::unique_ptr<int> (a);
    *a = 5;
    my::unique_ptr<int> p3(move(p2));
//    delete p2;
    int *b = new int;
    *b = 10;
    {
        my::unique_ptr<int> p4(b);
        if (p4.get() != NULL)
            cout << "No NULL " << *p4 << endl;
        else cout << "fuck!!!" << endl;
        p1 = move(p4);
        if (p4.get() != NULL)
            cout << "No NULL " << *p4 << endl;
        else cout << "fuck!!!" << endl;
    }
    if (p1.get() != NULL)
        cout << "No NULL " << *p1 << endl;
    else cout << "fuck!!!" << endl;
//    delete a;
//    delete b;
    return 0;
}
