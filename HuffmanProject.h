/*
Code by Karan Budhathoki, Leslie Delval, Prem Adhikari
*/
#include <iostream>
using namespace std;

class huffman {

private:
struct nodeType// nodeType is private
{
    //variable declarations
        char ch;
        int weight;
        struct nodeType* next;
        nodeType* one, * zero;

//contructor initializer
        nodeType() {
            ch = char(2);
            weight = 0;
            next = NULL;
            zero = NULL;
            one = NULL;
        }
    };
nodeType* root;
nodeType** arr;// pointer to an array pointer
void alt_printTree(nodeType* p, int level);
void put(nodeType* p);
bool isThere(nodeType* p, char myCh);

// functions used in the public of class huffman
public:
huffman();
void createArray();
void printArray();
void createLinkedList();
void printLinkedList();
void createTree();
void printTree();
void encode(char ch);
char decode(char* d);


};