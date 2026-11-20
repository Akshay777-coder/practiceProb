#include <iostream>
#include <fstream>
using namespace std;

int main(){
// 9. Count lines in file
//      Write a program that counts the number of lines in notes.txt
ifstream in("notes.txt");
        char ch;
        int count = 0;
        while(in.get(ch)){
                if(ch == '\n'){
                        count++;
                }else{
                        continue;
                }
        }
        in.close();
        cout << "Number of lines are "<< count << endl;
        return 0;
}
