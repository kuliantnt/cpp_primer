#include "Token.h"
#include<stdio.h>
void main()
{
    int i, j, n;
    std::cin >> n;

    for (i = 1; i <= n; ++i)  // ���ƽ������Ĳ�
    {
        for (j = 0; j != n - i + 1; ++j)  // ���ƽ�����ÿ��ǰ������Ŀո���
            printf(" ");
        for (j = 0; j != 2 * i - 1; ++j) // ���ƽ�����ÿ����Ҫ��ӡi�ĸ���
            printf("%d", i);
        printf("\n");  // һ������������ϣ����м��������һ��
    }
    system("pause");
}
