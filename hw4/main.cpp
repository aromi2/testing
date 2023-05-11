#include <iostream>
#include <fstream>
#include <string>
#include "hw4.h"

using namespace std;

int main() {
    string index;
    string name_data;
    string id_data;
    string age_data;
    string score_data;

    
    Menu *person = new Menu();
    
    
    //file 불러오기
    person->File();
    //select menu and get index like as "A".
    while(1){
        cout << "*********** MENU ****************" << endl;
        cout << "A: Add new data" << endl;
        cout << "D: Delete Data" << endl;
        cout << "R: Retrieve data" << endl;
        cout << "P: Print list" << endl;
        cout << "Q: Quit" << endl;
        cout << "Choose menu: " << endl;
        cin >> index;
        //implement according to index inputed.
        switch(index){
            //Add new data
            case "A": 
                person->MenuA(name_data, id_data, age_data, score_data);
            //Delete data
            case "D":
                person->MenuD(id_data);
            //Retrieve data
            case "R":
                person->Retrieve(id_data);
            //Print list
            case "P": 
                person->PrintList();
            //Quit
            case "Q":
                cout << endl << "Bye!" << endl;
                exit(0);
        }
    }



    
}