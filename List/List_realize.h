#pragma once
#include "List.h"

template<class T>
Node<T>* List<T>::GetElem(size_t ind)
{
	if (ind > count)
		return nullptr;
	int i{};
	auto begin = Head;
	while (i++ < ind)
		begin = begin->next;
	return begin;
}

template<class T>
void List<T>::Print(size_t pos)
{
	auto temp = GetElem(pos);
	if (temp != nullptr)
		cout << temp->data;
}

template<class T>
void List<T>::Print()
{
	auto begin = Head;
	while (begin != nullptr)
	{
		cout << begin->data << " ";
		begin = begin->next;
	}
}

template<class T>
void List<T>::AddHead(T value)
{
	Node<T>* element = new Node<T>;
	element->data = value;
	element->prev = nullptr;
	element->next = Head;

	if (Head == nullptr)
		Head = Tail = element;
	else
	{
		Head->prev = element;
		Head = element;
	}
	++count;
}

template<class T>
void List<T>::AddTail(T value)
{
	Node<T>* element = new Node<T>;
	element->data = value;
	element->prev = Tail;
	element->next = nullptr;

	if (Tail == nullptr)
		Head = Tail = element;
	else
	{
		Tail->next = element;
		Tail = element;
	}
	++count;
}

template<class T>
void List<T>::Insert(T value, size_t pos)
{
	if (pos > count)
		return;
	else if (pos == count)
		AddTail(value);
	else if (pos == 0)
		AddHead(value);
	else
	{
		auto temp = GetElem(pos);
		Node<T>* element = new Node<T>;

		element->data = value;
		element->next = temp;
		element->prev = temp->prev;

		temp->prev->next = element;
		temp->prev = element;
		++count;
	}
}

template<class T>
void List<T>::Del(size_t pos)
{
	if (pos > count - 1)
		return;
	auto del = GetElem(pos);
	auto after_del = del->next;
	auto prev_del = del->prev;

	if (del != Head)
		prev_del->next = after_del;
	if (del != Tail)
		after_del->prev = prev_del;
	if (pos == 0)
		Head = after_del;
	if (pos == count - 1)
		Tail = prev_del;
	delete del;
	--count;
}

template<class T>
void List<T>::DelAll()
{
	while (count != 0)
		Del(0);
}

template<class T>
List<T>::List(const List<T>& copy)
{
	Head = Tail = nullptr;
	count = 0;
	Copy(copy);
}

template<class T>
List<T>& List<T>::operator = (const List<T>& copy)
{
	if (this == &copy)
		return *this;

	DelAll();
	Copy(copy);
	return *this;
}

template<class T>
List<T> List<T>::operator + (const List<T>& copy)
{
	List<T> result{ *this };
	result.Copy(copy);
	return result;
}

template<class T>
void List<T>::Copy(const List<T>& copy)
{
	for (auto i{ copy.Head }; i != nullptr; i = i->next)
		AddTail(i->data);
}

template<class T>
List<T> List<T>::operator - ()
{
	List<T> result;
	for (auto i{ Head }; i != nullptr; i = i->next)
		result.AddHead(i->data);
	return result;
}
