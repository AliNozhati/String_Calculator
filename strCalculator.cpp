// Made by Ali Nozhati on 2021/8/31

#include "strCalculator.h"
#include <string.h>
#include <iostream>
#include <vector>
#include <cmath>

namespace Calculator{

    // Check
    bool checkInt(const char* str)
    {
        int size = strlen(str), i = 0;
        if(str[0] == '-' || str[0] == '+')
            i++;

        for (; i < size; i++)
            if(!isdigit(str[i]))
                return false;
        return true;
    }
    
    // Big, Small
    const char* big(const char* str1, const char* str2)
    {
        int size1 = strlen(str1), size2 = strlen(str2), j1 = 0, j2 = 0;
        if(*str1 == '+' || *str1 == '-') { --size1, j1++; }
        if(*str2 == '+' || *str2 == '-') { --size2, j2++; }

        for(; *(str1+j1) == '0'; j1++)
            size1--;
        for(; *(str2+j2) == '0'; j2++)
            size2--;

        if(size1 > size2) return str1;
        else if(size1 < size2) { return str2; } 
        else
        {
            for (; j1 < size1; j1++,j2++)
            {
                if(*(str1 + j1) > *(str2 + j2)) { return str1; }
                else if(*(str1 + j1) < *(str2 + j2)) { return str2; }
            }    
        }

        return str1; // str1 = str2   
    }

    // Miniaturize
    // 123456789987654321 => a1 = 123456789, a2 = 987654321
    void segmentation(const char* ch, int part, std::vector <std::string>& vect)
    {
        bool flag = false;
        int size = strlen(ch);
        int j = 0;

        if(*ch == '+' || *ch == '-' || *ch == '0') { --size,j++, flag = true; }
        for(; ch[j] == '0'; j++)
            size--;
        int q = size / part;
        int r = size % part;

        std::string str = ch;
        if(flag)
            str = str.substr(j,str.length()-j);

        int n = 0;
        if(r != 0)
            vect.push_back(str.substr(0, r));

        int count = -1;
        while (++count < q)
        {
            n = (count*part) + r;
            vect.push_back(str.substr(n, part));
        }
    }

    void isNegative(const char* str1, const char* str2, bool& flag1, bool& flag2)
    {
        if(*str1 == '-')
            flag1 = false;
        if(*str2 == '-')
            flag2 = false;
    }

    std::string SUM(const char* ch1, const char* ch2)
    {
        int part = 18;
        std::vector <std::string> vect1;
        std::vector <std::string> vect2;

        segmentation(ch1, part, vect1);
        segmentation(ch2, part, vect2);

        long long int a1, a2;
        bool flag = false;

        int i = vect1.size();
        int j = vect2.size();
        int k = j;
        if(j > i)
        {
            k = i;
        }

        std::string str = "", Final = "";

        while (--k >= 0)
        {
            i--;
            j--;
            a1 = atoll(vect1[i].c_str());
            a2 = atoll(vect2[j].c_str());  

            if(flag)
            {
                ++a1;
                flag = false;
            }

            str = std::to_string(a1+a2);
            static int size;
            size = str.length();

            if(size > part)
            {
                flag = true;
                if((i+j) != 0)
                    str = str.substr(1,size-1);
            }
            else if(size < part && (i+j) != 0)
            {
                int s = part - size;
                std::string strr(s, '0');
                str = strr.append(str);
            }
            Final = str.append(Final);
        }

        i = vect1.size() - vect2.size() - 1;
        for(; flag && i >= 0; i--)
        {
            a2 = atoll(vect1[i].c_str());
            ++a2;
            flag = false;
            str = std::to_string(a2);

            static int size2;
            size2 = str.length();
            if(size2 > part && i != 0)
            {
                flag = true;
                str = str.substr(1,size2-1);
            }
            Final = str.append(Final);
        }

        if(i >= 0)
        {
            std::string g = strstr(ch1,vect1[0].c_str());
            int ss = (++i*part) - (part-vect1[0].length());

            g = g.substr(0,ss);
            Final = g.append(Final);
        }
        
        if(!Final.compare(""))
            return "0";
        return Final;
    }

