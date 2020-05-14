//Amanda Espostio
//Header File for a stack
#include <iostream>
#include <string>

using namespace std;

class FullStack{};
class EmptyStack{};

const int MAX_ITEMS= 100; //max items in the list can be 100

typedef int T; //generic types
class Stack // declares the stacks functions
{
	public: 
		Stack(); //constructer 
		bool IsEmpty() const;
		void Push(T item);
		void Pop();
		T Top() const;
		bool IsFull() const;

	private: //variable declerations
		int top;
		int items[MAX_ITEMS];
};


