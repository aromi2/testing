#include <iostream>
#include <string>
#include "hw4.h"
#include <fstream>
using namespace std;

//Constructor
Menu::Menu(){
    head = NULL;
}

////Lecture: DS Chap4.Lists page20
//Destructor
Menu::~Menu(){
    list_node *curr = head, *next;
    while(curr){
        next = curr->link;
        delete curr;
        curr = next;
    }
}

////Lecture: DS Chap4.Lists page19
bool Menu::IsEmpty(){
    return (head==NULL);
}

//Lecture: DS Chap4.Lists page13~15
//add new data
void Menu::MenuA(string name_data, string id_data, string age_data, string score_data){
    //make new "new_person" list node
    list_node *new_person = new list_node;
    cout << "==> Type student name: ";
    cin >> name_data;
    new_person->name = name_data;
    
    cout << "==> Type student id: ";
    cin >> id_data;
    new_person->id = id_data;
    //if id_data is not 5digits, print "Id is wrong."
    if(id_data.length() != 5){
        cout << "Id is wrong." << endl;
        exit(1);
    }
    //if id_data is 5digits, keep implementing
    else {
        cout << "==> Type age of student: ";
        cin >> age_data;
        new_person->age = age_data;
        
        //if score_data is larger than 0 and is smaller than 100, keep implementing. if else, print "Score is wrong."
        if(((0<=score_data)&&(score_data<=100))){
            cout << "==> Type score: ";
            cin >> score_data;
            new_person->score = score_data;
            
            new_person->link = head;
            head = new_person;
            
            cout << endl << new_person->name << "'s record is added." << endl;    
        }
        else{
            cout << "Score is wrong." << endl;
            exit(1);
        }
    }
}

////Lecture: DS Chap4.Lists page16~18
//Delete data
void Menu::MenuD(string id_data){
    cout << "==> Type student id: ";
    cin >> id_data;
    
    //if id_data is not 5digits, print "Id is wrong." If else, keep implementing.
    if(id_data.length() != 5){
        cout << "Id is wrong." << endl;
        exit(1);
    }
    else{
        list_node *prev;
        list_node *curr = head;
        while(curr!=NULL && curr->id!=id_data) {
            prev = curr;
            curr = curr->link;
        }
        
        if(curr != NULL) {
            if(curr == head) head = curr->link;   //If first element is the one to be deleted
            else preve->link = curr->link;
            delete curr;
        }

        cout << endl << curr->name << "'s record is deleted." << endl;
    }
}

//Lecture: DS Chap4.Lists page12
//Retrieve data
bool Menu::Retrieve(string id_data){
    cout << "==> Type student id: ";
    cin >> id_data;
    //if id_data is not 5digits, print "Id is wrong." If else, keep implementing.
    if(id_data.length() != 5){
        cout << "Id is wrong." << endl;
        exit(1);
    }
    else{   
        list_node *curr = NULL;
        for(curr = head; curr != NULL; curr=curr->link) {
            if(curr->id == id_data) break;
        }
        if(curr!=NULL) {
            cout << endl << curr->name << "'s age is " << curr->age << " and score is " << curr->score << endl;
            return true;
        }
        else {
            cout << endl << "No record shown" << endl;
            return false;
        }
    }
}

//print list
void Menu::PrintList(){
    list_node *curr = NULL;
    cout << endl << "id_number" << '\t' << "name" << '\t' << "age" << '\t' << "score" << endl;
    for(curr = head; curr != NULL; curr = curr->link){
        cout << curr->id  << '\t' << curr->name << '\t' << curr->age << '\t' << curr->score << endl;
    }
}


void Menu::File(){
    //get file name
    string file_name;
    cout << "Enter input file name: ";
    cin >> file_name;

    //blog: https://devowen.com/311
    //file 불러오기
    ifstream inFile;
    inFile.open(file_name);
    list_node *person = new list_node;
    string temp;
    if(inFile.is_open()){
        //save a value in "person" node except for the first line of a file
        getline(inFile, temp);
        while(!inFile.eof()){
            inFile >> person->id;
            inFile >> person->name;
            inFile >> person->age;
            inFile >> person->score;
            head->link = person;    
        }
        //close file
        inFile.close();

    }

    //sort();
}