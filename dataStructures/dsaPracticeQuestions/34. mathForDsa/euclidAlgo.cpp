/* is to fing the gcd/hcf of two numbers
 * gcd(a,b) : gcd(a-b, b), a > b
 *            gcd(a, b-a), b > a
 * gcd(20,28) -> gcd(20,8) -> gcd(12,8) -> gcd(4,8) ->
 * gcd(4,4) -> gcd(0,4) -> 4 is gcd
 *
 * ***optimized approach***
 * gcd(a,b) : gcd(a%b, b), a > b
 *            gcd(a, b%a), b > a
 * gcd(20,28) -> gcd(20,8) -> gcd(4,8) -> gcd(4,0)
 * -> 4 is gcd
 */

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

int gcdRec(int a, int b) {
    if(b == 0) return a;
    
    return gcdRec(b, a % b);
}

int main() {
    cout << gcd(20,28) << endl;
    cout << gcdRec(20,28) << endl;
    return 0;
}
