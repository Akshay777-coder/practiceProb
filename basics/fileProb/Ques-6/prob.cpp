#include <iostream>
#include <fstream>
using namespace std;

int main(){
//6. Count lines in a file
// Write a program that counts the lines in a file.txt
        ifstream in("story.txt");
        char ch;
        int words = 0;
        bool inword = false;
        while(in.get(ch)){
                if(ch == ' ' || ch == '\n' || ch == '\t'){
                        inword = false;
                }else{
                        if(!inword){
                                words++;
                                inword = true;
                        }
                }
        }
        in.close();
        cout << "Total Words : "<< words << endl;
        return 0;
}
