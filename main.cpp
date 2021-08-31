// Made by Ali Nozhati on 2021/8/31

#include <iostream>
#include <string.h>
#include <vector>
#include "strcalculator.cpp"
#include <chrono>
using namespace std;

int main()
{
    auto start = chrono::steady_clock::now();

    ///////////////////////////////////////////////////////////////////////////////////////

    string a1 = "-999912399134213421121341344343434991349";
    string a2 = "999999913499";
    const char* st = "13400200134"; // n digits
    const char* st2 = "123"; // 9 digits

    string a3 = sumstri(a1.c_str(),a2.c_str());
    string a4 = minstri(a1.c_str(),a2.c_str());
    string a5 = multistri(a1.c_str(),a2.c_str());
    
    cout << "\nstr1: " << a1 << "\nstr2: " << a2
         << "\n\nsum: " << a3 << "\nsub: " << a4 << "\nmulty: " << a5 
         << "\n\n-----------------------------" 
         << "\nstr1: " << st << "\nstr2: " << st2
         << "\n\ndivit: " << divitstri(st, st2) 
         << "\nmode: " << modestri(st,st2) 
         << "\n-----------------------------\n\n";
  

    ///////////////////////////////////////////////////////////////////////////////////////

    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout << chrono::duration <double, milli> (diff).count() << " ms" << endl;
    cout << chrono::duration <double, nano> (diff).count() << " ns" << endl << endl;

    system ("pause");
    return 0;
}