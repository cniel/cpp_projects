#ifndef LISTOFINT_H
#define LISTOFINT_H


#include <iostream>

using namespace std;

class ListOfInt
{
	
private:

	struct item{
		int num;
		item* next;
	};
	
	item* _first;
	item* _last;
	int _size;

public:
	ListOfInt();
	~ListOfInt();
	
	void Append(int num);
	void Unshift(int num);
	
	void Pop();
	void Shift();
	item* RemoveFirst(int num);
	void RemoveAll(int num);
	
	int Locate(int num);
	
	bool IsEmpty();
	void Display();
	
	int GetSize();
};

#endif
