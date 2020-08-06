// Working with arrays and functions
// Author: Faiza Khan
// Last modified on: January 31, 2018

#include <iostream>

using namespace std;

const int CAPACITY=20;

//TODO: Declare a function that displays the content of an int array, 
//both the array and the size of array will be passed as parameters to the function 
int display(int[], int);

//TODO: Declare a function that searches for a value in a given int array, it returns 
//-1 if the value does not occur in the array; if the value occurs in the array,
// the function returns the index of its first occurance. 
int search(int array[],int size, int value);

//TODO: Declare a function that deletes the element stored in a specified position from the array
int delete_value(int array[], int& size, int position);

/* 
  inserts a value into a given position in an array of int
   if the given position is occupied, that number and its subsequent numbers will
   shifted to the right of the array.  
  @param array: the int array that the value is to be inserted into
  @param array_size: the current size of the array. Upon successful 
                    insertion, the array_size will be increased by 1 
  @param value: the value to be inserted 
  @param index: the value is supposed to be inserted into the given index 
  @return -1 if the array is already full, cannot insert a new value
          otherwise, return the index of the new value in the array
  @precondition: index is less than array_size 
 */ 
int insert_value(int array[], int& size, int position, int value);

//TODO: Declare a function that swaps two vaues. Remember to use call-by-reference. 
void swap_values(int array[], int size, int value);

// TODO: Declare a function that reverses an array.

int reverse_values(int array[], int& size);

int main()
{
    // As the NumArray can be partially filled, we use variable NumArraySize to keep track of how many numbers
    // have been stored in the array. 
    int NumArray[CAPACITY];	// a int array with a given capacity
    int NumArraySize=0;  // the array is initially empty, i.e., contains 0 elements
   
    //1. TODO: Prompt the user to enter a sequence of integer values, separated by space, and ended with -1,
    //        and store the values in the array 
    //       Display the array afterwards 
    cout << "Enter up to " << CAPACITY << " values or -1 to exit" << endl;

    int next;	

    do
    {
  	 cin >> next;
	if (next!=-1) NumArray[NumArraySize++]=next;
	
    } while (next!=-1 && NumArraySize <= CAPACITY);

    display(NumArray, NumArraySize);


    // 2. TODO: Call your function to search for value 50. 

    int index=search(NumArray, NumArraySize, 50);
    cout << index << endl;
    if (index==-1)	
	cout << "50 was not found" << endl;
    else
	cout << "50 was found at position " <<index << endl;
 
    // 3. Call your function to append a value (entered by the user) to the array 
    //       Display the content of the array afterwards 

    display(NumArray, NumArraySize);

    // 4. Call your function to insert a value (entered by the user) to a given position (entered by the user) 
    // of the array 
    // Display the content of the array afterwards 
    int value, position;
    cout << "What value do you want to insert?" << endl;
    cin >> value;
    cout << "Which position would you like to insert this value? "<< endl;
    cin >> position;
    insert_value(NumArray, NumArraySize, position, value);
    // 5. Call your function to delete the values stored in position 0 and 2
    display(NumArray, NumArraySize);
    delete_value(NumArray, NumArraySize, 2);
    display(NumArray, NumArraySize);
    delete_value(NumArray, NumArraySize, 0);

    // Display the content of the array after the deletion. 
    display(NumArray, NumArraySize);
  
    // 6. Call your function to reverse the array.
    reverse_values(NumArray, NumArraySize);
    display(NumArray, NumArraySize);

}

// TODO: implement all functions (after declaring them in main, I wrote the code for each below)

int display(int array[], int size){

	for (int i=0; i<size; i++)
	{
		cout << array[i]<< ", ";
	}
	cout << endl;

}

int delete_value(int array[], int& size, int position)
{
	for (int i=position; i<size; i++)
	{
		array[i]=array[i+1];
	}
	size=size-1;
}

int insert_value(int array[], int& size, int position, int value)
{
	if (position +1 > size)
		cout << "Invalid position!" << endl;

	for(int i = size; i >= position; i--)
	{
		array[i+1] = array[i];
	} 
	array[position]=value;
	size++;
}

void swap_values(int array[], int size, int a, int b)
{
	int temp = array[a];
	array[a]=array[b];
	array[b]=temp;
}

int reverse_values(int array[], int& size)
{
	int halfSize = size/2;
	for (int i = 0; i < halfSize; i++)
	{

		swap_values(array, size, i, size-i-1);
	}
}

int search(int array[], int size, int value)
{
	for (int i=0; i<size; i++)
	{
		if (array[i]==value)
			return i;
	}
	return -1;
}
 

