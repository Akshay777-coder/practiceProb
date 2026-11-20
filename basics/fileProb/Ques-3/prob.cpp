#include <iostream>
#include <fstream>
using namespace std;

int main(){
// 3. Append to a file
//      Write a program that reads the content of data.txt and display them on the screen

        string str3 = " I am appending this string into data.txt";
        ofstream out("data.txt",ios::app);
        out << str3;

        return 0;
}
