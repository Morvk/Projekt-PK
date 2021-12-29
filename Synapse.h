//Klasa odpowiadaj¹ca za synapse w sieci neuronowej
#pragma once
#include <iostream>

class Synaps
{
private:
	int value;
	//wartoœæ sygna³u dla ka¿dego neuronu
public:
	Synaps() :value(0) {}
	//inicjacja wagi po³¹czenia wartoœci¹ 0

	int getValue()const { return this->value; }
	//funkcja zwraca wartkoœæ wagi po³¹czenia



	Synaps& operator+(int i) {
		this->value += i;
		return *this;
	}

	Synaps& operator-(int i) {
		this->value -= i;
		return *this;
	}

	//zmienna i - wartoœæ, która jest dodawana lub idejmowana od wagi
	//operator+/- dodaje lub odejmuje wartoœæ od wagi po³¹czenia



};
