/*************************************************************************
  > File Name: 9_4.cpp
  > Author: lianlian
  > Created Time: 2016年09月07日 星期三 11时49分21秒
  > Description: 
 ************************************************************************/
#include <iostream>
#include <vector>
typedef std::vector<int>::iterator iters;
bool func(iters &iter1, iters &iter2, int number)
{
	while(iter1 != iter2)
	{
		if(number == *iter1++)
			return true;
	}
	return false;
}
iters func2(iters &iter1, iters &iter2, int number)
{
	while(iter1 != iter2)
	{
		if(number == *iter1++)
			return iter1;
	}
	std::cerr << "can't find the number" << std::endl;
	return iter1;
}
int main(int argc, char *argv[])
{
	std::vector<int> iVec {7,8,9,10,11};
	iters iter1 = iVec.begin();
	iters iter2 = iVec.end();
	std::cout << func(iter1,iter2,2) << std::flush;
	return 0;
}
