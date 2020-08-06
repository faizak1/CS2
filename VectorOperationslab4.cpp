/* Lab4: working with sorted array
 * Author: Faiza Khan 
 * Last modifed on: 3/1/18
 * Known bug:
 * Note: Please use assert to check for precondtition */
#include <iostream>
#include <assert.h>
#include <vector>
#include <string>
using namespace std;


/* Displays the content of a vector<string>,
   @param vector<string>: gives the vector<string> to be displayed
*/
void DisplayVector (vector<string> vstrings);


/*
  Binary search a vector of string for a given value, return true if found, false if not found 
  the index or would-be index of the value will be set to param index
   @param vstrings: gives the vector<string> to be displayed
   @param value: the value we are looking for 
   @param index: upon return, store the index of the occurence of the value (if found),
		or the would-be index of the value (if it's not found) 
   @precondition: vector contains vector.size() number of values in asceoding order 
   @postcondition: if value appeared in the array, its index is returned; otherwise -1 is returned 
*/
bool BinarySearch (vector<string> vstrings, string value, int & index);


/* 
 Deletes (i.e., removes) the element stored in the specified position from the SORTED vector, the 
 vector should be sorted afterwards
   @param vector: gives the vector to be deleted from
   @param index: we want to delete the {index}-th position in the vector 
   @precondition: vector contains vector.size() number of values in asceoding order 
        index < vector.size()
   @postcondition: if value stored in {index}-th position will be removed, the vector is still sorted. 
           vector.size() is decreased by 1
*/
void Delete (vector<string>& vstrings, int index);

/*
 * Deletes (i.e., removes) the element value by first searching for it and then deleting
 * if found. Uses BinarySearch(vector<string> vstrings, string value, int &index) to get
 * the index to pass into Delete(vector<string>, int index).
 * @param vector: gives the vector to be deleted from
 * @param string: we want to delete this value from the vector.
 * @precondition: vector contains vector.size() number of values in ascending order
 * @postcondition: if value is stored in vector, it will be removed, the vector will still be sorted.
 * 		vector.size() is decreased by 1.
 */
void Delete (vector<string>& vstrings, string value);


/* 
  inserts a value into an sorted vector so that the vector remains sorted,
  i.e., the value should be inserted before the first value that is 
  larger than it.  If the vector's content is "ann" "becky" "charlotte" "karen",
  and the value to be inserted into the vector is "julie", it should be put right
  before "karen", and the resulting vector should be "ann" "becky" "charolette"
  "julie" "karen" (assume all input is converted to lower case)
  @param vstrings: the vector that the value is to be inserted into
  @param value: the value to be inserted 
  @return: the index of the value in the vector 
  @precondition: vector.size() < vector.capacity() grow the vector 
  @postcondition: value is inserted into the vector, and the vector is sorted 
             vector.size() is incremented by 1.
 */ 
int InsertByValue (vector<string>& vstrings, string value);


int main()
{
 	// As the NumArray can be partially filled, we use variable NumArraySize to keep track of how many numbers
	// have been stored in the array. 
	vector<string> vstrings;	// a string vector 
	int index;
	string value; 

	//1. Fill vector<string> with data in sorted order 
	//       Display the array afterwards 
	// Create a sorted array 
	string temp_str;
	do {
		cout << "Enter another name or -1 to end input: ";
		cin >> temp_str;
		if (temp_str != "-1") {
			InsertByValue(vstrings, temp_str);
		}
 	} while (temp_str != "-1");

	DisplayVector(vstrings);


  //2. TODO: Prompt the user to enter a value to search for, search for the value, and 
  // report the result 
  	string search;
	cout << "Enter a name to search : " << endl;
	cin  >> search;
	
	
	if (BinarySearch (vstrings, search, index)== true)
		{	
			cout << search << "   was found at position " << index +1 << endl;
			return index;
		}
	else 
		cout << "Name was not found!" << endl;
	
  // 3. ToDo: Call your function to insert a value (entered by the user) into the vector
  // Display the content of the vector afterwards 
	InsertByValue(vstrings, search);
	DisplayVector(vstrings);

  // 4. ToDo: Prompt the user to enter an index (for the value to be deleted), and then delete the elements 
  //   stored there. 
  // Display the content of the vector after the deletion. 
	cout << "Enter the position in the vector you would like to delete : " << endl;
	cin >> index;
	Delete(vstrings, index);
	DisplayVector(vstrings);

  // 5. ToDo: Prompt the user to enter an value in the vector (to be deleted), and then delete the element 
  // Display the contents of the vector after the deletion.
	cout << "Enter the value you would like to delete : " << endl;
	cin >> value;
	Delete(vstrings, value);
	DisplayVector(vstrings);
} 

