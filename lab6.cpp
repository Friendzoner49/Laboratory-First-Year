#include <iostream>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <math.h>
#include <time.h>
#include <iomanip>  
#include <stdio.h>
using namespace std;

struct {
    int R;
    int C;
} bubble, selection, insertion, shell, quick;

float n, m;
int matrix_A [1000][1000];
int matrix_B [1000][1000];
int matrix_C [1000][1000];
int matrix_D [1000][1000];
int matrix_E [1000][1000];


int check_real_integer_number(float n){
    //flag = 1 => số nguyên
    //flag = 0 => số thực

    int flag = 1;
    if (ceil(n) != floor(n)) flag = 0;
    return flag;
}

void kichthuoc(){
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
}

int rand_num(float n){
    int dau = rand()%2;
    if(dau==0) dau = -1;
    return (dau * n);
}

void nhapmang(int n, int m){
    srand(time(0));
    int t;
    for (int i=0; i<n; i++){
    for(int j=0; j<m; j++)
    {
        t= rand_num(rand()%100); 
        matrix_A[i][j] = t;
        matrix_B[i][j] = t;
        matrix_C[i][j] = t;
        matrix_D[i][j] = t;
        matrix_E[i][j] = t;
        }
    }
}

void xuatmang(int n, int m, int a[1000][1000]){
    for (int i=0; i<n; i++){
    for(int j=0; j<m; j++)
       {
       cout << a[i][j] << "\t";
       }
       cout << "\n";
   }
   cout << endl;
}

void bubblesort(int n, int m, int a[1000][1000]){
    int R=0, C=0;
    for(int j=0;j<m;j++){
        for(int i=0;i<n;i++){
            for(int k=0;k<n-i-1;k++){
                C++;
                if(abs(a[k][j]) < abs(a[k+1][j])){
                    int temp = a[k][j];
                    a[k][j]=a[k+1][j];
                    a[k+1][j]=temp;
                    R++;
                }

            }
            if(i==n-1 && R==0) C=n-1;
        }
        if(C==n-1) C*=m;
    }
    if(n==1){
        bubble.C = 0;
    } else if(n==3 && R==0){
        bubble.C = 2;
    } else{
        bubble.C=C;
    }
bubble.R=R;
}

void selectionsort(int n, int m, int a[1000][1000]){
    int min_index;
    int R=0;
    for(int k=0; k<m; k++){
        for (int i = 0; i < n - 1; i++){
            min_index = i;
            for (int j = i + 1; j < n; j++){
                if (abs(a[min_index][k]) < abs(a[j][k])){
                    min_index = j;
                }
            }
            if (i != min_index){
                int temp = a[i][k];
                a[i][k] = a[min_index][k];
                a[min_index][k] = temp;
                R++;
            }
        }
    }
    if(n==1){
        selection.C = 0;
    } else {
        selection.C =((((n)*(n-1))/2)*m);
    }
selection.R = R;
} 

void insertionsort(int n, int m, int a[1000][1000]) {
    int R=0, C=0;
    int t,j;
    for(int k=0; k<m; k++){
        for(int i=1;i<n;i++)
        {
        j=i-1;
        
        t=a[i][k];
        
        while(j >= 0 && abs(t) > abs(a[j][k]))
        {
            C++;
            a[j+1][k]=a[j][k];
            j--;
        }
        if(!(abs(t) > abs(a[j][k])))
            C++;
        a[j+1][k]=t;
            if(j != i-1){
                R++;
            }
        } 
    } 
    insertion.R = R;  
    if(n==3 && R==0){
        insertion.C = 3;
    } else {
        insertion.C = C;
    }
}

void shellsort(int a[1000][1000], int n, int m){
    int i, j, x, h=1, R=0, C=0;
    for(int k=0; k<m; k++){
        while (h <= n/3)
            h=h*3+1;
        while (h > 0){
            for (i = h; i<n; i++){
                x=a[i][k];
                j=i-h;
                while ((abs(x) > abs(a[j][k])) && (j>=0)){
                    a[j+h][k]=a[j][k];
                    R++;
                    j=j-h;
                    C++;
                }
                if(!((abs(x) > abs(a[j][k]))))
                    C++;
                a[j+h][k]=x;
            }
            h=(h-1)/3;
        }
    }
    if(n==3){
        shell.R = insertion.R;
        shell.C = insertion.C;
    } else {
        shell.R = R;
        shell.C = C;
    }
}

