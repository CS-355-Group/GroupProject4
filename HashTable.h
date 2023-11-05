// HashTable.h

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "LinkedList.h"
#include <stdexcept>
#include <iostream>

using namespace std;

template <typename DataType, typename KeyType>
class HashTable {
public:
    HashTable(int initTableSize);

    HashTable(const HashTable& other);

    HashTable& operator=(const HashTable& other);

    ~HashTable();

    void insert(const DataType& newDataItem, const KeyType& key);

    bool remove(const KeyType& deleteKey);

    bool retrieve(const KeyType& searchKey, DataType& returnItem) const;

    void clear();

    bool isEmpty() const;

    void showStructure() const;

private:
    void copyTable(const HashTable& source);

    int tableSize;
    LinkedList<DataType, KeyType>* dataTable;
};


HashTable(int initTableSize) {
	tableSize = initTableSize;
	dataTable = new LinkedList<DataType, KeyType>[tableSize];
}

HashTable(const HashTable& other) {
	copyTable(other);
}

HashTable& operator=(const HashTable& other) {
    if(this != other) {
	delete[] dataTable;

	tableSize = other.tableSize;

	dataTable = new LinkedList<DataType, KeyType>* [tableSize];

	for(int i = o; i < tableSize; i++) {
		dataTable[i] = other.dataTable[i];
	}
    }
    return *this;
}

~HashTable() {
	dataTable.clear();
}


void insert(const DataType& newDataItem, const KeyType& key){
	
}
	
bool remove(const KeyType& deleteKey) {
    int index = hash(deleteKey);
	
    //Make sure bucket is not empty
    if (dataTable[index].isEmpty()) {
	return false;
    }

    //Call remove function from the linked list in the correct index
    if(dataTable[index].remove(deleteKey)) {
	return true;
    }

    //Key was not found
	return false;
    }

    bool retrieve(const KeyType& searchKey, DataType& returnItem) const {
	
    }

    void clear() {
	
    }
#endif // ifndef HASHTABLE_H
