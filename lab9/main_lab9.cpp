/* Faiza Khan
 * Lab9 CRISPR Application Main Program 
 * Last modified: 5/8/18 
 */

#include <iostream>
#include <string>
#include <cstring>
#include <cctype>
#include <stdio.h>
#include <vector>
#include "dna_sequence.h"
using namespace std;

int main()
{
	//variables 
	int seq_num; 
	char again;   

	//do-while loop in program that spans for rest of instructions
	do {

		//user enters the number of DNA Sequences
		cout << "Number of DNA Sequences for CRISPR application : ";
		cin >> seq_num; 

		while (cin.fail()) //loops until the user enters anything that is not int, which is invalid
		{
			cout << "Invalid! Only integers can be entered!" <<endl;

			cin.clear(); 
			cin.ignore(256, '\n'); 

			cout << "Number of DNA sequences needed for CRISPR application: ";
			cin >> seq_num; //user gets another chance to enter a valid input (number) 
		}

		cout << endl;

		// vector of DNASequence where the user enters the number of elements
		vector <DNASequence*> dna; 

		//this for-loop reads in a DNASequence for each element in the array using >> operator
		for (int i=0; i < seq_num; i++)
		{

			cout << "Processing DNA sequence #" << i+1 <<endl;

			DNASequence str_dna; 	

			cout << "Enter the elements in sequence #" << i+1 <<endl;

			cin >> str_dna;

			//dna.push_back(pointer)
			dna.push_back(new DNASequence(str_dna)); 

			cout << endl;
		}		

		//Declare a DNASequence called big_strand and add each element in the array to big_strand in a for-loop. 
		DNASequence* big_strand = new DNASequence();	

		for (int i=0; i < seq_num; i++)
		{
			*big_strand = *big_strand + *dna[i];
		}

		// Print the final big_strand after the loop using the << operator.
		cout << "The contents in the big strand is: "; 
		cout << *big_strand; 

		cout << endl;

		//Declare two variables: one for a small sequence of bad_dna and one to hold the clean_strand. 
		//NOTE: Make sure that clean_strand is set directly to big_strand when declared.
		DNASequence bad_dna;
		DNASequence* clean_strand = big_strand;

		cout <<endl;

		if (*clean_strand ==(*big_strand))
		{
			cout << "The is-Equal operator works!" <<endl;
		}
		cout << endl;


		if (bad_dna != (*clean_strand))
		{
			cout << "The not-Equal operator works!" <<endl;
		}

		cout << endl;

		// Ask the user to enter a bad DNASequence to remove from big_strand and put it in the bad_dna variable.
		cout << "Enter a bad DNASequence to remove from big_strand: ";
		cin >> bad_dna;

		do 
		{
			//subtract the bad_dna from big_strand. The results are in clean_strand
			*clean_strand = *big_strand - bad_dna;

			// Use clean_strand != big_strand as the while condition so that it loops until the strand is clean.
		} while(*clean_strand != (*big_strand));

		cout << endl;

		// Print the clean_strand as you go and the final result.
		//use function member to print out clean_strand
		cout << "Here are the contents in the clean strand : " <<*clean_strand; 

		cout <<endl;

		// Either Free the dynamic array of DNASequences or clear the vector after the loop.
		dna.clear();
		delete big_strand;		

		cout << endl;

		// Ask the user to try it again or quit.
		cout << "Do you want to run this program again? (Y= yes N=no? : " <<endl;
		cin >> again;

	} while (again == 'Y'|| again == 'y');

	cout << "Program ended! Goodbye!" <<endl;
}
