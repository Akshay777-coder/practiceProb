/* armstrong number is a number that is equal to the sum of cubes of its digit */
#include<iostream>
using namespace std;

bool isArmstrong(int n) {
    int copyN = n;
    int sumOfCubes;
    while(n != 0) {
        int dig = n % 10;
        sumOfCubes += (dig * dig * dig);

        n = n / 10;
    }

    return sumOfCubes == copyN;
}

int main(){
    int n = 153;

    if(isArmstrong(n)) {
        cout << n << " is an armstrong number" << endl;
    } else {
        cout << n << " is NOT an armstrong number" << endl;
    }
    return 0; 
}
