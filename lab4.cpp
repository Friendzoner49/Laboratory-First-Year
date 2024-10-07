#include <iostream>
#include <stdio.h>
#include <math.h>
#include <iomanip>  
using namespace std;

double taylor(double x, double E){
    int k = 1;
    double temp = 1;
    double value = 1;
    double f0 = 0;
    do {
        f0 = temp;
        temp *= ((-1) * (x*x / ((2 * k) * (2 * k -1))));
        value += temp;
        ++k;
    } while (fabs(temp - f0) >= E);
    return value;
}

main() {

double a, b;
long double E, x1, x2, xi, xs, x;
long double f, F, Q;

cout << "input E (epsilon): ";
cin >> E;
cout << "input x start: ";
cin >> x1;
cout << "input x end: ";
cin >> x2;
cout << "input step: ";
cin >> xs;

if (x1 == x2) {
        cout << "x1 != x2";
        exit(0);
        system("pause");
    }
if (xs == 0) {
        cout << "Step != 0";
        exit(0);
        system("pause");
    }
if (E == 0) {
        cout << "E != 0";
        exit(0);
        system("pause");
    }

cout << setw(21) << "x|" << setw(16) << "f" << "|" << setw(21) << "F|" << setw(22) << "Q|" << endl;
x = x1;
while (x < x2) {
    f = cos(x);
    F = taylor(x, E);
    Q = sqrt(fabs((f * f) - (F * F)));
    cout << setw(20) << setprecision(7) << fixed << x << "|" << setw(16) << f << "|" << setw(20) << setprecision(7) << fixed << F << "|" << setw(21) << Q << "|" << endl;
    x += xs;
}
cout << "---------------------------------------------------------------------------------" << endl;
cout << endl;
cout << "input x ideal: ";
cin >> xi;

cout << setw(21) << "E|" << setw(16) << "f" << "|" << setw(21) << "F|" << setw(22) << "Q|" << endl;

E = 0.1;
while (E > 0.0000001) {
    f = cos(x);
    F = taylor(x, E);
    Q = sqrt(fabs((f * f) - (F * F)));
    cout << setw(20) << setprecision(7) << fixed << E << "|" << setw(16) << f << "|" << setw(20) << setprecision(7) << fixed << F << "|" << setw(21) << Q << "|" << endl;
    E*=0.1;
}
cout << "---------------------------------------------------------------------------------" << endl;

return 0;
}
