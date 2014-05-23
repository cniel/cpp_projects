#include "ListOfInt.h"

using namespace std;


ListOfInt::ListOfInt()
{
	_first=NULL;
	_last=NULL;
	_size = 0;
}

ListOfInt::~ListOfInt()
{
	item* p1 = _first;
	item* p2 = NULL;
	
	while(p1)
	{
		p2=p1;
		p1=p1->next;
		delete(p2);
	}
	_first = NULL;
	_last = NULL;
}

void ListOfInt::Append(int num)
{
	item* n = new item;
	n->num = num;
	n->next = NULL;
	
	if(this->IsEmpty())
	{
		this->Unshift(num);
	}
	else
	{
		_last->next = n;
		_last = n;
		_size++;
	}	
}


void ListOfInt::Unshift(int num)
{
	item* n = new item;
	n->num = num;
	n->next = _first;
	_first = n;
	
	if(_last == NULL) //list was empty before this shift
		_last = _first;
	
	_size++;
}


void ListOfInt::Pop()
{
	if(this->IsEmpty())
		return;
		
	item* p = _first;
	
	while(p->next)
	{
		_last = p;
		p=p->next;
	}
	delete p;
	_last->next = NULL;
	_size--;
}

void ListOfInt::Shift()
{
	if(this->IsEmpty())
		return;
	
	item* p=_first;
	_first = _first->next;
	
	delete p;
	_size --;
}

ListOfInt::item* ListOfInt::RemoveFirst(int num)
{
	//empty list
	if(this->IsEmpty())
		return NULL;
	
	item* p = _first;
	item* prec = _first;
	
	//first elem is the good one
	if(_first->num == num)
	{
		if(_size == 1)
			_last = _last->next;
		
		_first = _first->next;
		delete p;
		_size--;
		
		return _first;
	}
	
	//first elem is not the good one -> listSize > 1 or no match
	while(p != NULL)
	{
		if(p->num == num)
		{
			prec->next = p->next;
			delete p;
			_size--;
			
			return prec->next;
		}
		
		prec = p;
		p = p->next;
	}
	return NULL;
}

void ListOfInt::RemoveAll(int num)
{
	if(this->IsEmpty())
		return;
	
	item* p = _first;
	item* mem = NULL;
	while(p != NULL)
	{
		mem = this->RemoveFirst(num);
		p = mem;
	}
}


int ListOfInt::Locate(int num)
{
	item* p = _first;
	int c = 0;
	while(p)
	{
		if(p->num == num)
			return c;
		c ++;
		p = p->next;
	}
	return -1;
}


bool ListOfInt::IsEmpty()
{
	if(_first == NULL)
		return true;
	else
		return false;
}

void ListOfInt::Display()
{
	item* p;
	if(this->IsEmpty())
	{
		cout << "The list is empty." << endl;
		return;
	}
	
	cout << "ListSize = " << _size << endl;
	for(p=_first; p; p=p->next)
	{
		cout << "num = " << p->num << endl;
	}
	cout << endl;
}

int ListOfInt::GetSize()
{
	return _size;
}
