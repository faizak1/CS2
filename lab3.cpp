/*********************************************************************
 Lab3.cpp

   This program uses dynamic arrays to store login information for
four labs.  Each of the four labs is referenced by the labs[] array
which is indexed from 0-3.  A pointer in the labs[] array then
references a dynamic array that is of size for however many computers
are in that lab.

Written by: Faiza Khan
Last modified on: 2/16/18
Known bugs: 
*********************************************************************/

#include <iostream>
#include <cstdlib>

using namespace std;

// Type definition
typedef int* IntPtr;

// Constants
const int NUMLABS = 4;

// Function prototypes

/*
 Creates the dynamic arrays for the labs.
 @param labs: the array of labs,
 @param labsizes: contains the size (or number of computers) of each lab
  This dictates the size of the dynamic array.
 @precondition: labsize[0] is the # of computers in lab1,
                labsize[1] is the # of computers in lab2, ...
 @postcondition: labs[0] points to lab1's array (of size given by labsize[0])
      labs[1] points to lab2's array (of size given by labsize[1])
        ...
*/

// create arrays allows us to choose the number of computers in each of the 4 labs
// the user can input the size of the labs  
void createArrays(IntPtr labs[], int labsizes[]);

/*
freeArrays:
Releases memory we allocated with "new".
*/
void freeArrays(IntPtr labs[]);

/*
showLabs:
Displays the status of all labs (who is logged into which computer).
*/
void showLabs(IntPtr labs[], int labsizes[]);


// ======================
// login:
// Simulates a user login by asking for the login info from
// the console.
// ======================
void login(IntPtr labs[], int labsizes[]);


// ======================
// logoff:
// Searches through the arrays for the input user ID and if found
// logs that user out.
// ======================
void logoff(IntPtr labs[], int labsizes[]);


// ======================
// search:
// Searches through the arrays for the input user ID and if found
// outputs the station number.
// ======================
void search(IntPtr labs[], int labsizes[]);
// this function allows us to search for an id number to see where it is located
// (the lab # and computer #)


// ======================
//     main function
// ======================
// users input lab sizes, provides a menu list in which the user chooses `an option 
// and the corresponding function gets called (if choice is 1, login gets called, 2 is logoff,
// choice 3 is search 
int main()
{
	IntPtr labs[NUMLABS]; 	// store the pointers to the dynamic array for each lab
	int labsizes[NUMLABS];	// Number of computers in each lab
	int choice = -1;
	
	cout <<"Welcome to the LabMonitorProgram!\n";

	// Prompt the user to enter labsizes 
	cout <<"Please enter the number of computer stations in each lab:\n"; 
	for (int i=0; i< NUMLABS; i++)
	{
		do
		{
			cout <<"How many computers in Lab "<< i+1<<"?";
			cin >> labsizes[i]; 
		} while (labsizes[i]<0); 
	}

	// Create ragged array structure
	createArrays(labs, labsizes);

	// Main Menu
	while (choice != 0)
	{
		cout << endl;
		showLabs(labs, labsizes);
		cout << "MAIN MENU" << endl;
		cout << "0) Quit" << endl;
		cout << "1) Simulate login" << endl;
		cout << "2) Simulate logoff" << endl;
		cout << "3) Search" << endl;
		cin >> choice;
		if (choice == 1) 
		{
			login(labs, labsizes); // calls login function if input is 1
		}
		else if (choice == 2)
		{
			logoff(labs, labsizes); // calls logoff function if input is 2
		}
		else if (choice == 3)
		{
			search(labs, labsizes); // cals search function if input is 3
		}
	}

	freeArrays(labs);		// Free memory before exiting
	return 0;
}


/* COMMENTS NEEDED HERE:
	Describe how your function does its job, 
	as required by the comments given for the declaration of the function.  
 */
// the create arrays function stores values inputed by the user for the size of the lab, and the lab # the user is logged in on
// new int gets stores in the heap
// the labs[i][j] is initialized to -1 so that the showlabs function can output "empty" for the computers in the labs which are not in use   
void createArrays(IntPtr labs[], int labsizes[])
{
  //TO BE DONE BY STUDENTS
  //Hint: for each of the 4 labs, dynamically
  //   allocate an int array of size given by the number of computers in the lab. 
  //   initialize each element in the array as -1 (unused computer).
  //   store the array in the labs 
	int j;

	for (int i=0; i<NUMLABS; i++)
	{
		labs[i]=new int[labsizes[i]];
		for (j=0; j< labsizes[i]; j++)
			labs[i][j]=-1;
	}

}

/* COMMENTS NEEDED HERE:
	Describe how your function does its job, 
	as required by the comments given for the declaration of the function.  
 */
// this function frees the memory from the heap that was associated with the new type, which we used in create arrays function
// releases memory before exiting
void freeArrays(IntPtr labs[])
{
  //TO BE DONE BY STUDENTS
	for (int i=0; i< NUMLABS; i++)
	{
		delete[]labs[i];
	}
}


