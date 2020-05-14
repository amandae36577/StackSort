#include <iostream>
#include<fstream>
#include "StackType.h"
#include "sorting.h"

using namespace std;

void insert(ifstream& In, StackType& Stack, ofstream& Out); //Will insert the input into the stack out of order
void Print(ofstream& Out, StackType& Stack); // will print out the final stack
void Sort(StackType& stack); //empties the stack
void Sorted(StackType& stack, int hold); // inserts correct values into the stack in order

int main() 
{

        ifstream inFile; // declaring the input and outputs
        ofstream outFile;

        inFile.open("input.txt"); // input will take from the input.txt file

        outFile.open("output.txt"); // output will be placed int the output.txt file

        if(inFile.fail()) // exits the program if the first input is invalid
        {
                cout << "The input failed" << endl;
                exit(1);
        }
        if(outFile.fail()) // exits the program if the output is invaid
        {
                cout << "The output failed" << endl;
                exit(1);
        }

    StackType myStack; //The stack being used

    outFile << "Not Sorted" << endl; // prints out
    insert(inFile, myStack, outFile); //calls the function to insert values into a stack

  Sort(myStack); // calls the sorting function

    outFile << "Sorted" << endl; //prints out
   Print(outFile, myStack); //prints out the sorted stack
    
//closes the files
inFile.close();
outFile.close();

return 0;
}

//Recursive function defintions
void insert(ifstream& In, StackType& Stack, ofstream& Out)
{
    int input;
    if(!In.eof()) // do the following code if not at the end of the input file
    {
    In >> input; //takes in the values
    Out << input << endl; // prints out the values not in order
    Stack.Push(input); //adds the value to the stack
    return insert(In, Stack, Out); //calls itself
    }     
    
}

void Print(ofstream& Out, StackType& Stack) //prints out the stack when called
{
  if(!Stack.IsEmpty())
  {
    int hold = Stack.Top();
    Stack.Pop();
    Out << hold << endl;
    return Print(Out, Stack);
  }

}

void Sort(StackType& stack) //takes the numbers out of the stack using recursion  (first step in a double recursion)
{
  if(stack.IsEmpty()) //if the stack is empty return back to main
  return;

  int top = stack.Top(); //set top to the top of the stack
  stack.Pop(); //pop the top of the stack

  Sort(stack); //calls Sort until the base case, and tracks the tops value for each function call  

	Sorted(stack, top); //is called during backtracking for sort (like the cout in the RevPrint function), sending the currect top value to sorted
			    //when sorted returns to the sort function, sort backtracks to the pervious function call 
}
void Sorted(StackType& stack, int hold) //helps to place the numbers back in the stack in order using recursion (second step in a double recursion)
{
  if(stack.IsEmpty() || hold > stack.Top()) //if the hold value is greater than the current top value then do the following
  {
    stack.Push(hold); //add the hold value back into the stack
    return; //return to sort
  }

  int top = stack.Top(); //if the value in the top of the stack is greater than hold, top is made to equal to the stacks top because it must be removed
  stack.Pop(); //takes the top value of the stack out

  Sorted(stack, hold); /*continues to call sorted and take values out of the stack until the hold value being passed from sort is less than the top of the
 stacks value and can be placed on the stack*/

  stack.Push(top); /*back tracks through the function calls and elements taken out of the stack, putting them back in from the most recent taken out to the 
earliest taken out of the stack*/ 
}
