/*************************************************************************
 > File Name: 9_14.cpp
 > Author: lianlian
 > Created Time: 2016年09月09日 星期五 14时58分22秒
 > Description: 
 ************************************************************************/
#include <iostream>
#include <vector>
#include <list>
using namespace std;
int main(int argc, char *argv[])
{
	list<const char*> clist = {"int char", "test2 ", "using name"};
	vector<string> strVec;
	strVec.assign(clist.begin(),clist.end());
	for(auto str : strVec)
	{
		cout << str << endl;
	}
	return 0;
}
