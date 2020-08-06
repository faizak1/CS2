/* Author: Faiza Khan
 * Last modified: 5/8/18  
 header file class DNASequence  
*/
#include <iostream>
#include <string>

#ifndef _DNASEQUENCE_
#define _DNASEQUENCE_

// class DNASequence 
// A class that contains a sequence of nucleotides in the dna_sequence.
// The max_sequence represents the capacity of the dna_sequence.
// A dna_sequence is a c-string of characters that consist only of
// 'A', 'T', 'G', 'C' standing for the 4 nucleotides and ending in a '\0'
// character. Input into the DNASequence is case-insensitive meaning that
// lower or upper case is acceptable, but it should be converted to uppercase
// internally.

class DNASequence {
	public:
		DNASequence(); 
		// Assume that the strand is initialized to a max_length of 20 nucleotides.
		// Add an extra character for '\0'.

		DNASequence(std::string nucleotides);
		// Assume that the sequence is initialized to the nucleotides string.
		// Add an extra character for '\0'.

		DNASequence(const DNASequence& arg);
		// Copy constructor makes a deep copy
		// Add an extra character for '\0'.

		~DNASequence();
		// Destructor

		DNASequence& operator=(const DNASequence& arg);
		// Assignment operator makes a deep copy

		bool operator==(const DNASequence& arg);
		// Equals operator compares the given sequence with the invoking (lhs) object.

		bool operator!=(const DNASequence& arg);
		// Not equals operator compares the given sequence with the invoking (lhs) object.

		friend DNASequence operator+(const DNASequence& arg1, const DNASequence& arg2);
		// Return a DNASequence with the second operand appended to the first operand.

		friend DNASequence operator-(const DNASequence& arg1, const DNASequence& arg2);
		// Return a DNASequence with the first occurance of the second operand removed
		// from the first operand. If the given sequence is not found, return a copy of
		// first operand.

		friend std::istream& operator>>(std::istream& ins, DNASequence& arg);
		// Implement the friend function to read in a nucleotide sequence made up
		// of only the following characters: adenine (A), thymine (T), guanine (G)
		// and cytosine (C). Assume case insensitive but convert to upper internally.
		
		friend std::ostream& operator<<(std::ostream& out, const DNASequence& arg);
		// Implement the friend function to write out a nucleotide sequence. No blanks.

		int get_max_sequence() const { return max_sequence; };
		// Accessor for max_sequence.

		char* get_dna_sequence() const { return dna_sequence; };
		// Accessor for dna_sequence.

	private:
		char		*dna_sequence;				// Dynamic array of char
		int 		max_sequence;				// Number of sequences.
		bool		validate(std::string& str);	// a helper function to validate the nucleotide string.
};

#endif
