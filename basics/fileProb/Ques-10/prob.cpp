#include <iostream>
#include <fstream>
using namespace std;

int main(){
// 10. Store and read numbers ()
//      Write a program that:
//      * Writes 10 integers into number.txt
//      * Read them back and print their sum

        ofstream out("number.txt");
        int num[10];
        for(int i = 0;i < 10;i++){
                cout << "Enter Number " << i + 1 << ": " << endl;
                cin >> num[i];
                out << num[i] << " ";
        }
        out.close();
        ifstream in("number.txt");
        int n = 0;
        int sum = 0;
        while(in >> n){
                sum += n;
        }
        in.close();
        cout << "Addition of the present numbers is : "<< sum << endl;
        return 0;
}
