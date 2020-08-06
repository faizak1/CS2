//Author: Faiza Khan
//Last modified: 4/11/18
#include <iostream>

// header file (contains class declaration)


class rational
{
public:
   /* default constructor set the rational number to 0, (i.e., numerator is 0, denominator is 1) */
   rational (int p=0, int q=1);	
								
   /* Set the invoking object's value from user input */
   void input();	

   /* Display invoking object's value in the standard output, in the form of numerator/denominator */
   void output();	

   //return the invoking object's numerator 
   int get_numerator();
   
   //return the invoking object's denominator
   int get_denominator(); 
   
   // Set invoking object to be the sum of op1 and op2
   void Sum (const rational &op1, const rational &op2); 
  
   static int counter;

   void set(int numer, int denom);

   void Product (const rational &op1, const rational &op2);
private:
   int numerator;
   int denominator;
};  
