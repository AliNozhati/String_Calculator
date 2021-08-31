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
    
    string st1 = "13400200134"; // n digits
    string st2 = "123"; // 9 digits

    string a3 = a1+a2;
    string a4 = a1-a2;
    string a5 = a1*a2;
    string st3 = st1/st2;
    string st4 = st1%st2;
    
    cout << "\nstr1: " << a1 << "\nstr2: " << a2
         << "\n\nsum: " << a3 << "\nsub: " << a4 << "\nmulty: " << a5 
         << "\n\n-----------------------------" 
         << "\nstr1: " << st1 << "\nstr2: " << st2
         << "\n\ndivit: " << st3 
         << "\nmode: " << st4
         << "\n-----------------------------\n\n";
  

    ///////////////////////////////////////////////////////////////////////////////////////

    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout << chrono::duration <double, milli> (diff).count() << " ms" << endl;
    cout << chrono::duration <double, nano> (diff).count() << " ns" << endl << endl;

    system ("pause");
    return 0;
}
