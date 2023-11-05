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
    HashTable(int initTableSize){
	tablesize = initTablesize;
	dataTable = new LinkedList<DataType, KeyType>* [tableSize];
    }

    HashTable(const HashTable& other){
	copyTable(other);
    }

    HashTable& operator=(const HashTable& other) {
	
	//Cheak to make sure they aren't already the same table    
	if(this != other) {
		//Deallocate the memory before assigning new values
		delete[] dataTable;

		//Match this table size with the other
		tableSize = other.tableSize;

		//Dynamically allocate a new data table
		dataTable = new LinkedList<DataType, KeyType>* [tableSize];

		//Fill values in the new table
		for(int i = 0; i < tableSize; i++) {
			dataTable[i] = other.dataTable[i];
		}
	}
	//Return a reference to this object
	return *this
    }

    ~HashTable() {
	    delete[] dataTable;
    }

    void insert(const DataType& newDataItem, const KeyType& key) {
	
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
