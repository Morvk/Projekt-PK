#pragma once
#include <fstream>
#include <iostream>
#include<string>
#include "Network.h"
#include "IUser.h"
/** \brief Klasa sluzaca do obslugi programu. Dziedziczy publicznie po klasie IUser
* 
* W klasie tej przechowywane sa informacje o plikach podanych przez uzytkownika, sprawdzanie poprawnosci podanych plikow oraz argumentow programu.
* Dodatkowo metoda buildNetwork() posrednio uczestniczy w budowaniu sieci neuronowej wskazujac odpowiednie argumenty do utworzenia sieci
*/
class FileHandling: public IUser
{private:
	///pole zawierajace informacje o ilosci wierszy w pliku
	 int fileYSize = 0;
	///pole zawierajace informacje o ilosci znakow w wierwszu pliku
	int fileXSize = 0;
	///pole zawierajace informacje o ilosci znakow w pliku
	int size = 0;
public:
	///Wektor nazw  plikow uczacych
	std::vector<std::string> teachData;
	/// Nazwa pliku ze wzorcem do rozpoznania
	std::string forRecognise;

	/**\brief Metoda odpowiedzialna za sprawdzanie poprawnosci przeslanych argumentow programu
	* 
	* @param argc - ilosc przeslanych argumentow
	* @param argv[] - tablica argumentow
	*/
	void checkArguments(int argc, char *argv[]);
	
	/** \brief Metoda, ktora wypelnia pola dotyczace wielkosci pliku, nastepnie te informacje sa uzywane do budowy sieci neuronowej
	* 
	* @return std::pair<int,int> - metoda zwraca pare liczb z informacjami o wielkosci pliku 
	*/
	std::pair<int,int> buildNetwork();

	/**\brief Metoda, w ktorej tworzona jest siec neuronowa oraz wywolywane sa odpowiedni funkcje dotycace procesu dzialania sieci neuronowej
	* 
	* @see Network::teach(), Network::recognize()
	*/
	void runNetwork();
	static void checkFile(std::string& file);
	
	/** Implementacja metody z klasy IUser
	* 
	* @see IUser::showHelp()
	*/
	void showHelp() const override;

	/** Implementacja metody z klasy IUser
	*
	* @see IUser::argErrorMess()
	*/
	void argErrorMess()const override;
};
