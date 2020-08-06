// Author: Faiza Khan
// Last modified: 4/11/18

//Definitions of all member functions 
using namespace std;
#include <iostream>
#include "rational.h"

int rational::counter = 0;
rational::rational (int p, int q)
{
   if (q==0)
	exit(1);
   numerator = p;
   denominator = q;
   counter++;
   cout <<"So far " <<counter <<" rational objects created\n";
}

 /* Set the invoking object's value from user input */
void rational::input()
{
   char c;
   int top, bottom;
   bool valid = true; 

   // keep reading until valid input is entered 
   do {
	cin >> top >> c >> bottom;
		if (c!='/' || bottom==0)
     {
        cout <<"wrong input. Enter a rational (p/q):";
        valid = false;
     } 
     else
 	valid = true;
   } while (!valid);

   // set the invoking object's numerator, denominator 
   numerator = top;
   denominator = bottom;
}

 /* Display invoking object's value in the standard output, in the form of numerator/denominator */
void rational::output()
{
   cout << numerator << "/" << denominator; 
}

 //return the invoking object's numerator 
int rational::get_numerator()
{
   return numerator; 
}
   
 //return the invoking object's denominator
int rational::get_denominator()
{
   return denominator;
}
   
// Set invoking object to be the sum of op1 and op2
void rational::Sum (const rational &op1, const rational &op2)
{
   numerator = (op1.numerator * op2.denominator + op2.numerator*op1.denominator);
   denominator = op1.denominator*op2.denominator;
}

// set invoking object to the the product of op1 and op2
void rational::Product(const rational &op1, const rational &op2)
{
   numerator = (op1.numerator * op2.numerator);
   denominator = (op1.denominator * op2.denominator);
}

// sets numerator and denominator 
void rational::set(int numer, int denom)
{
 	numerator=numer;
	denominator=denom;	
}
