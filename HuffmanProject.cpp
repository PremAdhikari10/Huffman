/*
Code by Karan Budhathoki, Leslie Delval, Prem Adhikari
*/
#include <iostream>
using namespace std;
#include <fstream>
#include"HuffmanProject.h"

const int MAX = 256;


// Defining wrapper method to print trees

void huffman::alt_printTree(nodeType* p, int level) {
        if (p) {
            cout << p->ch << '\t' << p->weight << "\t" << level << endl;
            alt_printTree(p->zero, level + 1);
            alt_printTree(p->one, level + 1);
        }
    }
    
    //inserting node in the linked list
    void huffman:: put(nodeType* p) {
        nodeType** dp;
        dp = &root;//access root
        while (*dp && (*dp)->weight <= p->weight) {//asecnding  order
            dp = &(*dp)->next;
        }
        p->next = *dp;
        *dp = p;
    }
// isthre function for creating linked list.
    bool huffman::isThere(nodeType* p, char myCh) {
        if (!p) {
            return false;
        }
        else {
            if (p->ch == myCh) {
                return true;
            }
            else {
                return isThere(p->zero, myCh) || isThere(p->one, myCh);
            }
        }
    }

    //constructor:

    huffman::huffman() {
        root = NULL;
        arr = new nodeType * [MAX];//array gets 256 pointers
        for (int i = 0; i < MAX; i++) {
            arr[i] = NULL;// array of Null pointers
        }
    }
    void huffman::createArray() {
        ifstream ifile;
        ifile.open("input.txt");

        char myCh;
        while (true) {
            myCh = ifile.get();// gets a character
            if (ifile.eof()) {
                break;
            }
            cout.put(myCh);
            //sorting the array by character in ASCII code order
            int j = (int)myCh; //get ASCII code of the character
            if (!arr[j]) {//if seen the character before not Null
                arr[j] = new nodeType;
                arr[j]->ch = myCh;
            }
            arr[j]->weight++;//increment the weight
        }
        ifile.close();
        cout.put('\n');//when finished there characters and weight.
    }
    void huffman::printArray() {
        cout << "\nPrinting the array:\n";
        for (int i = 0; i < MAX; i++) {
            if (arr[i]) {// if position is Null 
                cout << arr[i]->ch << '\t' << arr[i]->weight << '\n';
            }
        }
    }
    //Builiding a linked list
    void huffman::createLinkedList() {
        for (int i = 0; i < MAX; i++) {
            if (arr[i]) {//pointer to a nodetype
                put(arr[i]);//putting arays in the list
            }
        }
    }
    void huffman::printLinkedList() {
        nodeType* p;
        p = root;
        cout << "\nPrinting the linked list:" << endl;
        while (p) {//until it get null pointer till the end
            cout << p->ch << '\t' << p->weight << '\n';
            p = p->next;
        }
    }

    void huffman::createTree() {
        nodeType* p;
        while (root->next) {
            p = new nodeType;
            p->zero = root;
            p->one = root->next;
            p->weight = p->zero->weight + p->one->weight;//sum of two children
            root = root->next->next; //root advances two down the list 
            put(p);// p gets put in

        }
    }
    // Printing the list of weight and character in the trees
    void huffman::printTree() {
        cout << "\nPrinting the Tree:" << endl;
        alt_printTree(root, 0);
    }

    void huffman::encode(char ch) {
        nodeType* p = root;
        while (p->zero) {
            if (isThere(p->zero, ch)) {
                cout.put('0');//if isthere in 0 direction print zero
                p = p->zero;
            }
            else {
                cout.put('1');// if not there use 1
                p = p->one;
            }
        }
        cout << "\nFinished" << endl;
    }
    char huffman::decode(char* d) // pointer gets array of characters.
    {
        int i = 0;
        char num;//
        nodeType* p = root;
        while(p->zero) {
            num = d[i++]; //first digit gets 0
            cout.put(num);
            if (num == '0') {//if digit goes to zero go to zero's side
                p = p->zero;
            }
            else { // else go to ones side.
                p = p->one;
            }
        }
        cout.put('\t');
        return p->ch;
    }

