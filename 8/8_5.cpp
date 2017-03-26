/*************************************************************************
  > File Name: 8_5.cpp
  > Author: lianlian
  > Created Time: 2016年09月01日 星期四 08时40分02秒
  > Description: 
 ************************************************************************/
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
void readFileToVec(std::ifstream &ifs, std::vector<std::string> &strVec);
int main(int argc, char *argv[])
{
	std::ifstream ifs (argv[1]);
	int i = 1; //计数器
	std::vector<std::string> strVec;
	readFileToVec(ifs,strVec);
	for(auto iter : strVec)
	{
		std::cout << iter << "\t";
		++i;
		if(i == 4)
		{
			std::cout << std::endl;
			i == 1;
		}
	}
}
void readFileToVec(std::ifstream &ifs, std::vector<std::string> &strVec)
{
	std::string str;
	if(ifs)
	{
		while(ifs >> str )
		{
			strVec.push_back(str);
		}
	}
	else
		std::cerr << "No Files" << std::endl;
}
