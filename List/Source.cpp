#include <iostream>
#include <Windows.h>
#include "List.h"

using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	List<int> test;

	test.AddTail(1);
	test.AddTail(3);
	test.AddTail(2);
	test.AddTail(6);
	test.AddTail(8);
	test.Insert(5);
	test.Insert(5);
	test.Insert(5);
	test.Insert(5);
	test.Del();
	//test.DelAll();
	List<int> test2;
	test2 = test;
	test.Print();
	cout << endl;
	test2.Print();

	cout << endl;
	cout << test.GetElem(0);
	cout << endl;
	cout << test2.GetElem(0);
	cout << endl;
	(test + test2).Print();
	cout << endl;
	(-test).Print();
	//test.Print();
	
	return 0;
}