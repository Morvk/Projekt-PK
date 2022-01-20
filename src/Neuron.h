#pragma once
///Klasa reprezentujaca pojedynczy neuron w sieci neuronowej
class Neuron
{
private:
	///pole reprezentujace stan neuronu
	int state; //nauron aktywny =1 ; neuron nieaktywny = -1

public:
	///Konstruktor bezparametrowy ustawiajacy stan neuronu na wartosc -1 (stan nieaktywny)
	Neuron():state(-1){} 

	/** \brief Funkcja zwracajaca stan nauronu
	* 
	* @return stan neuronu (int)
	*/
	int getStan()const { return state; }

	/** \brief Funkcja ustawiajaca stan neuronu na przekazana wartosc
	* 
	* @param value  -> wartosc, na jaka zostanie ustawiony stan neuronu
	*/
	void setStan(int value) {state = value;}

};	