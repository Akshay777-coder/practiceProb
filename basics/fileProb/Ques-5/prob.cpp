#include <iostream>
#include <fstream>
using namespace std;

int main(){
// 5. Count characters in a file
//      Write a program that writes 5 lines entered by the user into a file called notes.txt

        ofstream out;
        out.open("notes.txt");
        string str1, str2, str3, str4, str5;
        cout << "Enter five lines: " << endl;
        getline(cin,str1);
        getline(cin,str2);
        getline(cin,str3);
        getline(cin,str4);
        getline(cin,str5);
        out << str1 << endl << str2<< endl << str3<< endl << str4<< endl << str5;                                                                              out.close();
        ifstream in("notes.txt");
        char ch;
        int count = 0;

        while(in.get(ch)){
                count++; // reads every character
        }
        in.close();
        cout << "Number of characters in text file is: " << count << endl;

        return 0;
}
