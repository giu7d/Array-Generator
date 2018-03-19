#include "ArraySort.h"
#include <iostream>

using namespace std;

ArraySort::ArraySort(int *a, int s)
{
    size = s;
    array = new int[size];
    array = a;
}

ArraySort::~ArraySort()
{
    delete[] array;
}

void ArraySort::printArray()
{
    for (int i = 0; i < size; ++i)
        cout << array[i] << endl;
}

int* ArraySort::bubbleSort()
{
    bool swapped = true;
    int j = 0;
    int tmp;

    while (swapped)
    {
        swapped = false;
        j++;
        for (int i = 0; i < size - j; ++i)
        {
            if (array[i] > array[i + 1])
            {
                tmp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = tmp;
                swapped = true;
            }
        }
    }

    return array;
}

int* ArraySort::insertSort()
{
    int j;
    int tmp;

    for (int i = 0; i < size; ++i)
    {
        j = i;
        while (j > 0 && array[j] < array[j - 1])
        {
            tmp = array[j];
            array[j] = array[j - 1];
            array[j - 1] = tmp;
            j--;
        }
    }

    return array;
}

int *ArraySort::getArray()
{
    return array;
}

int ArraySort::getSize()
{
    return size;
}
