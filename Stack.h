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
		/**
 		* @post top = -1
		* constructer
		*/
		Stack();  
		/**
 		* @post true if size == -1
 		* @post false if size > -1
 		* @return if the stack is empty
		* Returns whether or not the stack is empty
		*/
		bool IsEmpty() const;
		/**
		* @param item is a valid member of T
 		* @pre IsFull == false
 		* @post true is size = #size + 1 
 		* Adds item to the top of the stack
		*/
		void Push(T item);
		/**
 		* @pre IsEmpty == false
 		* @post true is size = #size - 1 
		* gets rid of the value on top of the stack
		*/
		void Pop();
		/**
		* @post true if size == MAX_ITEMS
		* @post false if size != MAX_ITEMS
 		* @return if the stack is full
		* Returns whether or not the stack is full
		*/
		bool IsFull() const;
    		/**
     		* @post Size() = size
     		* @return the amount of elements in the stack (size variable)
     		* returns the size of the stack
     		*/
		int Size();
		/**
		* @pre size > 0
 		* @return the item on the top of the stack
 		* returns the value on the top of the stack
		*/
		T Top() const;

	private: //variable declerations
		int size;
		int items[MAX_ITEMS];
};