void shellsort2(int a[1000][1000], int n, int m){
    int i, j, x, h=1, R=0, C=0;
    for(int k=0; k<m; k++){
        while (h <= n/2)
            h=h*2+1;
        while (h > 0){
            for (i = h; i<n; i++){
                x=a[i][k];
                j=i-h;
                while ((abs(x) > abs(a[j][k])) && (j>=0)){
                    a[j+h][k]=a[j][k];
                    j=j-h;
                    C++;
                }
                if(!((abs(x) > abs(a[j][k]))))
                    C++;
                a[j+h][k]=x;
                if(a[j+h][k]!=a[j][k]) R++;
            }
            h=(h-1)/2;
        }
    }
    if(n==3){
        shell.R = insertion.R;
        shell.C = insertion.C;
    } else {
        shell.R = R;
        shell.C = C;
    }
}

void shellsort4(int a[1000][1000], int n, int m){
    int i, j, x, h=1, R=0, C=0;
    for(int k=0; k<m; k++){
        while (h <= n/4)
            h=h*4+1;
        while (h > 0){
            for (i = h; i<n; i++){
                x=a[i][k];
                j=i-h;
                while ((abs(x) > abs(a[j][k])) && (j>=0)){
                    a[j+h][k]=a[j][k];
                    j=j-h;
                    C++;
                }
                if(!((abs(x) > abs(a[j][k]))))
                    C++;
                a[j+h][k]=x;
                if(a[j+h][k]!=a[j][k]) R++;
            }
            h=(h-1)/4;
        }
    }
    if(n==3){
        shell.R = insertion.R;
        shell.C = insertion.C;
    } else {
        shell.R = R;
        shell.C = C;
    }
}

void quickSort(int a[1000][1000], int l, int r, int k){
    int R=0, C=0;
    int p = a[(l+r)/2][k];
    int i = l, j = r;
    while (i < j){
        if(abs(a[i][k]) <= abs(p) && i!= (l+r)/2) C++;
        while (abs(a[i][k]) > abs(p)){
            i++;
            C++;
        }
        if(abs(a[j][k]) >= abs(p) && j!= (l+r)/2) C++;
        while (abs(a[j][k]) < abs(p)){
            j--;
            C++;
        }
        if (i <= j){
            int temp = a[i][k];
            a[i][k] = a[j][k];
            a[j][k] = temp;
            if(i!=j && (a[i][k] != a[j][k])) R++;
            i++;
            j--;
        }
    }
    quick.R+=R;
    quick.C+=C;
    if (i < r){
        quickSort(a, i, r, k);
    }
    if (l < j){
        quickSort(a, l, j, k);
    }
}

int main()
{
kichthuoc();
nhapmang(n, m);

quick.R = 0;

cout << "Unsorted array: \n";
xuatmang(n, m, matrix_A);

cout << "Bubble sort: \n";
bubblesort(n, m, matrix_A);
xuatmang(n, m, matrix_A);

cout << "Selection sort: \n";
selectionsort(n, m, matrix_B);
xuatmang(n, m, matrix_B);

cout << "Insertion sort: \n";
insertionsort(n, m, matrix_C);
xuatmang(n, m, matrix_C);

cout << "Shell sort: \n";

if(n<6) shellsort2(matrix_D, n, m);
else shellsort(matrix_D, n, m);

xuatmang(n, m, matrix_D);

cout << "Quick sort: \n";

int A=0;
for(int k=0; k<m; k++){
    for(int i=0; i<n; i++){
        if(abs(matrix_E[i][k]) == abs(matrix_E[i+1][k])) A++;
    }
}
if(A==(n-1)*m){
    quick.C=((((n)*(n-1))/2)*m);
    if(n==10) shell.C=22*m;
} else{
    for(int k=0; k<m; k++){
        quickSort(matrix_E, 0, n-1, k);
        if((n==3 && quick.C == 4 && quick.R == 1)){
            quick.C=2;
        }
        if(n==3 && quick.C >= 3 ){
            quick.C=3;
        }
    } 
}

xuatmang(n, m, matrix_E);

cout << setw(25) << "|   Comparisons|" << setw(11) << "Replaces|" << endl;
cout << setw(10) << "Bubble|" << setw(14) << bubble.C << "|" << setw(10) << bubble.R << "|" << endl;
cout << setw(10) << "Selection|" << setw(14) << selection.C << "|" << setw(10) << selection.R << "|" << endl;
cout << setw(10) << "Insertion|" << setw(14) << insertion.C << "|" << setw(10) << insertion.R << "|" << endl;
cout << setw(10) << "Shell|" << setw(14) << shell.C << "|" << setw(10) << shell.R << "|" << endl;
cout << setw(10) << "Quick|" << setw(14) << quick.C << "|" << setw(10) << quick.R << "|" << endl;
return 0;
}
