#include <iostream>
#include <fstream>
using namespace std;

int main(){
// 4. Write multiple lines
//      Writes a program that appends the text to an existing file data.txt
//      without deleting the previous contents.

        string str4 = "This string is being appended and the previous data is being removedii\n";
        ofstream out("data.txt");
        out << str4;
        out << str4;
        out << str4;

        return 0;
}
