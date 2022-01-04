#pragma once
//klasa odpowiedzialna za pojedynczy neuron

class Neuron
{
private:
	int state;

public:
	Neuron() :state(-1) {} 
	//2 stany neurona
	// -1 neuron jest nieaktywny
	// 1 neuron jest aktywny


	int getStan()const { return state; }
	//zwraca stan naszego neurona

	void setStan(int value) { state = value; }
	//zmienia stan neutrona na otrzymana wartosc


};