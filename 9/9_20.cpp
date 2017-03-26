#include <iostream>
#include <deque>
#include <list>

using namespace std;

int main(int argc, char * argv[])
{
    list<int> list1;
    deque<int> deque1,deque2;
    for(int i = 0; i != 10; i++)
    {
        list1.push_back(i);
    }
    for(auto ix : list1)
    {
        if(ix % 2 == 0)
            deque2.push_back(ix);
        else
            deque1.push_back(ix);
    }
    for(auto ix : deque1)
        cout << ix << endl;
    for(auto ix : deque2)
        cout << ix << endl;
    return 0;
}