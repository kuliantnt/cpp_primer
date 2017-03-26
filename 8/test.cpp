/*************************************************************************
  > File Name: test.cpp
  > Author: lianlian
  > Created Time: 2016年08月31日 星期三 16时23分06秒
  > Description: 
 ************************************************************************/
#include <iostream>
class Solution {
	public:
		int addDigits(int num) {
			unsigned int temp = 0,sum = 0;
			while(num >= 10)
			{
				sum = 0;
				temp = num / 10000;
				num -= temp * 10000;
				sum += temp;

				temp = num / 1000;
				num -= temp * 1000;
				sum += temp;

				temp = num / 100;
				num -= temp * 100;
				sum += temp;

				temp = num / 10;
				num -= temp * 10;
				sum += temp;

				num += sum;
			}
			return num;
		}
};
int main(int argc,char *argv[])
{
	Solution sol;
	for(int i = 0 ; i != 100 ; i++)
	std::cout << "i = " << i << "\tsoult = " << sol.addDigits(i) << std::endl;
}
