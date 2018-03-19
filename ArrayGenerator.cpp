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
    delete[] array;
    cout << endl
         << "Objeto Deletado" << endl;
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

    //R1
    for (int i = 0; i < 3333; i++)
        for (int j = 0; j < 3333; j++)
            int aux = (i * j);

    double ck1 = (double)((clock() - init) * 1000) / CLOCKS_PER_SEC;
    clocker = (int)((clock() - ck1) + 500000) / 100;

    //R2
    for (int i = 0; i < clocker; i++)
        for (int j = 0; j < 3333; j++)
            int aux = (i * j) - (i * j);

    double ck2 = (double)((clock() - init) * 1000) / CLOCKS_PER_SEC;
    clocker += (ck1 * ck1);

    return rand() % multply(clocker, 10000);
    // return rand() % (ck0 - ck1 + 1) + ck1;
}

int ArrayGenerator::getSize(void)
{
    return size;
}

void ArrayGenerator::getArray(void)
{
    for (int i = 0; i < size; i++)
    {
        cout << endl << i << " - " << array[i] << endl;
    }
}

void ArrayGenerator::outFile(std::string str)
{

    str.insert(str.size(), ".txt");

    std::ofstream out(str.c_str());

    out << ">" << size;

    for (int i = 0; i < size; i++)
    {
        out << ":" << array[i];
    }

    out.close();
}