/*
Code by Karan Budhathoki, Leslie Delval, Prem Adhikari
*/
#include <iostream>
using namespace std;
#include <fstream>
#include"HuffmanProject.h"

int main() {
    
    huffman myhuff;// variable of type class
    myhuff.createArray();//creating array
    myhuff.printArray();// printing the arrays
    cout<<"------------------------------"<<endl;
    myhuff.createLinkedList();// creating linked list
    myhuff.printLinkedList();// printing the linked
    cout<<"------------------------------"<<endl;
    myhuff.createTree();// creating the tree
    myhuff.printTree();// printing the tree

    cout<<"------------------------------"<<endl;

    char input;
    bool check = true;
    
    while (check) {
        cout << "\nEnter character to encode or enter n for exit: ";// prompting the user to encode
        cin >> input;
        if (input == 'n') {
            check = false;
            break;
        }
        cout << "\n\n";
        myhuff.encode(input);
    }
    char* s;
    s = new char[8];
    while (true) {
        cin.ignore(255, '\n');
        cout << "Enter a string to decode or press enter to exit: ";// prompting the user to decode.
        cin.getline(s, 8);
        if (!s[0]) {
            break;
        }
        cout << myhuff.decode(s) << "\n\n";// printinng the decode.
    }
    return 0;
}
