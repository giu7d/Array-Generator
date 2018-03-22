#include <iostream>
#include <fstream>
#include <string>

#include "ArrayGenerator.h"
#include "ArraySort.h"

using namespace std;

void outFile(int *array, int size, std::string file_name, std::string file_ext)
{

    file_name.insert(file_name.size(), file_ext.c_str());

    std::ofstream out(file_name.c_str());

    out << ">" << size;

    for (int i = 0; i < size; i++)
    {
        out << ":" << array[i];
    }

    out.close();
}

int main()
{
    int file_size;
    std::string file_name;
    std::string file_ext;
    
    cout << "Nome do Arquivo: " << endl;
    cin >> file_name;
    cout << "Tamanho do Arquivo: " << endl;
    cin >> file_size;
    

    ArrayGenerator gen(file_size);
    ArraySort sort(gen.getArray(),gen.getSize());

    //RND
    file_ext = "_rnd.txt";
    outFile(gen.getArray(), gen.getSize(), file_name, file_ext);
    cout << endl << "Gerado ./" << file_name << file_ext << endl; 

    //ORD
    file_ext = "_ord.txt";
    sort.shellSort();
    outFile(sort.getArray(), sort.getSize(), file_name, file_ext);
    cout << endl << "Gerado ./" << file_name << file_ext << endl;     
    
    //INV
    file_ext = "_inv.txt";
    sort.reverseArray();
    outFile(sort.getArray(), sort.getSize(), file_name, file_ext);
    cout << endl << "Gerado ./" << file_name << file_ext << endl;

    return 0;
}