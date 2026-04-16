#include <iostream>
using namespace std;

int gcd(int a, int b) {
    while(a > 0 && b > 0) {
        if(a > b) {
            a = a % b;
        } else {
            b = b % a;
        }
    }

    if(a == 0) return b;
    return a;
}

int lcm(int a, int b) {
/* a*b = lcm * gcd */
    return (a * b)/gcd(a,b);
}

int main() {
    cout << "gcd of 20 & 28: " << gcd(20,28) << endl;
    cout << "lcm of 20 & 28: " << lcm(20,28) << endl;
    return 0;
}
