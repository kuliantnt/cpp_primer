/*************************************************************************
  > File Name: 8_1.cpp
  > Author: lianlian
  > Created Time: 2016年08月31日 星期三 09时00分24秒
  > Description: 
 ************************************************************************/
#include <iostream>
using std::istream;
istream& func(istream& is)
{
	std::string buf;
	while(is >> buf)
	{
		std::cout << buf << std::endl;
		is.clear();
		return is;
	}
	
}
int main(int argc,char* argv[])
{
	istream& is = func(std::cin);
	std::cout << is.rdstate() << std::endl;
	return 0;
}
