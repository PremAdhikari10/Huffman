/*
Code by Karan Budhathoki, Leslie Delval, Prem Adhikari
*/
#include <iostream>
using namespace std;
#include <fstream>
#include"HuffmanProject.h"

const int MAX = 256;
    
void huffman::alt_printTree(nodeType* p, int level) {
        if (p) {
            cout << p->ch << '\t' << p->weight << "\t" << level << endl;
            alt_printTree(p->zero, level + 1);
            alt_printTree(p->one, level + 1);
        }
    }
    void huffman:: put(nodeType* p) {
        nodeType** dp;
        dp = &root;
        while (*dp && (*dp)->weight <= p->weight) {
            dp = &(*dp)->next;
        }
        p->next = *dp;
        *dp = p;
    }
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


    huffman::huffman() {
        root = NULL;
        arr = new nodeType * [MAX];
        for (int i = 0; i < MAX; i++) {
            arr[i] = NULL;
        }
    }
    void huffman::createArray() {
        ifstream ifile;
        ifile.open("input.txt");

        char myCh;
        while (true) {
            myCh = ifile.get();
            if (ifile.eof()) {
                break;
            }
            cout.put(myCh);
            //sorting the array by character in ASCII code order
            int j = (int)myCh;
            if (!arr[j]) {
                arr[j] = new nodeType;
                arr[j]->ch = myCh;
            }
            arr[j]->weight++;
        }
        ifile.close();
        cout.put('\n');
    }
    void huffman::printArray() {
        cout << "\nPrinting the array:\n";
        for (int i = 0; i < MAX; i++) {
            if (arr[i]) {
                cout << arr[i]->ch << '\t' << arr[i]->weight << '\n';
            }
        }
    }
    void huffman::createLinkedList() {
        for (int i = 0; i < MAX; i++) {
            if (arr[i]) {
                put(arr[i]);
            }
        }
    }
    void huffman::printLinkedList() {
        nodeType* p;
        p = root;
        cout << "\nPrinting the linked list:" << endl;
        while (p) {
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
            p->weight = p->zero->weight + p->one->weight;
            root = root->next->next;
            put(p);

        }
    }
    void huffman::printTree() {
        cout << "\nPrinting the Tree:" << endl;
        alt_printTree(root, 0);
    }

    void huffman::encode(char ch) {
        nodeType* p = root;
        while (p->zero) {
            if (isThere(p->zero, ch)) {
                cout.put('0');
                p = p->zero;
            }
            else {
                cout.put('1');
                p = p->one;
            }
        }
        cout << "\nFinished" << endl;
    }
    char huffman::decode(char* d) {
        int i = 0;
        char num;
        nodeType* p = root;
        while(p->zero) {
            num = d[i++];
            cout.put(num);
            if (num == '0') {
                p = p->zero;
            }
            else {
                p = p->one;
            }
        }
        cout.put('\t');
        return p->ch;
    }

