#include <iostream>
#include <fstream>
#include <string>
#include "HashTable.h"

void readFile(HashTable& h,int testCases) {

    fstream file("names.txt");
    string names;

    if (file.is_open()) {
        for (int i = 0; i < testCases; i++) {
            getline(file, names);
            h.insert(names);
        }
    } 
    else
        cout << "FALSE: File could not be opened." << endl;
}

int main() {
    
    int testCases;
    cin >> testCases;
    
    HashTable h(testCases);

    readFile(h, testCases);

    h.print();
    h.calculateColissions();

    return 0;
}