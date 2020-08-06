// Author: Faiza Khan
// Last modified: 4/11/18

// cpp file contains the main function
using namespace std;
#include <iostream>
#include "rational.h"


// declare the array in main 
// (dynamically declare an array of rationals, loop over the array setting (1/1, 1/2, 1/3, use i+1 in the set (1/i+1)
int main ()
{
	char answer;	

	// Test the three constructors ... 
	rational  a(1,2); // a is 1/2 
	cout <<"rational object initialized with parameter 1,2:";
	a.output ();
        cout <<endl;

	rational b(2); // b is 2/1
	cout <<"rational object initialized with parameter 2:";
	b.output ();
        cout <<endl;

	rational c;
	cout <<"rational object initialized with default constructor:";
	c.output ();
        cout <<endl;

	//Test input member function 
	cout <<"Enter a rational value :";
	c.input (); //read value for c from input
	cout <<"What you just entered :";
	c.output (); 
        cout <<endl;

	//Test Sum member function 
	do {
	  cout <<"Enter op1 (in the format of p/q):";
          a.input();

          cout <<"Enter op2 (in the format of p/q):";
	  b.input();

	  c.Sum (a,b);  
	  cout <<"The sum of op1 and op2 is:";
          c.output (); 
          cout <<endl;

	  cout <<"Try again (Y/N)?";
	  cin >> answer;

        } while (answer=='y' || answer=='Y');
	
	//test getters 
	cout <<" C's numerator is: " << c.get_numerator() << endl;
	cout <<" C's denominator is: " << c.get_denominator() << endl;

	// extending the rational class
	int seq_length;
	cout << "Enter the number of terms to add and multiply : " << endl; //asks for user input
	cin >> seq_length;

	rational * fractions = new rational[seq_length]; // suppose you use int seq_length to store the input from step 1		
	
	rational totalsum;
	rational totalproduct=1;
	for (int i =1; i<= seq_length; i++) // for loop to set the fractions in the array to 1/1, 1/2, 1/3, 1/4, etc
 	{
		fractions[i].set(1,i);	
	}

	for (int i=1; i<= seq_length; i++) // for loop continues to calculate the sum and product of all of the elements in the array (until the number of terms are all added/multiplied) 
	{
		totalsum.Sum(totalsum,fractions[i]); 	//calls sum function
		totalproduct.Product(totalproduct,fractions[i]);	// calls product function
	}

	cout << "The total sum is ";
	totalsum.output(); //calls output function to show the total sum
	cout << endl;
	totalproduct.output();	//calls output function to display the total product
}
