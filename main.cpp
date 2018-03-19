#include <iostream>
#include <fstream>
#include <string>

#include "ArrayGenerator.h"
#include "ArrayReader.h"
#include "ArraySort.h"

using namespace std;

//Import file function
std::string getMemorieString(std::string str)
{
    std::string str_mem;
    streampos size;
    char *memblock;

    str.insert(str.size(), ".txt");

    ifstream file(str.c_str(), ios::in | ios::binary | ios::ate);

    if (file.is_open())
    {
        size = file.tellg();
        memblock = new char[size];

        file.seekg(0, ios::beg);
        file.read(memblock, size);
        file.close();

        str_mem = memblock;

        delete[] memblock;

        return str_mem;
    }

    else
        return NULL;
}


int main()
{
    std::string file;
    cin >> file;

    std::string str_array = getMemorieString(file);

    ArrayReader reader(str_array);
    ArraySort array_sort(reader.getArray(), reader.getSize());

    int *ar = new int[array_sort.getSize()];
    ar = array_sort.insertSort();

    cout << "Fora de Ordem:" << endl;
    reader.printArray();

    cout << "Bubble Sort:" << endl;
    
    for(int i = 0; i < array_sort.getSize(); i++){
        cout << ar[i] << endl;
    }

    // cout << endl << arr[0] << endl;
    // cout << arr[1] << endl;
    // cout << arr[2] << endl;

    // ArraySort b(arr, reader.getSize());
    
    // cout << "Fora de Ordem:" << endl;
    // b.printArray();
    // b.insertSort();
    // cout << "Insert Sort:" << endl;
    // b.printArray();

    delete[] ar;

    return 0;
}