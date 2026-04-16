/* leetCode problem no 7 */
#include <iostream>
using namespace std;

int reverse(int n) {
    int revNum = 0;
    while(n != 0) {
        int dig = n % 10;
        revNum = revNum * 10 + dig;
        n = n / 10;
    }
    return revNum;
}

int main() {
    int n = 2546;
    cout << "reverse of " << n << " : " << reverse(n) << endl;
    return 0;
}
