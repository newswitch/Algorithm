#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <time.h>
using namespace std;

template <typename T>
void quicksort(T s[], int l, int r)
{
    if (l < r)
    {
        // Swap(s[l], s[(l + r) / 2]); //将中间的这个数和第一个数交换 参见注1
        int i = l, j = r, x = s[l];
        while (i < j)
        {
            while (i < j && s[j] >= x) // 从右向左找第一个小于x的数
                j--;
            if (i < j)
                s[i] = s[j];

            while (i < j && s[i] < x) // 从左向右找第一个大于等于x的数
                i++;
            if (i < j)
                s[j] = s[i];
        }
        s[i] = x;
        quicksort(s, l, i - 1); // 递归调用
        quicksort(s, i + 1, r);
    }
}

void PrintArray(int array[], int len)
{
    for (int i = 0; i < len; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

int main(void)
{
    const int NUM = 10;
    int array[NUM] = {0};
    srand((unsigned int)time(nullptr));
    for (int i = 0; i < NUM; i++)
    {
        array[i] = rand() % 100 + 1;
    }
    cout << "排序前：" << endl;
    PrintArray(array, NUM);
    cout << "排序后：" << endl;
    quicksort(array, 0, NUM - 1);
    cout << "check" << endl;
    PrintArray(array, NUM);

    return 0;
}