#include <iostream>
#include <string.h>

#include "ListOfInt.h"

using namespace std;

int main(int argc, char** argv)
{
	ListOfInt my;
	
	my.Append(3);
	my.Unshift(2);
	my.Unshift(1);
	my.Append(4);
	my.Append(2);
	my.Append(2);
	
	my.Display();
	
	my.RemoveAll(2);
	my.Display();

	my.Pop();
	my.Display();
	
	my.RemoveFirst(3);
	my.Display();
	
	my.RemoveFirst(4);
	my.Display();
	
	my.RemoveFirst(1);
	my.Display();
	
	return 0;
}