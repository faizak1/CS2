/* Author: Faiza Khan 
 * Last Modified: 5/8/18
 * Known Bugs:
 * This cpp file contains the implementation of DNASequence class and defined member functions
*/

#include <iostream>
#include <string>
#include <cstring>
#include <cctype>
#include <stdio.h>
#include "dna_sequence.h"

using namespace std;

// Assume strand is made up of 20 sequences
// Add an extra character for '\0'
DNASequence::DNASequence(): max_sequence(20) //default constructor
{ 
	dna_sequence = new char [max_sequence]; 
	dna_sequence[0] = '\0'; 
}

// Assume that the sequence is initialized to the nucleotides string.
// Add an extra character for '\0'
DNASequence::DNASequence(string nucleotides): max_sequence(nucleotides.length()+1)
{
	dna_sequence = new char [max_sequence]; 
	strcpy(dna_sequence, nucleotides.c_str());
	dna_sequence[max_sequence] = '\0';
}

// Copy constructor
// Add an extra character for '\0'
DNASequence::DNASequence(const DNASequence& arg): max_sequence(strlen(arg.dna_sequence)+1)
{
	this->dna_sequence = new char [max_sequence];
	strcpy(this->dna_sequence, arg.dna_sequence);
	this->dna_sequence[this->max_sequence] = '\0';
}

// Destructor
DNASequence::~DNASequence()
{
	delete [] dna_sequence;
}

// Assignment operator 
DNASequence& DNASequence::operator=(const DNASequence& arg)
{
	this->max_sequence = strlen(arg.dna_sequence); //using the this pointer to point to max_sequence

	for (int i=0; i < this->max_sequence; i++)
	{
		this->dna_sequence[i] = arg.dna_sequence[i];
	}

	this->dna_sequence[this->max_sequence] = '\0';

	return *this;
}

// Equals operator compares the given sequence with the invoking object.
bool DNASequence::operator==(const DNASequence& arg)
{
	// for-loop to check for equality
	for (int i=0; i < this->max_sequence; i++)
	{ 
		if (this->dna_sequence[i] != arg.dna_sequence[i])
		{
			return false; // if at least ONE element is not the same, it returns false
		}
	}

	return true; //if all of the elements are the same, boolean returns true
}

// Not equals operator compares the given sequence with the invoking object
bool DNASequence::operator!=(const DNASequence& arg)
{
	// implement for loop which checks for inequality (opposite of the previous function)
	for (int i=0; i < arg.max_sequence; i++)
	{ 
		if (this->dna_sequence[i] != arg.dna_sequence[i])
		{
			return true; //it returns true if the sequences are not the same
		}
	}
	return false; //false is returned is they are the same 
}

// append the given sequence onto the end of the invoking object sequence
DNASequence operator+(const DNASequence& arg1, const DNASequence& arg2)
{ 
	DNASequence result; //object declaration

	
	if (arg1.dna_sequence[0] == '\0') //if first strand is empty, the following code is executed
	{
		result.max_sequence = arg2.max_sequence;
		result.dna_sequence = new char [result.max_sequence];
		for (int i= 0; i < arg2.max_sequence; i++)
		{
			// Add the values of arg2 to object result
			result.dna_sequence[i] = arg2.dna_sequence[i]; 
		}
	}
		//if the both strands elements, else statement is executed 
	else
	{
		
		result.max_sequence = arg1.max_sequence + arg2.max_sequence -1;  //-1 because arg 1 and arg2 have space for the null character
										// when added, they only need one empty space for null '/0'
		result.dna_sequence = new char [result.max_sequence];	//allocation of dynamic int array

		for (int i=0; i < arg1.max_sequence; i++)
		{
			result.dna_sequence[i]=arg1.dna_sequence[i]; //copies #s from arg1 into the new array
		}

		for (int i= 0; i < arg2.max_sequence; i++)
		{
			result.dna_sequence[i+arg1.max_sequence] = arg2.dna_sequence[i]; //values of 2nd argument are added to the end of result object
		}
	}
	return result; //object is returned
}

// EXTRA CREDIT 10 POINTS: Remove the given sequence from the invoking object if it exists. 
// If the given sequence is not found, return the first argument sequence unaltered.
DNASequence operator-(const DNASequence& arg1, const DNASequence& arg2)
{
	DNASequence result = arg1;

	//sequences convert to string 
	std::string dna(result.dna_sequence);
	std::string dna2(arg2.dna_sequence);

	// Get the first occurrence
	size_t pos = dna.find(dna2);
 
	// while loop repeats until the end is reached
	while( pos != std::string::npos)
	{
		// Replace this occurrence of Sub String
		dna.replace(pos, dna2.size(), "");
		// Get the next occurrence from the current position
		pos =dna.find(dna2);
	}

	//return as a object 
	return DNASequence(dna.c_str());
}

// To make the code compile, a function that validates the input string
// is made up purely of nucleotides.
bool DNASequence::validate(string& str) 
{
	// Check the string for characters 'A', 'a', 'T', 't', 'G', 'g', 'C', 'c'
	// return false if any characters in the string are different. You can
	// use any means you like, remember what we did with palindrome code to
	// avoid a big if statement.

	for (int i =0; i < str.length(); i++)
	{
		//if it is a nucleotide base 
		if (str[i] == 'A' || str[i] == 'a' || str[i] == 'T' || str[i] == 't' || str[i] == 'G' || str[i] == 'g' || str[i] == 'C' || str[i] == 'c')
		{
			if (islower(str[i]))
				{
					str[i]=toupper(str[i]); //convert character to uppercase	
				}
		}
		else //anything that is not a nucleotide base 
		{
			return false;
		}	
	}
	return true; 
}

// Implement the friend function to read in a nucleotide sequence made up
// of only the following characters: adenine (A), thymine (T), guanine (G)
// and cytosine (C). Assume case insensitive but convert to upper internally.
istream& operator>>(istream& ins, DNASequence& arg)
{
	string str_dna;

	//Read in a string 
	ins >> str_dna;  

	//if the sequence is not valid 
	if (arg.validate(str_dna) == false)
	{
		cout << "Invalid sequence" <<endl; //displays error message
		exit(1); //exits out of the program 
	}

	//set value of object by assignment 
	arg= DNASequence (str_dna);

	return ins; //returns input stream
}

// Implement the friend function to write out a nucleotide sequence. No blanks.
ostream& operator<<(ostream& out, const DNASequence& arg)
{
	
	for (int i=0; i < arg.max_sequence; i++)
	{
		out << arg.dna_sequence[i]; 
	}	

	return out; //returns output stream
}
