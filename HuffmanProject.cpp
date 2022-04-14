/*
Code by Karan Budhathoki, Leslie Delval, Prem Adhikari
*/




#include <iostream>
using namespace std;
#include <fstream>

const int MAX = 256;
class huffman {
private:
    struct nodeType {
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

    void alt_printTree(nodeType* p, int level) {
        if (p) {
            cout << p->ch << '\t' << p->weight << "\t" << level << endl;
            alt_printTree(p->zero, level + 1);
            alt_printTree(p->one, level + 1);
        }
    }
    void put(nodeType* p) {
        nodeType** dp;
        dp = &root;
        while (*dp && (*dp)->weight <= p->weight) {
            dp = &(*dp)->next;
        }
        p->next = *dp;
        *dp = p;
    }
    bool isThere(nodeType* p, char myCh) {
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
public:
    huffman() {
        root = NULL;
        arr = new nodeType * [MAX];
        for (int i = 0; i < MAX; i++) {
            arr[i] = NULL;
        }
    }
    void createArray() {
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
    void printArray() {
        cout << "\nPrinting the array:\n";
        for (int i = 0; i < MAX; i++) {
            if (arr[i]) {
                cout << arr[i]->ch << '\t' << arr[i]->weight << '\n';
            }
        }
    }
    void createLinkedList() {
        for (int i = 0; i < MAX; i++) {
            if (arr[i]) {
                put(arr[i]);
            }
        }
    }
    void printLinkedList() {
        nodeType* p;
        p = root;
        cout << "\nPrinting the linked list:" << endl;
        while (p) {
            cout << p->ch << '\t' << p->weight << '\n';
            p = p->next;
        }
    }
    void createTree() {
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
    void printTree() {
        cout << "\nPrinting the Tree:" << endl;
        alt_printTree(root, 0);
    }

    void encode(char ch) {
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
    char decode(char* d) {
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
};

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
