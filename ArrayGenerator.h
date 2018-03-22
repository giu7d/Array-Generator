#ifndef ArrayGenerator_H
#define ArrayGenerator_H

#include <string>

class ArrayGenerator
{
  private:
    int *array;
    int size;
    void rndArray(); 
    int multply(int input, int size);
    int getRndNumber(); 

  public:
    ArrayGenerator(int sz);
    ~ArrayGenerator();
    void printArray();
    int getSize();
    int* getArray();
};

#endif