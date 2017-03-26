#include <vector>
#include <iostream>
using namespace std;
vector<int>* newVector ()
{
    vector<int> *pVec = new vector<int>;
    return pVec;
}
vector<int>* writeVector(vector<int> *pVec)
{
    int i = 0;
    while (cin >> i)
    {
        pVec->push_back(i);
    }
    return pVec;
}
void print(vector<int> *pVec)
{
    for(auto iter : *pVec)
    {
        cout << iter << endl;
    }
    delete pVec;
    return;
}
int main(int argc, char *argv[]) {
    print(writeVector(newVector()));
    return 0;

}
