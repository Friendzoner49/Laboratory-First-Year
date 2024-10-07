#include <stdio.h>
#include <math.h>
#include <iostream>
#include <algorithm>
using namespace std;

bool check(float x) {
   float tmp = int(sqrt(x));
   if (tmp * tmp == x) return true;
   else return false;
}
int main() {
   float a[5];
   cout << "input a (natural numbers) = ";
   cin >> a[0];
   cout << "input b (natural numbers) = ";
   cin >> a[1];
   cout << "input c (natural numbers) = ";
   cin >> a[2];
   sort(a, a + 3);
   if(a[0]<=1 || a[1]<=1 || a[2]<=1){
       cout << "a,b,c must be higher than 1";
   } else if (a[0] * a[0] + a[1] * a[1] == a[2] * a[2]) {
       cout << "this is a Pythagorean triple";
       return 0;
   }
   else {
       float x, y, z;
       x = a[0]; y = a[1];
       for (x; x <= 100000; x++) {
           for (y = x; y <= 100000; y++) {
               if (check(x * x + y * y)) {
                   cout << x << " " << y << " " << int(sqrt(x * x + y * y));
                   return 0;
               }
           }
       }

   }

   return 0;
}
