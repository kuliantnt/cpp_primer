/*************************************************************************
 > File Name: 8_9.cpp
 > Author: lianlian
 > Created Time: 2016年09月06日 星期二 08时57分21秒
 > Description: 
 ************************************************************************/
#include <iostream>
#include <sstream>
std::istream& input(std::istream &isstrm)
{
	std::string buf;
	while(isstrm >> buf)
		std::cout << buf << std::endl;
	isstrm.clear();
	return isstrm;
}
int main(int argc, char *argv[])
{
	std::istringstream iss("nihao");
	input(iss);
	return 0;

}
