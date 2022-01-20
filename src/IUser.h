#pragma once
/**\brief Klasa abstrakcyjna opisujaca interakcje programu z uzytkownikiem
* 
*/
class IUser
{
public:
	/// Wirtualny destruktor
	virtual ~IUser(){}


	/** \brief Statyczna metoda, w ktorej zostaly zaimplementowane komunikaty odnosnie bledow zwiazanych w przeslanymi plikami
	* 
	* Metoda obsluguje komunikaty zwiazane z nieprawidlowym otwarciem pliku, plikiem pustym lub o liniach roznej dlugosci
	*/
	static void fileErrorMess(int opt);

	/** \brief Czysto wirtualna metoda dotyczaca wyswietlania komunikatow zwiazanych z blednymi argumentami wejsciowymi
	*/
	virtual void argErrorMess()const = 0;

	/** \brief Czysto wirtualna metoda dotyczaca wyswietlania okna pomocy programu
	*/
	virtual void showHelp()const = 0;
};

