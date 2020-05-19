//Amanda Esposito
//Definition of stack functionality
#include <iostream>
#include <string>
#include "Stack.h"

using namespace std;

Stack::Stack()
{
	size = -1;
}

void Stack::Pop() 
{
	if(IsEmpty())
		throw EmptyStack();
	size--;
}

void Stack::Push(T newItem)
{
	if (IsFull())
		throw FullStack();
	size++;
	items[size] = newItem;
}

bool Stack::IsEmpty() const
{
	return (size == -1);
}

bool Stack::IsFull() const 
{
	return (size == MAX_ITEMS-1);
}

int Stack::Size()
{
	return size+1;
}

T Stack::Top() const
{
	if (IsEmpty())
		throw EmptyStack();
	return items[size];
}
