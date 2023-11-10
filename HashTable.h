//--------------------------------------------------------------------------------
// Braden Harris Wyatt Hooper
// Group Project 4
// CS-355
// 11/9/23
// Implement a hashtable using a linked list
//--------------------------------------------------------------------------------
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

//---------------------------------------------------------------------------------------------------------------------------
// constructor
// input: integer for table size
// return: none
// Description: takes in an integer for the size of table then initializes a table of that type and size
// Author: Wyatt Hooper
template <typename DataType, typename KeyType>
HashTable<DataType, KeyType>::HashTable(int initTableSize) {
	tableSize = initTableSize;
	dataTable = new LinkedList<DataType, KeyType>[tableSize];
}

//---------------------------------------------------------------------------------------------------------------------------
// constructor
// input: integer for table size and a hashtable
// return: none
// Description: takes in an integer for the size of table then initializes a table of that type and size and copies
//	the given hashtable into it
// Author: Wyatt Hooper
template <typename DataType, typename KeyType>
HashTable<DataType, KeyType>::HashTable(const HashTable<DataType, KeyType>& other) {
	copyTable(other);
}

//---------------------------------------------------------------------------------------------------------------------------
// override the assignment operator
// input: hashtable
// return: none
// Description: takes in a hashtable, then makes a deep copy
// Author: Wyatt Hooper
template <typename DataType, typename KeyType>
HashTable<DataType, KeyType>& HashTable<DataType, KeyType>::operator=(const HashTable<DataType, KeyType>& other) {
    if(this != other) {
	delete[] dataTable;

	int tableSize = other.tableSize;

dataTable = new LinkedList<DataType, KeyType>* [tableSize];

	for(int i = 0; i < tableSize; i++) {
		dataTable[i] = other.dataTable[i];
	}
    }
    return *this;
}

//---------------------------------------------------------------------------------------------------------------------------
// destructor
// input: none
// return: none
// Description: deallocates memeory
// Author: Wyatt Hooper
template <typename DataType, typename KeyType>
HashTable<DataType, KeyType>::~HashTable() {
	clear();
}

//---------------------------------------------------------------------------------------------------------------------------
// insert()
// input: a value and a key
// return: none
// Description: accepts a value and key and inserts it into the hashtable
// Author: Braden Harris
template <typename DataType, typename KeyType>
void HashTable<DataType, KeyType>::insert(const DataType& newDataItem, const KeyType& key){
    dataTable->insert(newDataItem, key);
}

//---------------------------------------------------------------------------------------------------------------------------
// remove()
// input: hashtable
// return: bool representing if desired value could be deleted
// Description: takes in a key to be deleted, checks to see if it exists, and if it does then it is deleted
// Author: Wyatt Hooper
template <typename DataType, typename KeyType>
bool HashTable<DataType, KeyType>::remove(const KeyType& deleteKey) {
    //Make sure bucket is not empty
    if (dataTable->isEmpty()) {
	return false;
    }

    //Call remove function from the linked list in the correct index
    if(dataTable->remove(deleteKey)) {
	return true;
    }

    //Key was not found
	return false;
    }

//---------------------------------------------------------------------------------------------------------------------------
// retrieve()
// input: key and value
// return: bool that represents if the value exists
// Description: takes in a key value pair and then searches the table to see if it exists
// Author: Wyatt Hooper
template <typename DataType, typename KeyType>
bool HashTable<DataType, KeyType>::retrieve(const KeyType& searchKey, DataType& returnItem) const {
	return dataTable->retrieve(searchKey, returnItem);
}

//---------------------------------------------------------------------------------------------------------------------------
// clear()
// input: none
// return: none
// Description: clears the hashtable
// Author: Braden Harris
template <typename DataType, typename KeyType>
void HashTable<DataType, KeyType>::clear() {
    dataTable->clear();
    tableSize = 0;
}

//---------------------------------------------------------------------------------------------------------------------------
// isEmpty()
// input: none
// return: bool if empty
// Description: checks to see if the hashtable is empty
// Author: Braden Harris
template <typename DataType, typename KeyType>
bool HashTable<DataType, KeyType>::isEmpty() const{
    return dataTable->isEmpty();    
}

//---------------------------------------------------------------------------------------------------------------------------
// showStucture()
// input: none
// return: none
// Description: displays all key value pairs within the hashtable
// Author: Wyatt Hooper
template <typename DataType, typename KeyType>
void HashTable<DataType, KeyType>::showStructure() const{
	dataTable->showStructure();
}

#endif // ifndef HASHTABLE_H
