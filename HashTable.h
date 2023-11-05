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
	    delete[] dataTable;
    }


    void insert(const DataType& newDataItem, const KeyType& key){

    }

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

#endif // ifndef HASHTABLE_H
