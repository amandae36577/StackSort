//Amanda Esposito
//Definition of stack functionality
#include <iostream>
#include <string>
#include "Stack.h"

using namespace std;

/*
* @post top = -1
*/
Stack::Stack()
{
	top = -1;
}
/*
* @post 
* @return the item on the top of the stack
* returns the value on the top of the stack
*/
T Stack::Top() const
{
	if (IsEmpty())
		throw EmptyStack();
	return items[top];
}
/*
* @pre IsEmpty == false
* @post true is top = #top - 1 
*/
void Stack::Pop() // gets rid of the value on top of the stack
{
	if(IsEmpty())
		throw EmptyStack();
	top--;
}
/*
* @pre IsFull == false
* @post true is top = #top + 1 
* @param is of type T
*/
void Stack::Push(T newItem)
{
	if (IsFull())
		throw FullStack();
	top++;
	items[top] = newItem;
}
/*
* @post true is top == -1
* @return if the stack is empty
*/
bool Stack::IsEmpty() const
{
	return (top == -1);
}
/*
* @post true is stack == MAX_ITEMS
* @return if the stack is full
*/
bool Stack::IsFull() const 
{
	return (top == MAX_ITEMS-1);
}


