#include <iostream>
using namespace std;
#include <fstream>
#include"HuffmanProject.h"

int main() {
    
    huffman myhuff;
    myhuff.createArray();
    myhuff.printArray();
    cout<<"------------------------------"<<endl;
    myhuff.createLinkedList();
    myhuff.printLinkedList();
    cout<<"------------------------------"<<endl;
    myhuff.createTree();
    myhuff.printTree();
    cout<<"------------------------------"<<endl;

    char input;
    bool check = true;
    
    while (check) {
        cout << "\nEnter character to encode or enter n for exit: ";
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
        cout << "Enter a string to decode or press enter to exit: ";
        cin.getline(s, 8);
        if (!s[0]) {
            break;
        }
        cout << myhuff.decode(s) << "\n\n";
    }
    return 0;
}
