#include <iostream>
#include <string.h>
#include <cstdlib>

using namespace std;

#ifndef HASH_H
#define HASH_H

class Hash{

private:
	static const int tableSize = 128;

	struct item{
		string name;
		string drink;
		item* next;
	};
	
	item* HashTable[tableSize];
	

public:
	/*
	 * Return the index integer of the HashTable
	 * */
	int HashFunction(string key);
	
	/*
	 * Store a item
	 * */
	void AddItem(string name, string drink);
	
	/*
	 * Count items clustered in an index
	 * */
	int CountItemsInIndex(int index);
	
	/*
	 * Print function without going through collision lists
	 * */
	 void PrintTable();
	 
	 /*
	  * Print items of a collision list
	  * */
	 void PrintItemsInIndex(int index);
	 
	 /*
	  * input : name
	  * Ouput : drink
	  * */
	 void FindDrink(string iname);
	 
	/*
	 * Remove an item in the HashTable, from a given name
	 * */
	 void RemoveItem(string iname);
	
	Hash();
};

#endif
