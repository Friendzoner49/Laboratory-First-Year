#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>
#include <conio.h>
#include <windows.h>
#include <locale>
using namespace std;

#include "pch.h"
#include <cmath>
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <iomanip>
#include <locale>
#pragma once
using namespace std;

struct Colors {
    int text;
    int background;
};

Colors mircolor = { 9, 12 };

void setcolor(int text, int background) {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, (background << 4) | text);
}

double rfun(double x, double ep) {
    int n;
    int k = 2;
    double s = x + 2;
    double lastresult = 1;
    double flast = 0;
    do {
        flast = lastresult;
        lastresult = lastresult / k;
        s += lastresult;
        ++k;
    } while (fabs(lastresult - flast) >= ep);
    return s;
}

double mfun(double x) {
    return exp(1) + x;
}

extern "C" __declspec(dllexport) Colors getHeadColor()
{
    return mircolor;
}

extern "C" __declspec(dllexport) string getDllAuthorName()
{
    return "Vu Manh Hung - 5130902/30002";
}

extern "C" __declspec(dllexport) string getFunctionName()
{
    return "e + x";
}

extern "C" __declspec(dllexport) void printLine(int num, double x, double a, Colors(*CallbackFuntion)(), double ep)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO start_attribute;
    GetConsoleScreenBufferInfo(hStdout, &start_attribute);

    Colors nextcolor = CallbackFuntion();
    setcolor(nextcolor.text, nextcolor.background);
    int k = 0;
    if (!isnan(x) && !isinf(x))
    {
        if (num == 0)
        {
            if (x > 1)
            {
                cout << fixed << setprecision(8);
                cout << '|' << setw(29) << x << '|' << setw(29) << "ERROR" << '|' << setw(29) << exp(1) + x << '|' << setw(29) << "ERROR" << '|';
                k++;
            }
            if (x < -1 + 0.000000000001)
            {
                cout << fixed << setprecision(8);
                cout << '|' << setw(29) << x << '|' << setw(29) << "ERROR" << '|' << setw(29) << "ERROR" << '|' << setw(29) << "ERROR" << '|';
                k++;
            }
        }
        else
        {
            if (x > 1)
            {
                cout << fixed << setprecision(8);
                cout << '|' << setw(29) << ep << '|' << setw(29) << "ERROR" << '|' << setw(29) << exp(1) + x << '|' << setw(29) << "ERROR" << '|';
                k++;
            }
            if (x < -1 + 0.000000000001)
            {
                cout << fixed << setprecision(8);
                cout << '|' << setw(29) << ep << '|' << setw(29) << "ERROR" << '|' << setw(29) << "ERROR" << '|' << setw(29) << "ERROR" << '|';
                k++;
            }
        }
    }
    else
    {
        if (num == 0) {
            cout << fixed << setprecision(8) << "|" << setw(29) << x << "|" << setw(29) << "ERROR" << "|" << setw(29) << "ERROR" << "|" << setw(29) << "ERROR" << "|";
        }
        else {
            cout << fixed << setprecision(8) << "|" << setw(29) << ep << "|" << setw(29) << "ERROR" << "|" << setw(29) << "ERROR" << "|" << setw(29) << "ERROR" << "|";
        }
    }
    if (k == 0)
    {
        double r = rfun(x, ep);
        double mt = mfun(x);
        if (!isnan(x) && !isinf(x))
        {
            if (num == 0)
            {
                cout << fixed << setprecision(8) << "|" << setw(29) << x << "|" << setw(29) << r << "|" << setw(29) << mt << "|" << setw(29) << sqrt(abs(r * r - mt * mt)) << "|";
            }
            else
            {
                cout << fixed << setprecision(8) << "|" << setw(29) << ep << "|" << setw(29) << r << "|" << setw(29) << mt << "|" << setw(29) << sqrt(abs(r * r - mt * mt)) << "|";
            }

        }
        else {
            if (num == 0) {
                cout << fixed << setprecision(8) << "|" << setw(29) << x << "|" << setw(29) << "ERROR" << "|" << setw(29) << "ERROR" << "|" << setw(29) << "ERROR" << "|";
            }
            else {
                cout << fixed << setprecision(8) << "|" << setw(29) << ep << "|" << setw(29) << "ERROR" << "|" << setw(29) << "ERROR" << "|" << setw(29) << "ERROR" << "|";
            }
        }
    }


    SetConsoleTextAttribute(hStdout, start_attribute.wAttributes);
    cout << endl;
}





HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
void setcolor(int text, int background) {
    SetConsoleTextAttribute(h, (background << 4) | text);
}

struct color {
    int text;
    int background;
};

bool isFileBinary(string fileName) {
    ifstream ifs;
    ifs.open(fileName);
    char a;
    while (ifs.get(a)) {
        if (a == EOF) {
            return true;
        }
        //cout << "|" << a << "|" << endl;
    };
    ifs.close();
    return false;
}

color mycol = { 9, 12 };
int calls = 0;

color callback() {
    calls++;

    if (calls % (1 % 5) == 0 && calls != 1) {
        if (mycol.text == 11)
        {
            mycol.text = mycol.text + 2;
        }
        else
        {
            mycol.text = mycol.text + 1;
        }
    }
    if (mycol.text > 15) {
        mycol.text = 0;
    }
    return mycol;
}

int main()
{
    HINSTANCE moduleInject = LoadLibraryA("DLL9.dll");
    if (moduleInject == nullptr) {
        cout << "DLL library error";
        system("pause");
        return 0;
    }
    typedef string(*author)();
    author getDllAuthorName = (author)GetProcAddress(moduleInject, "getDllAuthorName");
    typedef void (*solve)(int numder, double x, double a, color(*CallbackFunc)(), double ep);
    solve printLine = (solve)GetProcAddress(moduleInject, "printLine");
    typedef string(*namefun)();
    namefun getFunctionName = (namefun)GetProcAddress(moduleInject, "getFunctionName");
    typedef color(*colordll)();
    colordll getHeadColor = (colordll)GetProcAddress(moduleInject, "getHeadColor");

    CONSOLE_SCREEN_BUFFER_INFO start_attribute;
    GetConsoleScreenBufferInfo(h, &start_attribute);

    double ep, x1, x2, dx, a;
    color headend = getHeadColor();
    cout << "Author DLL: " << getDllAuthorName().c_str() << endl;
    cout << "Enter a number E greater than 0: ";
    cin >> ep;
    while (ep <= 0) {
        cout << "Epsilon is less than zero, write E>0: ";
        cin >> ep;
    }
    cout << "Input x start: ";
    cin >> x1;
    cout << "Input x end: ";
    cin >> x2;
    cout << "Input step: ";
    cin >> dx;
    if ((x1 < x2 && dx < 0) || (x1 > x2 && dx > 0) || (dx == 0)) {
        cout << "Error, the problem cannot be solved with such a set of numbers" << endl;
        system("pause");
        return 0;
    }
    cout << "Input a: ";
    cin >> a;
    setcolor(headend.text, headend.background);
    cout << " ----------------------------------------------------------------------------------------------------------------------- " << endl;
    cout << "|" << setw(29) << "x" << "|" << setw(29) << getFunctionName().c_str() << "|" << setw(29) << "F(x)" << "|" << setw(29) << "Q" << "|" << endl;
    cout << " ----------------------------------------------------------------------------------------------------------------------- " << endl;
    SetConsoleTextAttribute(h, start_attribute.wAttributes);
    if (x1 < x2)
    {
        for (double i = x1; i < x2 + 0.0000000001; i += dx)
        {
            printLine(0, i, a, callback, ep);
        }
    }
    else
    {
        for (double i = x1; i > x2 - 0.0000000001; i += dx)
        {
            printLine(0, i, a, callback, ep);
        }
    }
    setcolor(headend.text, headend.background);
    cout << " ----------------------------------------------------------------------------------------------------------------------- " << endl;
    SetConsoleTextAttribute(h, start_attribute.wAttributes);
    cout << endl;

    double xi;
    cout << "Input x ideal: ";
    cin >> xi;
    setcolor(headend.text, headend.background);
    cout << " ----------------------------------------------------------------------------------------------------------------------- " << endl;
    cout << "|" << setw(29) << "E" << "|" << setw(29) << getFunctionName().c_str() << "|" << setw(29) << "F(x)" << "|" << setw(29) << "Q" << "|" << endl;
    cout << " ----------------------------------------------------------------------------------------------------------------------- " << endl;
    SetConsoleTextAttribute(h, start_attribute.wAttributes);

    for (double i = 0.1; i > 0.00000001; i = i / 10) {
        printLine(1, xi, a, callback, i);
    }

    setcolor(headend.text, headend.background);

    cout << " ----------------------------------------------------------------------------------------------------------------------- " << endl;

    SetConsoleTextAttribute(h, start_attribute.wAttributes);

    system("pause");
    return 0;

}
