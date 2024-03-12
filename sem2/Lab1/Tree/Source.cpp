#include "TreeHead.h" 
FenwickTree::FenwickTree(int n)
{
    if (n < 0)
    {
        std::cout << " Ошибка! Отрицательный размер исходного массива." << "\n";
        exit(0);
    }
    size = n;
    array = std::vector<int>(n, 0);
    PrefixSum = std::vector<int>(n, 0);
}

int FenwickTree::f(int i)
{
    return i & (i + 1);
}

int FenwickTree::g(int i)
{
    return i | (i + 1);
}

void FenwickTree::CreateTree()
{
    for (int i = 0; i < size; i++)
    {
        int sum = 0;
        for (int j = f(i); j <= i; j++)
        {
            sum += array[j];
        }
        PrefixSum[i] = sum;
    }
}
int FenwickTree::Sum(int start, int pos)
{
    int sum_start = 0;
    for (int i = start - 1; i >= 0; i = f(i) - 1)
    {
        sum_start += PrefixSum[i];
    }
    int sum_pos = 0;
    for (int i = pos; i >= 0; i = f(i) - 1)
    {
        sum_pos += PrefixSum[i];
    }
    return sum_pos - sum_start;
}

void FenwickTree::Update(int pos, int value)
{
    for (int i = pos; i < size; i = g(i))
    {
        PrefixSum[i] += value;
    }
}

