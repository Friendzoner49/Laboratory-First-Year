#include <iostream>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <Windows.h>
#include <cmath>
#include <time.h>
#include <conio.h>
#include <stdio.h>
using namespace std;


double taylor(double x, double E){
    int k = 1;
    double temp = x;
    double value = 1;
    double f0 = 0;
    do {
        f0 = temp;
        temp *= ((-1) * (3*3*x*x / ((2 * k) * (2 * k -1))));
        value += temp;
        ++k;
    } while (fabs(temp - f0) >= E);
    return value;
}


void SetColor(int backgound_color, int text_color)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

    int color_code = backgound_color * 16 + text_color;
    SetConsoleTextAttribute(hStdout, color_code);
}

float n, m;



int matrix_A [1000][1000];
bool check = false;
int count = 0;


int main()
{


int x = -999999;
memset(matrix_A, x, 1000*1000);

HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO start_attribute; 
    GetConsoleScreenBufferInfo(hStdOut, &start_attribute); 




cout << "Input the number of rows in the array A: ";
cin >> n;
cout << "Input the number of columns array A: ";
cin >> m;







if (n <= 0 || m <= 0) {
   cout << "Array does not exist";
   exit(0);
   system("pause");
  }

if (check_real_integer_number(n) == 0 || check_real_integer_number(m) == 0) {
   cout << "n, m must be integer number";
   exit(0);
   system("pause");
}

srand(time(0));
for (int i=0; i<n; i++)
{
   for(int j=0; j<m; j++)
   {
       matrix_A[i][j] = rand()%2;
       }
   }



int matrix_B [3];
for(int i=0; i<3; i++)
{
   matrix_B[i] = rand()%2;
}



SetColor(0, 7);
for (int i=0; i<n; i++)
{
   for(int j=0; j<m; j++)
       {
       cout << matrix_A[i][j] << "\t";
       }
       cout << "\n";
   }
cout << endl;



SetColor(0, 10);
for(int i=0; i<3; i++)
       {
       cout << matrix_B[i] << "\t";
       }
cout << endl;


for (int i=0; i<n; i++)
{
   for(int j=0; j<m; j++)
   { 
       if(j<=m){
       if(matrix_A[i][j] == matrix_B[0] && matrix_A[i][j+1] == matrix_B[1] && matrix_A[i][j+2] == matrix_B[2])
       {
           check = true;
       }
       }
   }
}


if(check == true){
for (int i=0; i<n; i++)
{
   for(int j=0; j<m; j++)
   { 
       if(j<=m){
       if(matrix_A[i][j] == matrix_B[0] && matrix_A[i][j+1] == matrix_B[1] && matrix_A[i][j+2] == matrix_B[2])
       {
           SetColor(0, 4);
           cout << matrix_A[i][j] << "\t";
       } else if(j>=1 && matrix_A[i][j-1] == matrix_B[0] && matrix_A[i][j] == matrix_B[1] && matrix_A[i][j+1] == matrix_B[2])
       {
            SetColor(0, 4);
            cout << matrix_A[i][j] << "\t";
       } else if(j>=2 && matrix_A[i][j-2] == matrix_B[0] && matrix_A[i][j-1] == matrix_B[1] && matrix_A[i][j] == matrix_B[2])
        {
            SetColor(0, 4);
            cout << matrix_A[i][j] << "\t";
        }

        else
       {
           SetColor(0, 7);
           cout << matrix_A[i][j] << "\t";
       }
       }
   }
   cout << "\n";
}
}



SetColor(0, 6);
if(check == false)
{
   cout << "No matching line found.";
} else {
   cout << "The number of line: ";
}



for (int i=0; i<n; i++)
{
   for(int j=0; j<m; j++)
   { 
       if(j<=m){
       if(matrix_A[i][j] == matrix_B[0] && matrix_A[i][j+1] == matrix_B[1] && matrix_A[i][j+2] == matrix_B[2])
       {
           cout << i+1 << " ";
       }
       }
   }
}

SetConsoleTextAttribute(hStdOut, start_attribute.wAttributes);
return 0;
}
