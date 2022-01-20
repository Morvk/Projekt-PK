#include "IUser.h"
#include <iostream>
using namespace std;
void IUser::fileErrorMess(int option)
{
		switch (option) {
		case 1:
			cout << "Nie mozna otworzyc pliku! Sprawdz poprawnosc pliku oraz podanej sciezki" << endl;
			break;
		case 2:
			cout << "Pliki musza byc tego samego rozmiaru!" << endl;
			break;
		case 3:
			cout << "Plik podany w argumencie jest pusty! Wprowadz poprawne dane!" << endl;
			break;
		}
}
