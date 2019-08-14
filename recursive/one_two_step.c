# include <stdlib.h>
# include <stdio.h>

int buffer[21] = {0};

// 计算走法数
// 还需要解决重复计算问题。
int calcMoveAmount(int stepN)
{
    // 终止条件
    if (stepN == 0 || stepN == 1) return 1;
    if (stepN == 2) return 2;

    // 减少重复计算
    buffer[stepN - 1] = (buffer[stepN - 1] == 0) ? calcMoveAmount(stepN - 1) : buffer[stepN - 1];
    buffer[stepN - 2] = (buffer[stepN - 2] == 0) ? calcMoveAmount(stepN - 2) : buffer[stepN - 2];
    

    // 1 找边界
    // f(0) = 1, f(1) = 1, f(2) = 2

    // 2 分析关系，公式
    // f(n) = f(n - 1) + f(n - 2)
    // n 台阶的走法等于走一个台阶后的走法，加上走两个台阶的走法
    return buffer[stepN - 1] + buffer[stepN - 2];
}

// 假如这里有 n 个台阶，每次你可以跨 1 个台阶或者 2 个，请问跨 N 个有多少个走法？
// f(n) = ?
int main(int argc, char const *argv[])
{
    int step = 0;
    printf("%d\n", calcMoveAmount(3));
    printf("%d\n", calcMoveAmount(7));
    printf("%d\n", calcMoveAmount(4));
    return 0;
}