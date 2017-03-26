/*************************************************************************
 > File Name: 8_4.cpp
 > Author: lianlian
 > Created Time: 2016年08月31日 星期三 14时47分39秒
 > Description: 
 ************************************************************************/
#include <fstream>
#include <string>
#include <vector>
#include <iostream>
int main(int argc, char *argv[])
{
	std::vector<std::string> strvec;
	std::string str;
	std::ifstream input(argv[1]);
	while(getline(input,str))
	{
		strvec.push_back(str);
	}
	for(auto iter : strvec)
	{
		std::cout << iter << std::endl;
	}
	return 0;
}