/* COMMENTS NEEDED HERE:
	Describe how your function does its job, 
	as required by the comments given for the declaration of the function.  
 */
// showLabs displays the number of computers in the four labs, based on user input 
// and outputs empty for the computers that do not have a user logged in 
void showLabs(IntPtr labs[], int labsizes[])
{

	int i;
	int j;

	cout << "LAB STATUS" << endl;
	cout << "Lab #     Computer Stations" << endl; 
	for (i=0; i < NUMLABS; i++)
	{
		cout << i+1 << "         ";
		for (j=0; j < labsizes[i]; j++)
		{
			cout << (j+1) << ": ";
			if (labs[i][j] == -1) 
			{
				cout << "empty "; // if a user is not logged in, this is the output
			}
			else
			{
				cout << labs[i][j] << " ";
			}
		}
		cout << endl;
	}
	cout << endl;
	return;
}

/* COMMENTS NEEDED HERE:
	Describe how your function does its job, 
	as required by the comments given for the declaration of the function.  
 */
// the user enters a number, which is taken in the id variable, and that user id has to be between 0 and 99999
// the user then chooses which lab number they are logged in on, as well as the particular
//  computer station in the lab that they chose 
//  if this station is free, then they have successfully logged in, and they are assigned to the station
//  assuming that the criteria was met with the five digit number
//  if a station is taken, the user is notified with an error message displaying the fact that this computer is unavailable
void login(IntPtr labs[], int labsizes[])
{
	int id, lab, num = -1;

	// read user id 
	do
	{
  		cout << "Enter the 5 digit ID number of the user logging in:" << endl;
		cin >> id;
	} while ((id < 0) || (id > 99999));

	// read the lab number 
	do 
	{
		cout << "Enter the lab number the user is logging in from (1-" <<
			NUMLABS << "):" << endl;
		cin >> lab;
	} while ((lab < 0) || (lab > NUMLABS));

	//read computer number 
	do
	{
		cout << "Enter computer station number the user is logging in to " <<
			"(1-" << labsizes[lab-1] << "):" << endl;
		cin >> num;
	} while ((num < 0) || (num > labsizes[lab-1]));

	// Check to see if this station is free
	if (labs[lab-1][num-1]!=-1)
	{
		cout << "ERROR, user " << labs[lab-1][num-1] <<
			" is already logged into that station." << endl;
		return;
	}
	// Assign this station to the user
	labs[lab-1][num-1] = id;
	return;
}


/* COMMENTS NEEDED HERE:
	Describe how your function does its job, 
	as required by the comments given for the declaration of the function.  
 */
// the user enters the id number, and if the id matches with the given lab station, the function logs off the user
// the user is notified that they are logged off with a display message
// if the id doesn't match, that means that the user id that they entered never even logged in to begin with so they can't log out
// a message displays letting the user know that the id they entered was not logged in
void logoff(IntPtr labs[], int labsizes[])
{
	int id, i,j;

	// Get input from the keyboard, validating data ranges
	do
	{
  		cout << "Enter the 5 digit ID number of the user to find:" << endl;
		cin >> id;
	} while ((id < 0) || (id > 99999));

	
	for (i=0; i<NUMLABS; i++) // check for each lab 
	{
		for (j=0; j<labsizes[i]; j++) //if the user is using any computer in the lab
		{
			if (labs[i][j]==id) //if so, log the user off... 
			{
				// Log the user off by setting the entry to -1
				labs[i][j] = -1;
				cout << "User " << id << " is logged off." << endl;
				return;
			}
		}
	}
	cout << "That user is not logged in." << endl;
	return;
}

/* COMMENTS NEEDED HERE:
	Describe how your function does its job, 
	as required by the comments given for the declaration of the function.  
 */
// this function allows the user to search to locate where a specific user id is located (the lab # and computer #)
void search(IntPtr labs[], int labsizes[])
{
  //TO BE DONE BY STUDENTS.
  	
  	// we put determine whether or not the input/ username exists
  	// here, I have created a variable to test this
	int id;
	
	// prompts user to enter the id that they would like to search
	do
	{
  		cout << "Enter the 5 digit ID number of the user logging in:" << endl;
		cin >> id;
	} while ((id < 0) || (id > 99999));

	// if the id is found, this nested for-loop outputs the lab # and computer station of the id 	
	int k=0; 
	for (int i=0; i< NUMLABS; i++)
	{
		for (int j=0; j< labsizes[i]; j++)
		{
			if (labs[i][j]== id)
			{	
				k=1; // k=1 when the id was found by the search function
				cout << "The id is found in lab # " << i +1 << " at computer # " << j+1 << endl;
				return;
			}
		}
	}
		// k is the variable that checks to see if the user id is found. It acts like a bool. 
		// If it is found, the value of k is 1. If it is not found, then the value of k is 0 and "id is not found" is displayed 	
		if (k==0)
			cout << "Id is not found " << endl;
}	
	
	
