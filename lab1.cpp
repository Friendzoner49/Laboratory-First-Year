#include<iostream> 
#include <math.h> 
#include <iomanip>  
using namespace std;


int main() {
    double x = -5.8, a, b, c;
    cout << "input a: ";
    cin >> a;
    cout << "------------------------------------------------------------" << endl;
    cout << setw(20) << "a" << "|" << setw(16) << "x" << "|" << setw(22) << "y|" << endl;
    while (x < 26.8) {
        c = 0.7 + a * cos(x);
        double y = asin(c);
        if (c < -1 || c > 1) {
            cout << setw(20) << setprecision(5) << fixed << a << "|" << setw(16) << x << "|" << setw(21) << "Error" << "|" << endl;
        }
        else {
            cout << setw(20) << setprecision(5) << fixed << a << "|" << setw(16) << x << "|" << setw(21) << y << "|" << endl;
        }
        x += 3.1;
    }
    cout << "------------------------------------------------------------" << endl;
}
