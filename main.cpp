#include <iostream>
#include<fstream>
#include<stdlib.h>
#include "Stack.h"

using namespace std;

/**
 * @pre valid file for In
 * @pre valid file for Out
 * @post Stack length increased
 * Recursive insertion of values from a file to a stack
 */
void Insert(ifstream& In, Stack& stackValue, ofstream& Out); //Will insert the input into the stack out of order
/**
 * @post Out file will contain the stack
 */ 
void Print(ofstream& Out, Stack& stackValue); // will print out the final stack
/**
 * @pre !Stack.IsEmpty()
 * @return a sorted stack
 */
void SortIt(Stack& stackValue);

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
    Stack myStack; //The stack being used

    outFile << "Not Sorted" << endl; // prints out
    Insert(inFile, myStack, outFile); //calls the function to insert values into a stack
    Print(outFile, myStack); //prints out the sorted stack

	SortIt(myStack); // calls the sorting function

    outFile << "Sorted" << endl; //prints out
	Print(outFile, myStack); //prints out the sorted stack
    
//closes the files
inFile.close();
outFile.close();

return 0;
}

//Recursive insertion of values from a file to a stack
void Insert(ifstream& In, Stack& stackValue, ofstream& Out)
{
    int input;
    In >> input; //takes in the values
    if(!In.eof()) // do the following code if not at the end of the input file
    {		
		stackValue.Push(input); //adds the value to the stack
		return Insert(In, stackValue, Out); //calls itself
    }     
}

void Print(ofstream& Out, Stack& stackValue) //prints out the stack when called
{
	int hold;
	if(!stackValue.IsEmpty())
	{
		hold = stackValue.Top();
		stackValue.Pop();
		Out << hold << endl;
		Print(Out, stackValue);
		stackValue.Push(hold);
	}
}
void SortIt(Stack& stackValue)
{
	int size = stackValue.Size();
	int temp[size], count = size, index = 0, value, temporary;
	//sort values through the use of the array
	for(int track = 0; track < size; track++) 
	{
		value = stackValue.Top();
		if(track != 0)
		{
			index = 0;
			while(temp[index] > value && index < track)
			{
				index++;
			}
			for(int ind = index; ind < track; ind++)
			{
				temporary = temp[ind];
				temp[ind+1] = temporary;
			}
		}
		temp[index] = value;
		stackValue.Pop();
	}
	for(int track = 0; track < size; track++) //add values back to stack
	{
		stackValue.Push(temp[track]);
	}
}
