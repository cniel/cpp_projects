#include "StringServices.h"

using namespace std;

void StringServices::encadre(string s)
{
	int len = s.size();
	
	cout << "|";
	for (int i=0; i<len*2; i++)
		cout << "=";
	cout << "|\n";
	
	cout << "|";
	for(int i=0; i<len/2; i++)
		cout << " ";
	cout << s;
	for(int i=0; i<len/2; i++)
		cout << " ";
	cout << "|\n";
	
	cout << "|";
	for (int i=0; i<len*2; i++)
		cout << "=";
	cout << "|\n\n";
}
