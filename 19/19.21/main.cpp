#include "Token.h"
#include<stdio.h>
void main()
{
    int i, j, n;
    std::cin >> n;

    for (i = 1; i <= n; ++i)  // 控制金字塔的层
    {
        for (j = 0; j != n - i + 1; ++j)  // 控制金字塔每层前面输出的空格数
            printf(" ");
        for (j = 0; j != 2 * i - 1; ++j) // 控制金字塔每层需要打印i的个数
            printf("%d", i);
        printf("\n");  // 一层金字塔输出完毕，换行继续输出下一层
    }
    system("pause");
}
