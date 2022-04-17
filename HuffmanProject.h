#include <iostream>
using namespace std;

class huffman {

private:
struct nodeType
{
        char ch;
        int weight;
        struct nodeType* next;
        nodeType* one, * zero;

        nodeType() {
            ch = char(2);
            weight = 0;
            next = NULL;
            zero = NULL;
            one = NULL;
        }
    };
nodeType* root;
nodeType** arr;
void alt_printTree(nodeType* p, int level);
void put(nodeType* p);
bool isThere(nodeType* p, char myCh);


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