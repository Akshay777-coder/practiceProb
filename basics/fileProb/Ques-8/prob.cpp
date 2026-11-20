#include <iostream>
#include <fstream>
using namespace std;

int main(){
// 8. Search a word in file
//      Write a program that asks the user for a word and checks whether the word exists in
//      story.txt or not.

        ifstream in("story.txt");
        string word;
        string target;
        cout << "Search for the word : " << endl;
        cin >> target;
        bool found = false;
        while(in >> word){
                if(word == target){
                        found = true;
                        break;
                }
        }
        in.close();
        if(found){
                cout <<word << " exists in the file"<< endl << endl;
        }else{
                cout << "word do not existed in the file" << endl;
        }
        return 0;
}