/* Displays the content of a vector<string>,
   @param vector<string>: gives the vector<string> to be displayed
*/
void DisplayVector (vector<string> vstrings)
{
	for (int i=0; i<vstrings.size(); i++) 
 	{
		cout << vstrings[i] << "   " << endl;
	}
	// uses for-loop to iterate and display. BONUS: Use iterator vstrings.begin and vstrings.end
}


/*
  Binary search a vector of string for a given value, return true if found, false if not found 
  the index or would-be index of the value will be set to param index
   @param vstrings: gives the vector<string> to be displayed
   @param value: the value we are looking for 
   @param index: upon return, store the index of the occurence of the value (if found),
		or the would-be index of the value (if it's not found) 
   @precondition: vector contains vector.size() number of values in asceoding order 
   @postcondition: if value appeared in the array, its index is returned; otherwise -1 is returned 
*/
bool BinarySearch (vector<string> vstrings, string value, int& index)
{
	int first=0;
	int last= vstrings.size() -1;
	index= (last+first) /2;  // index represents the middle value
	do
	{
		if (vstrings[index]<value)  
		{
			first=index+1;
		}
		else if (vstrings[index]==value)
		{
			return true; // returns true if the value is found in the search 
		}
		else 
		{
			last=index-1;  
		}
		index=(last+first)/2;

	} while (first <= last);
	index = -1;
	return false;	// returns false if the value is not found
}

/* 
 Deletes (i.e., removes) the element stored in the specified position from the SORTED vector, the 
 vector should be sorted afterwards
   @param vector: gives the vector to be deleted from
   @param index: we want to delete the {index}-th position in the vector 
   @precondition: vector contains vector.size() number of values in asceoding order 
        index < vector.size()
   @postcondition: if value stored in {index}-th position will be removed, the vector is still sorted. 
           vector.size() is decreased by 1
*/
void Delete (vector<string>& vstrings, int index)
{
	if (index>=0 && index<=vstrings.size()-1) 
	{	
		vstrings.erase(vstrings.begin()+index);
	}	
	// uses vector.erase(index)
}

/*
 * Deletes (i.e., removes) the element value by first searching for it and then deleting
 * if found. Uses BinarySearch(vector<string> vstrings, string value, int &index) to get
 * the index to pass into Delete(vector<string>, int index).
 * @param vector: gives the vector to be deleted from
 * @param string: we want to delete this value from the vector.
 * @precondition: vector contains vector.size() number of values in ascending order
 * @postcondition: if value is stored in vector, it will be removed, the vector will still be sorted.
 * 		vector.size() is decreased by 1.
 */

void Delete (vector<string>& vstrings, string value)
{
	
	int index;
	bool Search = BinarySearch(vstrings, value, index); 

	if (Search==true)
	{
		Delete(vstrings, index);
	}
	// BinarySearch to get index and vector.erase(index) to
	// delete.
}


/* 
  inserts a value into an sorted vector so that the vector remains sorted,
  i.e., the value should be inserted before the first value that is 
  larger than it.  If the vector's content is "ann" "becky" "charlotte" "karen",
  and the value to be inserted into the vector is "julie", it should be put right
  before "karen", and the resulting vector should be "ann" "becky" "charolette"
  "julie" "karen" (assume all input is converted to lower case)
  @param vstrings: the vector that the value is to be inserted into
  @param value: the value to be inserted 
  @return: the index of the value in the vector 
  @precondition: vector.size() < vector.capacity() grow the vector 
  @postcondition: value is inserted into the vector, and the vector is sorted 
             vector.size() is incremented by 1.
 */ 
int InsertByValue (vector<string>& vstrings, string value)
{
	// Uses for-loop to find the vector enter that is greater than value
	// if we get to the end, do vector.push_back(value) otherwise use
	// vector.insert(vector.begin()+index, value);
	// empty
	if(vstrings.empty())
	{
		vstrings.push_back(value);
		return 0;
	}

	// middle
	for(int i = 0; i < vstrings.size(); i++)
	{
		if(vstrings[i] > value)
		{
			vstrings.insert(vstrings.begin() + i, value);
			return i;
		}
	}	

	// end
	vstrings.push_back(value);
	return vstrings.size() - 1;
}
	
// extenstion on the lab (not a part of the code)
/*
Hi Faiza,

In this context, an iterator is not a for-loop. It is what is returned from vstrings.begin(). Add that to i as the argument to erase.

I will be in my office at 1:30 tomorrow. Stop by if you still need help.

Regards,
Julie Harazduk */	