    std::string SUB(const char* ch1, const char* ch2)
    {
        int part = 17;
        std::vector <std::string> vect1;
        std::vector <std::string> vect2;

        segmentation(ch1, part, vect1);
        segmentation(ch2, part, vect2);

        long long int a1, a2, a3;
        bool flag = false;

        int i = vect1.size();
        int j = vect2.size();

        int k = j;
        if(j > i)
        {
            k = i;
        }

        std::string str = "", Final = "";
        long long int POW = pow(10, part); 

        while (--k >= 0)
        {
            i--;
            j--;

            a1 = atoll(vect1[i].c_str());
            a2 = atoll(vect2[j].c_str());  

            if(flag)
            {
                --a1;
                flag = false;
            }

            a3 = a1-a2;
            if(a3 < 0)
            {
                a1 = POW + a1;
                a3 = a1 - a2;
                flag = true;
            }

            std::string st(20, '0');
            str = std::to_string(a3);
            int size = str.length() - part;

            if(size < 0 && k != 0)
            {
                size *= -1;
                str = st.substr(0,size).append(str);
            }
            Final = str.append(Final);
        }

        i = vect1.size() - vect2.size() - 1;
        for(; flag && i >= 0; i--)
        {
            a2 = atoll(vect1[i].c_str());
            --a2;
            flag = false;

            if(a2 < 0)
            {
                a2 = POW - 1;
                flag = true;
            }

            str = std::to_string(a2);
            Final = str.append(Final); 
        }

        if(i >= 0){
            std::string st = strstr(ch1,vect1[0].c_str());
            int size2 = (++i*part) - (part - vect1[0].length());

            st = st.substr(0,size2);
            Final = st.append(Final);
        }
        if(!Final.compare(""))
            return "0";

        return Final; 
    }

    std::string MULTY(const char* ch1, const char* ch2)
    {
        std::string Final = "";
        int part = 9;
        std::vector <std::string> vect1;
        std::vector <std::string> vect2;

        segmentation(ch1, part, vect1);
        segmentation(ch2, part, vect2);

        long long int a1, a2, a3;
        bool flag = false;
    
        int size1 = vect1.size();
        int size2 = vect2.size();

        int k1 = size2;
        int k2 = size1;
        if(size2 > size1)
        {
            k1 = size1;
            k2 = size2;
        }

        std::string str = "";
        int p = 0;
        std::vector <std::string> fin;
        long long int POW = pow(10, part);

        for(int q = 0; q < k1; q++)
        {
            int k3 = k2;
            int i = size1, j;
            std::string st(part*q,'0');
            j = size2 - q - 1;
            p = 0;
            Final = "";

            while (--k3 >= 0)
            {
                i--;

                a1 = atoi(vect1[i].c_str());
                a2 = atoi(vect2[j].c_str());  

                a3 = a2*a1;
                a3 += p;
                if(i != 0)
                {
                    p = a3 / POW;
                    a3 = a3 % POW;
                }

                str = std::to_string(a3);
                static int size;
                size = str.length();

                if(size < part && q != k1-1)
                {
                    int s = part - size;
                    std::string sr(s,'0');
                    str = sr.append(str);
                }

                Final = str.append(Final);
            }

            Final += st;
            fin.push_back(Final);
        }

        int size3 = fin.size();
        std::string finish;

        if(size3 == 1)
            finish = fin[0];
        else if(size3 >= 2)
            finish = SUM(fin[size3 - 1].c_str(), fin[size3 - 2].c_str());

        for(int q = size3 - 3; q >= 0; q--)
            finish = SUM(finish.c_str(), fin[q].c_str());

        if(!finish.compare(""))
            return "0";

        return finish;
    }

    void segmentationDiv(const char* str, int part, std::vector <std::string>& vect)
    {
        bool flag = false;
        int size = strlen(str);
        int j = 0;

        if(*str == '+' || *str == '-' || *str == '0') { --size,j++, flag = true; }
        for(; str[j] == '0'; j++)
            size--;
        int q = size / part;
        int r = size % part;

        std::string st = str;
        int i = (flag) ? j : 0;
        int count = -1;

        while (++count < q)
        {
            j = (count*part) + i;
            vect.push_back(st.substr(j, part));
        }

        if(r != 0)
        {
            j = (count*part) + i;
            part= strlen(str) - j;
            vect.push_back(st.substr(j, part));   
        }
    }

    std::string DIVIT(const char* str1, const char* str2)
    {
        std::vector <std::string> vect1;
        std::vector <std::string> vect2;
        Calculator::segmentationDiv(str1, 10,vect1);
        Calculator::segmentationDiv(str2, 9, vect2);   

        long long int a1, a2, a3, a4;

        int i = vect1.size();

        std::string str = "";
        int zero = 0;
        a2 = atoll(vect2[0].c_str());
        int p = 0;

        for(int c = 0; c < i; c++)
        {
            a1 = atoll(vect1[c].c_str());

            if(vect1[c][0] == '0')
            {
                zero = 0;
                while(vect1[c][++zero] == '0');
            }

            a3 = a1 / a2;
            a4 = a1 % a2;

            static int s = 9;
            static long long int ss = 0;

            if(ss != 0 && c != 0)
            {
                if((c+1) == i && s > vect1[c].length())
                {
                    s = vect1[c].length() + 1;
                    ss = 0;
                }
                else{
                    ss = atoll(vect1[c].substr(zero, s).c_str());   
                }

                zero += s;
                if((ss % a2) == 0)
                    zero--;
                p = 0;            
            }

            if(zero != 0 && c != 0)
            {
                std::string st(zero, '0');
                str = str.append(st);
            }

            bool flag = false;
            if(a4 != 0)
            {
                flag = true;

                p = 1;
                while(pow(10, p++) < a4);
                p--;

                if((c+1) != i)
                    vect1[c+1] = std::to_string(a4).append(vect1[c+1]);
                else
                {
                    double b = atof(std::to_string((double)a1/a2).c_str());

                    str.append(std::to_string(b));             
                    return str;
                }
            }

            zero = 0;
            str.append(std::to_string(a3));
        }

        return str;
    }

