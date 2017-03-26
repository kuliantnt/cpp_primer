#include <iostream>
#include <vector>
#include <list>

using namespace std;
int main(int argc, char* argv[])
{
    list<int> lis {1,2,3,4,5};
    vector<int> vec {1,2,3,4,5};
    cout << boolalpha << (vector<int> (lis.cbegin(),lis.cend()) == vec) << endl;
    cin.get();
    return 0;
}
