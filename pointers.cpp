#include <iostream>
using namespace std;

int main ()
{
	int *a= new int [10];
	for (int i=0; i<10; i++) a[i] = i;
	int *b =&a[2];
	
	cout << b[0];

	return 0;
}
