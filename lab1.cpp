// This program calculates the inflation rate given the old and new cpi
// Faiza Khan
// 1/24/18

#include <iostream>
using namespace std;

double InflationRate(float old_cpi, float new_cpi);

int main ()
{
	// declare two float variables (old consumer price index and new consumer price index)
	float old_cpi, new_cpi;
	
	//  read in two float values and store them in as variables
	cout << "Enter the old cpi : " << endl;
	cin  >> old_cpi;

	cout << "Enter the new cpi : " << endl;
	cin  >> new_cpi;

	// call the function InflationRate with two cpis 
	InflationRate(old_cpi, new_cpi);

	return 0;
}

double InflationRate(float old_cpi, float new_cpi)
{
	double InflationRate;
	
	InflationRate = (new_cpi - old_cpi) / old_cpi * 100;

	// print the results
	if ((old_cpi > 0.000000) && (new_cpi > 0.000000))
	{
		cout << "The inflation rate is " << InflationRate << endl;
	}
	
	else 
		cout << "Invalid CPI! Both prices must be greater than 0.0." << endl;
}
		

