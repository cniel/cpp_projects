
#include "Hash.h"

using namespace std;

//--------------------------------------------
//	CONSTRUCTOR
//--------------------------------------------

Hash::Hash()
{
	for(int i=0; i<tableSize; i++)
	{
		HashTable[i] = new item;
		HashTable[i]->name = "empty";
		HashTable[i]->drink = "empty";
		HashTable[i]->next = NULL;
	}
}


//--------------------------------------------
//	METHODS
//--------------------------------------------
int Hash::HashFunction(string key)
{
	int hash = 0;
	int index;
	
	for(size_t i = 0; i < key.length(); i++)
	{
		hash = (hash + (int)key[i])*17;
	}
	
	index = hash % tableSize;
	
	return index;
}

void Hash::AddItem(string iname, string idrink)
{
	int index = HashFunction(iname);
	
	if(HashTable[index]->name == "empty")
	{
		HashTable[index]->name = iname;
		HashTable[index]->drink = idrink;
	}
	else
	{
		item* p = NULL; item* p_prec = NULL;
		item* n = new item;
		
		n->name = iname;
		n->drink = idrink;
		n->next=NULL;

		for(p=HashTable[index]; p; p=p->next)
			p_prec = p;
		p_prec->next = n;
	}
}

int Hash::CountItemsInIndex(int index)
{
	int count = 0;
	
	if(HashTable[index]->name != "empty")
	{
		count++;
		item* p = NULL;
		for(p=HashTable[index]; p; p=p->next)
		{
			count++;
		}
	}
	return count;
}


void Hash::PrintTable()
{
	int number;
	
	for(int i=0; i<tableSize; i++)
	{
		number = CountItemsInIndex(i);
		cout << "------------------------\n";
		cout << "index = " << i << endl;
		cout << HashTable[i]->name << endl;
		cout << HashTable[i]->drink << endl;
		cout << "# of items = " << number << endl;
		cout << "------------------------\n";
	}
}


void Hash::PrintItemsInIndex(int index)
{
	item* p = HashTable[index];
	
	if(p->name == "empty")
		cout << "Index " << index << " is empty.\n";
	else
	{
		cout << "Index " << index << " contains the following items:\n";
		
		while(p)
		{
			cout << "------------------\n";
			cout << p->name << endl;
			cout << p->drink << endl;
			cout << "------------------\n";
			p = p->next;
		}
	}
}


void Hash::FindDrink(string iname)
{
	int index = HashFunction(iname);
	bool foundName = false;
	string drink;
	
	item* p = HashTable[index];	
	
	while(p)
	{
		if(p->name == iname)
		{
			drink = p->drink;
			foundName = true;
		}
		p = p->next;
	}
	
	if(foundName)
		cout << "Favorite drink = " << drink << endl;
	else
		cout << iname << "'s info was not found in the HashTable\n";
	
}


void Hash::RemoveItem(string iname)
{
	int index = HashFunction(iname);
	
	item* pDel=NULL;
	item* p1=NULL;
	item* p2=NULL;
	
	// 1 - IF EMPTY
	if(HashTable[index]->name == "empty" && HashTable[index]->drink == "empty")
		cout << iname << " was not found in the HashTable\n";
	
	// 2 - IF ONLY ONE ITEM CONTAINED & MATCHING NAME
	else if(HashTable[index]->name == iname && HashTable[index]->next == NULL)
	{
		HashTable[index]->name = "empty";
		HashTable[index]->drink = "empty";
	
		cout << iname << " was removed from the Hashtable\n";
	}
	
	// 3 - IF MATCH WITH 1st ITEM, BUT THERE ARE MORE
	else if(HashTable[index]->name == iname)
	{
		pDel = HashTable[index];
		HashTable[index] = HashTable[index]->next;
		delete pDel;
		
		cout << iname << " was removed from the Hashtable\n";
	}
	
	// 4 - IF MORE THAN 1 ITEM, BUT 1st ITEM IS NOT MATCHING
	else
	{
		p1 = HashTable[index]->next;
		p2 = HashTable[index];
		
		while(p1 && p1->name != iname)
		{
			p2 = p1;
			p1 = p1->next;
		}
		
		// 4.1 - no match
		if(p1 == NULL)
			cout << iname << " was not found in the HashTable\n";

		// 4.2 - match
		else
		{
			pDel = p1;
			p1 = p1->next;
			p2->next = p1;
			delete(pDel);
		}
	}
}



















