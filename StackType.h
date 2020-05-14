#include <iostream>
#include <string>

using namespace std;

class FullStack{};

class EmptyStack{};
const int MAX_ITEMS=15; //max items in the list can be 15

typedef int T;
class StackType // declares the stacks functions
{
	public: 
		StackType(); //constructer 
		bool IsEmpty() const;
		void Push(T item);
		void Pop();
		T Top() const;
		bool IsFull() const;

	private: //variable declerations
		int top;
		int items[MAX_ITEMS];
};


