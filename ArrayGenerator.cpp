#include "ArrayGenerator.h"
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <time.h>
#include <string>

using namespace std;

ArrayGenerator::ArrayGenerator(int sz)
{
    size = sz;
    array = new int[size];
    rndArray();
}

ArrayGenerator::~ArrayGenerator(void)
{
    // delete[] array;
}

void ArrayGenerator::rndArray()
{
    for (int i = 0; i < size; i++)
    {
        array[i] = getRndNumber();
    }
}

int ArrayGenerator::multply(int input, int size)
{
    int aux = 0;
    int output = 1;

    while (size > 0)
    {

        aux = input / size;
        input -= aux * size;
        size *= 0.1;

        if (aux != 0)
            output *= aux;
    }

    return output;
}

int ArrayGenerator::getRndNumber()
{

    clock_t init = clock();
    int clocker = 0;

    
    for (int i = 0; i < 1000; i++)
        for (int j = 0; j < 1000; j++)
            int aux = (i * j);

    double ck1 = (double)((clock() - init) * 1000) / CLOCKS_PER_SEC;
    clocker = (int)((clock() - ck1) + rand()) / 100;
    double ck2 = (double)((clock() - init) * 1000) / CLOCKS_PER_SEC;
    clocker += (ck1 * ck1);

    return rand() % multply(clocker, 1000000);
}

int ArrayGenerator::getSize(void)
{
    return size;
}

int* ArrayGenerator::getArray(void)
{
    return array;
}

void ArrayGenerator::printArray(void)
{
    for (int i = 0; i < size; i++)
    {
        cout << endl << i << " - " << array[i] << endl;
    }
}
