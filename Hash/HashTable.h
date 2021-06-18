#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class HashTable {

public:
    HashTable();
    HashTable(int);
    int getSize();
    void insert(string);
    void search(string);
    void remove();
    void print();
    void calculateColissions();
    ~HashTable();

private:
    int hashFunction(string);
    vector<string> table;
    int size;
    int collisions;
};