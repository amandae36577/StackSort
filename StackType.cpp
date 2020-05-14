#include <iostream>
#include <string>
#include "StackType.h"

using namespace std;

StackType::StackType() // constructer setting the top index
{
	top = -1;
}

T StackType::Top() const // returns the value on the top of the stack
{
	if (IsEmpty())
		throw EmptyStack();
	return items[top];
}

void StackType::Pop() // gets rid of the value on top of the stack
{
	if(IsEmpty())
		throw EmptyStack();
	top--;
}

void StackType::Push(T newItem) // puts the item on the top of the stack
{
	if (IsFull())
		throw FullStack();
	top++;
	items[top] = newItem;
}

bool StackType::IsEmpty() const // returns whether the stack is empty
{
	return (top ==-1);
}
bool StackType::IsFull() const // returns whether stack is full
{
	return (top == MAX_ITEMS-1);
}


