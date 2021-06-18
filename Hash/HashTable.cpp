#include "HashTable.h"

HashTable::HashTable()
    :size(0), collisions(0) {}

HashTable::HashTable(int s) : collisions(0) {
    size = s;
    table.resize(size);
}

int HashTable::getSize() {
    return size;
}

void HashTable::insert(string n) {
	int index = hashFunction(n);

    if (table[index].empty())
        table.insert(table.begin() + index, n);
    else {
        table.push_back(n);
        collisions++;
    }
        
}

void HashTable::search(string) {
	
}

void HashTable::remove() {
	
}

void HashTable::print() {

	for (int i = 0; i < table.size(); i++) 
        cout << table[i] << " "; 
    cout << endl; 
}

void HashTable::calculateColissions() {
	cout << "Colisiones: " << (float(collisions)/float(size))*100 << "%" << endl; 
}

HashTable::~HashTable() {
	
}

int HashTable::hashFunction(string key) {

    int index;

    index = index + key.length();

	for (int i = 0; i < key.length(); i++) {
        char x = key.at(i);
        int index = index + int(x);
    }

    return index;
}