/**/
#include <iostream>
using namespace std;

bool reverseNum(int n) {
    int revNum = 0;
    while(n != 0) {
        int dig = n % 10;
        int revNum = revNum * 10 + dig;
        n = n / 10;
    }

    return revNum
}

int main() {
    int n = 3838;
    cout << reverseNum(n);
    // cout << "121 is a palindrome: " << isPallindrome(n) << endl;
    return 0;
}
