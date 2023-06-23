#pragma once
#include <iostream>

using namespace std;

template<class T>
struct Node
{
	T data;
	Node<T>* next;
	Node<T>* prev;
};

template<class T>
class List
{
private:
	Node<T>* Head;
	Node<T>* Tail;
	size_t count;

public:
	List() :Head{ nullptr }, Tail{ nullptr }, count{0} {}
	List(const List&);
	~List() { DelAll(); }
	size_t GetCount() { return count; };
	Node<T>* GetElem(size_t);
	void DelAll();
	void Del(size_t pos);
	void Del() { Del(count - 1); }
	void Insert(T value, size_t pos);
	void Insert(T value) { Insert(value, count); }
	void AddTail(T value);
	void AddHead(T value);
	void Print();
	void Print(size_t pos);
	List& operator = (const List&);
	//сложение двух списков (дописывание)
	List operator + (const List&);
	//переворачивание списка
	List operator - ();

private:
	void Copy(const List<T>&);
};

#include "List_realize.h"