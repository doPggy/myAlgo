#include <stdio.h>
#include <stdlib.h>

void dump_array(int *array, int len)
{
    for(int i = 0; i < len; i++)
    {
        printf("[%d] = %d\n", i + 1, array[i]);
    }
}

void bubble_sort(int *wait_sort, int len)
{
    int i        = 0;
    int j        = 0;
    char is_swap = 0; // 数据是否交换的记录

    // 4 5 6 3 2 1
    for(i = 0; i < len - 1; i++)
    {
        is_swap = 0;
        for(j = 0; j < len - 1 - i; j++)
        {
            if(wait_sort[j] > wait_sort[j + 1])
            {
                wait_sort[j]     = wait_sort[j] + wait_sort[j + 1];
                wait_sort[j + 1] = wait_sort[j] - wait_sort[j + 1];
                wait_sort[j]     = wait_sort[j] - wait_sort[j + 1];
                is_swap = 1;
            }
        }
        
        if(!is_swap)
        {
            break;
        }
    }
}

void insert_sort(int *wait_sort, int len)
{
    int i = 0;
    int j = 0;
    int t = 0;

    // 4 5 6 3 2 1
    // 分为有序区和无序区
    for(i = 1; i < len; i++)
    {
        t = wait_sort[i];
        for(j = i - 1; j >= 0; j--)
        {
            if(wait_sort[j] > t)
            {
                wait_sort[j + 1] = wait_sort[j];
            }
            else
            {
                break;
            }
        }
        wait_sort[j + 1] = t; 
    }
}


void select_sort(int *wait_sort, int len)
{
    int i = 0;
    int j = 0;
    int min_index = 0;

    // 4 5 6 3 2 1
    for(i = 0; i < len; i++)
    {
        min_index = i;
        for(j = i; j < len; j++)
        {
            if(wait_sort[j] < wait_sort[min_index])
            {
                min_index = j;
            }
        }
        if(i == min_index) continue;

        wait_sort[i]         = wait_sort[i] + wait_sort[min_index];
        wait_sort[min_index] = wait_sort[i] - wait_sort[min_index];
        wait_sort[i]         = wait_sort[i] - wait_sort[min_index];
    }
}

void test_insert_sort()
{
    int b[20] = {4, 7, 8, 6, 2, 1};
    insert_sort(b, 6);
    dump_array(b, 6);
}

void test_bubble_sort()
{
    int a[20] = {4, 5, 6, 3, 2, 1};
    bubble_sort(a, 6);
    dump_array(a, 6);
}

void test_select_sort()
{
    int a[20] = {44, 5, 6, 3, 2, 1};
    select_sort(a, 6);
    dump_array(a, 6);
}


int main()
{
    test_insert_sort();
    test_bubble_sort();
    test_select_sort();

    return 0;
}