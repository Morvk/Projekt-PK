#pragma once
#include <iostream>
///Klasa reprezentujaca pojedyncza synapse w sieci neuronowej 
class Synapsa
{
private:
	///wartosc wagi sygnalu dla kazdego nauronu
	int value; 

public:
	/// Konstruktor bezparametryczny inicjujacy wage polaczenia wartoscia 0
	Synapsa():value(0){}

	/** \brief Funkcja zwracajaca wage danego polaczenia
	* 
	* @return wartosc wagi polaczenia (int)
	*/
	 int getValue()const {return this->value;}

	 /** \brief Przeciazony operator+ dodajacy wartosc do wagi polaczenia
	 *
	 * @param i  -> wartosc, ktora zostanie dodana do wagi
	 * @return Synapsa&
	 */
	Synapsa& operator+(int i) {
		this->value += i;
		return *this;
	}

	/** \brief Przeciazony operator- odejmujacy wartosc od wagi polaczenia
	*
	* @param i  -> wartosc, ktora zostanie odjeta od wagi
	* @return Synapsa&
	*/
	Synapsa& operator-(int i) {
		this->value -= i;
		return *this;
	}
};