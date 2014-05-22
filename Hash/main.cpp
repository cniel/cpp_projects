#include <iostream>
#include <string.h>
#include <cstdlib>

#include "Hash.h"

using namespace std;


int main(int argc, char** argv)
{

	Hash Hashy;
	
	string name = "";
	
	Hashy.AddItem("Paul","malibu");
	Hashy.AddItem("Annie", "vodka");
	Hashy.AddItem("Emma", "rhum");
	Hashy.AddItem("Celine", "passoa");
	Hashy.AddItem("Robert", "beer");
	Hashy.AddItem("Jerem", "water");
	
	
	Hashy.PrintTable();
	/*
	Hashy.PrintItemsInIndex(5);
	Hashy.PrintItemsInIndex(2);
	Hashy.PrintItemsInIndex(4);
	*/

	while(name != "exit")
	{
		cout << "Remove for ";
		cin >> name;
		if(name != "exit")
			Hashy.RemoveItem(name);
	}
	
	
	return 0;
}
