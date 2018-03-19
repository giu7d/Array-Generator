#ifndef ArrayGenerator_H
#define ArrayGenerator_H

#include <string>

class ArrayGenerator
{
  private:
    int *array;
    int size;
    int getRndNumber(); //Rnd Number
    void rndArray();    //Rnd Array
    int multply(int input, int size);
    //int sum(int input, int size);

  public:
    ArrayGenerator(int sz);
    ~ArrayGenerator();
    int getSize();
    void getArray();
    void outFile(std::string fileName);
};

#endif