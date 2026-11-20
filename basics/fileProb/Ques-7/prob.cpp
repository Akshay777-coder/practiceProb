#include <iostream>
#include <fstream>
using namespace std;

int main(){
// 7. Write a program that copy the file content
//      Writes a program that copies the contents of source.txt into destination.txt

        ofstream out("source.txt");
        out << "Hi this is akshay, i am a present of it lab";
        out.close();
        ifstream in("source.txt");
        string str;
        getline(in,str);
        in.close();
        ofstream output("destination.txt");
        output << str;
        output.close();

        return 0;
}
