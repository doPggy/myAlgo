#include <stdlib.h>
#include <iostream>

// 将两个序列有序合并
void merge(int *a, int begin1, int begin2, int end)
{
    std::cout << end - begin1 + 1 << std::endl;
    std::cout << begin1 << "," << begin2 << "," << end << "," << std::endl;

    int *tmp = new int[end - begin1 + 1];
    int i    = begin1;
    int j    = begin2;
    int tmpK = 0; 

    while(i < begin2 || j <= end)
    {
        if(a[i] <= a[j])
        {
            tmp[tmpK++] = a[i++];
        }
        else
        {
            tmp[tmpK++] = a[j++];
        }
    }

    while(i < begin2) tmp[tmpK++] = a[i++];
    while(j <= end) tmp[tmpK++] = a[j++];

    i = begin1;
    tmpK = 0;
    while(i <= end) 
    {
        a[i++] = tmp[tmpK++];
    }
    delete [] tmp;
}

void mergeCore(int *a, int begin, int end)
{
    if(begin >= end) return;
    int mid = (begin + end) / 2;

    mergeCore(a, begin, mid); // 分解左半边
    mergeCore(a, mid + 1, end);// 分解右半边
    // 4 5 6 3 2
    merge(a, begin, mid + 1, end); // 归并两个序列
}

void mergeSort(int *a, int n)
{
    mergeCore(a, 0, n - 1);
}

int main()
{
    int a[10] = {1, 2, 20, 4, 33, 34, 11};
    mergeSort(a, 7);
    for(int i = 0; i < 7; i++)
    {
        std::cout << "[" << i + 1 << "] = " << a[i] << std::endl;
    }
    return 0;
}
