/* Lab5: Practice using struct and dynamic arrays 
 * Author: Faiza Khan
 * Last modifed on: 3/5/18
 * Known bug:
 * Note: Please use assert to check for precondtition */

#include <iostream>
#include <assert.h>
using namespace std;

//Define a struct type, each struct type variable has three 
// member variables: array, capacity, and length. Together these
// three variables represent a partially filled array.
struct Array {
	int * array;  // point to the dynamically allocated array 
	int capacity; // the capacity of the array 
	int length;	// the number of elements in the array 
			// the array is filled from 0th, 1st, ... (length-1)-th
			// spots 
};


/* Initialize the array structure with the given numbers.
 * the array's capacity will be twice the length of numbers array 
 @param array: the array struct to be initialized
 @param numbers: the array of values to be stored in the array struct
 @param numbers_len: how many numbers are there in the array numbers
 precondition: "numbers" has been filled with "numbers_len" number of ints
 post condition: a.length == numbers_len
                 a.array[0]==numbers[0],..., 
		 a.capacity = 2*numbers_len
*/
void InitArray (Array & a, int numbers[], int numbers_len); 

/* Displays the content of an int array, both the array and 
   the length of array will be passed as parameters to the function 
   @param array: gives the array to be displayed
*/
void DisplayArray (const Array & a);

//Extra Credit Part: Implement this function, and test in main 
/* Read a sequence of int from input, and store them in the given Array 
 *  variable; we overwrite any existing content of the Array variable
 @param array: the Array variable that is used to store the numbers
 Note: you should allow the user to enter any many numbers as they want,
 the number sequence will be ended with a special value of -1 
 This means that you have to "grow" your array variable when needed 
*/
void InitArrayFromInput (Array & a); 

/* Merge the contents of two arrays into one
 @param array1: the target array
 @param array2: the source array
 @precondition: array1 and array2 have been set up 
 @postcondition: array1.length = array1.length+array2.length;
                 array1 contains its previous numbers, followed by numbers
		from array2 
 Note: if array1's capacity is not enough to hold all numbers, 
   you need to allocate a new int array, and copy old data over to the 
   new array... 
*/
void MergeArray (Array & a1, const Array & a2);



int main()
{
	int numbers1[5]={12, 23,34,56,78};
	int numbers2[11]={89, 7,14,22,98, 101, 112, 34, 11, 5, 99};

	Array NumArray1={NULL,0,0};	//Declare a Array variable, and initilize its member variables 
	Array NumArray2={NULL,0,0};	//Declare another Array variable, and initialize its member variables 

	cout <<"***** NumArray1:\n";
	DisplayArray(NumArray1);
	cout <<"***** NumArray2:\n";
	DisplayArray(NumArray2);

	InitArray (NumArray1, numbers1, 5);	//Now initialize the two Array variables with numbers from two static arrays
	InitArray (NumArray2, numbers2, 11);

	cout <<"***** NumArray1:\n";
	DisplayArray(NumArray1);

	cout <<"***** NumArray2:\n";
	DisplayArray(NumArray2);

	MergeArray (NumArray1, NumArray2);

	cout <<"***** After merge:\n";
	cout <<"***** NumArray1:\n";
	DisplayArray(NumArray1);
}

//ToDo: Please implement all functions declared above 


/* Initialize the array structure with the given numbers.
 * the array's capacity will be twice the length of numbers array 
*/
void InitArray (Array & a, int numbers[], int numbers_len)
{
   // 1. Dynamically allocate an int array of size given by numbers_len*2
   //    and stores its address in a.array
   //    Set a.capacity 
   int *array = new int [numbers_len*2];
	for (int i=0; i<numbers_len; i++)
	{
		array[i]=numbers[i];
	}
   // 2. Copy the int numbers from array numbers to a.array
	a.array=array;	

	a.length=numbers_len;

   // 3. set a.size 

	a.capacity=numbers_len*2;
}

void MergeArray (Array & a1, const Array & a2)
{
    //If a1.array is not big enough to hold all data 
    if (a1.length + a2.length > a1.capacity) 
    { 
	//1. Allocate a new dynamic int array that is big enough
	//  you can make its size be a1.length+a2.length+10 
	
	int *array = new int [a1.length+a2.length+10]; 
	for (int i=0; i<a1.length; i++)
	{
	// 2. copy numebrs from a1.array to this new array 
		array[i]=a1.array[i];
	}
    	// 3. free the current a1.array 
	delete a1.array;
    	//4. make a1.array points to the new array 
	a1.array=array;
    	//5. set a1.capacity to the new array's capacity
	a1.capacity=a1.length+a2.length+10;
    }

	for (int i=0; i<a2.length; i++)
	{
    	//Todo: append a2.array's data into a1.array  
		a1.array [a1.length+i] = a2.array [i];
	}

    	//Todo: update a1.length 
	a1.length += a2.length;
     
}

void DisplayArray (const Array & a)
{
	for (int i=0; i<a.length; i++)
	{
		cout << a.array[i] << "  ";
	}

	cout << endl;	


/* Displays the content of an int array, both the array and 
   the length of array will be passed as parameters to the function 
   @param array: gives the array to be displayed
*/
}
