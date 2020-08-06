/* Lab 6: class Rational to practice basics of defining and using classes.
Author: Faiza Khan
Known Bugs: 
Last Modified: 3/21/18 
*/
#include <iostream>
#include <sys/time.h>

using namespace std;

/*
 * class Rational
 *    represents a Rational number. Remember rational means ratio-nal
 *    which means there is a numerator and denominator implemented using
 *    integer values. Using good ADT techniques, we have made member
 *    variable private (also known as instance variables) and made member
 *    functions public.
 */
class Rational
{
  public:
    	Rational ();     
 	// default constructor 

    Rational(int i);
    // constructor that takes a single int as paramter. Implies that the
    // denominator is 1.

    Rational (int p, int q);
    //constructor that takes two ints as parameter. Verify q is not zero

    void input();
    // read value for the object from standard input 

    void output();
    // display the value of the object to standard output 

	int getNumerator();
    //Todo: declare an accessor (getter function) that returns the numerator
    
	int getDenominator();
    //Todo: declare an accessor (getter function) that returns the denominator
    
    void Sum (Rational op1, Rational op2);
    // set current object's value to be the sum of num1 and num2 

    bool isEqual(const Rational& op);
    // test if two rational numbers are equal.

  private:
    int numerator;
    int denominator;

}; 


/*
 * main program
 * Unit Test code for class Rational uses all defined methods
 */
int main ()
{
    Rational a(1,2);	 // a is 1/2 
    a.output ();

    Rational b(2); 	 // b is 2/1
    b.output ();

    Rational c;		 // what does the default constructor do?
    c.output ();

    c.input (); 	 // read value for c from input
    c.output (); 

    c.Sum (a,b); 	// c will be set to 1/2+2/1 = 5/2
    c.output (); 	//this should display 5/2
    
    //Todo: display the numerator of c
 	cout << c.getNumerator() << endl;
   
    //Todo: display the denominator of c
    	cout << c.getDenominator()<< endl;
   
    //Todo: read in two rational numbers and test if they are equal using isEqual
   	 Rational d;
    	Rational e;
	d.input();
	e.input();
    // Todo: get the values using the input member function
	if (d.isEqual(e))
		cout << "D is equal to E " << endl;
    // Todo: compare using isEquals and write out the result.

}

//Definitions of all member functions 

Rational::Rational () // using default constructor
{
	numerator=0;
	denominator=1;
}

 Rational::Rational (int i) // this constructor takes in a single int as a parameter and sets the denominator equal to 1
{
	numerator = i;
	denominator = 1;
}

 Rational::Rational (int p, int q) // this constructor takes two parameters and displays error message if q is 0
{
	numerator = p;
	denominator=q;
	if (denominator == 0)
		cout << endl << "ERROR! Cannot divide by 0" << endl;

}


void Rational::input () // reads in 2 numbers which the user enters  
{
	int p, q;
	cout << "Enter 2 numbers : " << endl;
	cin  >> p >> q;
	numerator = p;
	denominator = q;
}

void Rational::output () // displays value of the object
{
	cout << numerator << "/" << denominator << endl;

}

int Rational::getNumerator () // getter function that returns the numerator
{
	return numerator;
}
	
int Rational::getDenominator () // getter function that returns the denominator
{
	return denominator;
}

void Rational::Sum (Rational r1, Rational r2) // sets current object's value to be the sum of num1 and num2
{
	 numerator= (r1.numerator * r2.denominator) + r2.numerator * r1.denominator;
	 denominator = r1.denominator * r2.denominator;
}

bool Rational::isEqual (const Rational & op) // tests if the two rational numbers are equal
{
	if ((double)numerator/(double)denominator == (double)op.numerator/(double)op.denominator)
	{
		return true;
	}
	return false;
}


