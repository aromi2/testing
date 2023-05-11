#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main() {
    string file_name;
    cout << "Enter input file name: ";
    cin >> file_name;

    // commit testing

    //file 불러오기
    ifstream inFile;
    inFile.open(file_name);
    string file_inform;
    string file_inform1;
    string file_inform2;
    string file_inform3;

    if(inFile.is_open()){
        while(!inFile.eof()){

            inFile >> file_inform;
            inFile >> file_inform1;
            inFile >> file_inform2;
            inFile >> file_inform3;
            cout << file_inform << '\t';
            cout << file_inform1 << '\t';
            cout << file_inform2 << '\t';
            cout << file_inform3 << '\t' << endl;
            
        }

        while

        for(; !inFile.eof(); )


    }
     inFile.close();

}