    std::string MODE(const char* str1, const char* str2)
    {
        std::vector <std::string> vect1;
        std::vector <std::string> vect2;
        Calculator::segmentationDiv(str1, 10,vect1);
        Calculator::segmentationDiv(str2, 9, vect2);   

        long long int a1, a2, a3, a4;
        int i = vect1.size();

        std::string str = "0";
        a2 = atoll(vect2[0].c_str());

        for(int c = 0; c < i; c++)
        {
            a1 = atoll(vect1[c].c_str());
            a4 = a1 % a2;

            if(a4 != 0)
            {
                if((c+1) != i)
                    vect1[c+1] = std::to_string(a4).append(vect1[c+1]);
                else
                {
                    str = std::to_string(a4);            
                    return str;
                }
            }
        }

        return str;
    }    
}

std::string sumstri(const char* str1, const char* str2) // n digits + n digits
{
    if(Calculator::checkInt(str1) && Calculator::checkInt(str2))
    {
        const char* ch1 = Calculator::big(str1, str2);
        const char* ch2 = (strcmp(ch1,str1)) ? str1 : str2;
        bool one, two;
        one = two = true; // true => + , false => -
        Calculator::isNegative(ch1, ch2, one, two); // + or - 

        std::string Final;
        if(one == false && two == true)
        {
            Final = Calculator::SUB(ch1,ch2);
            Final = "-" + Final;
        }
        else if(one == true && two == false)
        {
            Final = Calculator::SUB(ch1,ch2);
        }
        else if((one == false) && (two == false))
        {
            Final = Calculator::SUM(ch1,ch2);
            Final = "-" + Final;
        }
        else
            Final = Calculator::SUM(ch1,ch2);  

        return Final; 
    }
    else
        return "0";
}

std::string minstri(const char* str1, const char* str2) // n digits - n digits
{
    if(Calculator::checkInt(str1) && Calculator::checkInt(str2))
    {
        const char* ch1 = Calculator::big(str1, str2);
        const char* ch2 = (strcmp(ch1,str1) != 0) ? str1 : str2;

        bool one, two;
        one = two = true; // true => + , false => -
        Calculator::isNegative(ch1, ch2, one, two); // + or - 
        if(two)
            two = false;
        else    
            two = true;

        std::string Final;
        if(one == false && two == true)
        {
            Final = Calculator::SUB(ch1, ch2);
            Final = "-" + Final;
        }
        else if(one == true && two == false)
        {
            Final = Calculator::SUB(ch1, ch2);       
        }
        else if((one == false) && (two == false))
        {
            Final = Calculator::SUM(ch1, ch2);
            Final = "-" + Final; 
        }
        else
            Final = Calculator::SUM(ch1,ch2);

        return Final;
    }
    else
        return "0";
}

std::string multistri(const char* str1, const char* str2) // n digits * n digits
{
    if(Calculator::checkInt(str1) && Calculator::checkInt(str2))
    {
        const char* ch1 = Calculator::big(str1, str2);
        const char* ch2 = (strcmp(ch1,str1) != 0) ? str1 : str2;

        bool one, two;
        one = two = true;
        Calculator::isNegative(ch1, ch2, one, two);

        std::string Final = Calculator::MULTY(str1, str2);
        if(one == two)
            return Final;
        else
            Final = "-" + Final;

        return Final;
    }
    else
        return "0";   
}

std::string divitstri(const char* str1, const char* str2) // n digits / 9 digits
{
    if(Calculator::checkInt(str1) && Calculator::checkInt(str2))
    {
        // const char* ch1 = Calculator::big(str1, str2);
        // const char* ch2 = (strcmp(ch1,str1)) ? str1 : str2;
        bool one, two;
        one = two = true;
        Calculator::isNegative(str1, str2, one, two);

        std::string div = Calculator::DIVIT(str1, str2);
        if(one != two)
            div = "-" + div;
        if(!div.compare(""))
            return "0";
        return div;
    }
    else
        return "0";  
}

std::string modestri(const char* str1, const char* str2) // n digits % 9 digits
{
    if(Calculator::checkInt(str1) && Calculator::checkInt(str2))
    {
        bool one, two;
        one = two = true;
        Calculator::isNegative(str1, str2, one, two);

        std::string div = Calculator::MODE(str1, str2);
        if(one)
            return div;
        else
        {
            div = "-" + div;
            return div;
        }
    }
    else
        return "0"; 
}