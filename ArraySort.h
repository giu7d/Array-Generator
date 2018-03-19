#ifndef ArraySort_H
#define ArraySort_H

class ArraySort
{
  private:
    int *array;
    int size;

  public:
    ArraySort(int *a, int s);
    ~ArraySort();
    int* bubbleSort();
    int* insertSort();
    void printArray();
    int *getArray();
    int getSize();
};

#endif