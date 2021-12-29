//Klasa odpowiadaj�ca za synapse w sieci neuronowej
#pragma once
#include <iostream>

class Synaps
{
private:
	int value;
	//warto�� sygna�u dla ka�dego neuronu
public:
	Synaps() :value(0) {}
	//inicjacja wagi po��czenia warto�ci� 0

	int getValue()const { return this->value; }
	//funkcja zwraca wartko�� wagi po��czenia



	Synaps& operator+(int i) {
		this->value += i;
		return *this;
	}

	Synaps& operator-(int i) {
		this->value -= i;
		return *this;
	}

	//zmienna i - warto��, kt�ra jest dodawana lub idejmowana od wagi
	//operator+/- dodaje lub odejmuje warto�� od wagi po��czenia



};
