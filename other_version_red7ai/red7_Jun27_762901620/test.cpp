#include <iostream>
#include <list>

using namespace std;

int main()
{
    list<int> test;
    for (int i = 0; i < 10; i++) {
        test.push_back(i);
    }


    list<int>::iterator it, it2, it3;
    for (it3 = test.begin(); it3 != test.end(); it3 ++) {
        cout<<*it3<<" ";
    }

    cout << endl;
    cout << endl;

    it = test.begin();
    it2 = test.begin();
    for (int i = 0; i < 10; i++) {
        if (i < 2)
            it ++;
        if (i < 3)
            it2 ++;

    }

    cout << *it << " " << *it2 << endl;

    test.erase(it);
    test.erase(it2);

    for (it3 = test.begin(); it3 != test.end(); it3++) {
        cout<<*it3<<" ";
    }

    cout << endl;
    cout << endl;

    it--;
    it2--;

    it++;
    it2++;

    test.insert(it2, 5);
    test.insert(it, 2);
    

    for (it3 = test.begin(); it3 != test.end(); it3++) {
        cout<<*it3<<" ";
    }

    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;

    list<int> test1;
    for (int i = 0; i < 10; i++) {
        test1.push_back(i);
    }
    list<int> test2;
    test2 = test1;
    it = test1.begin();
    test1.erase(it);

    for (it3 = test2.begin(); it3 != test2.end(); it3++) {
        cout<<*it3<<" ";
    }

    for (it3 = test1.begin(); it3 != test1.end(); it3++) {
        cout<<*it3<<" ";
    }



    return 0;
}