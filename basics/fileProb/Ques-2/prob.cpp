#include <iostream>
#include <fstream>
using namespace std;

int main(){
// 2. Read from a file
//     Write a c++ program that creates a file named data.txt and writes

        string str2;
        ifstream in("data.txt");
        getline(in,str2);
        cout << str2;
        
        return 0;
}
