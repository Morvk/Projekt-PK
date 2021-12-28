#include <iostream>
using namespace std;

void wypisz(int tab[], int ile)
{
	for (int ind = 0; ind < ile; ind++)
	{
		cout << tab[ind] << endl;
	}
		
}






int main() 
{

	int dane[5];
	dane[0] = 123;
	dane[1] = 321;
	dane[2] = 333;
	dane[3] = 222;
	dane[4] = 111;
	wypisz(dane, 5);
	return 0;
}