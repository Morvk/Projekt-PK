#pragma once
#include <vector>
#include "Neuron.h"
#include "Synapsa.h"
#include "FileHandling.h"
#include "IUser.h"
#include <string>
#include <algorithm>
#include <ctime>

/** \brief Klasa reprezentujaca siec Hopfielda 
* 
* Klasa reprezentuje siec neuronowa Hopfielda odpowiedzialna za rozpoznawanie liczb od 0 do 9
* W sieci tej jeden neuron odpowiada dokladnie jednemu znakowi w pliku wejsciowym
*/
class Network
{
private:
	/// Zbior wszystkich neuronow w sieci
	std::vector<Neuron*> neurons; 

	///Zbior wszystkich polaczen (synaps) pomiedzy neuronami
	std::vector<Synapsa*> connections;
	
	/// Pole reprezentujace ilosc neuronow w sieci
	int size;

	/// Pole reprezentujace ilosc neuronow w jednej linii pliku
	int filexSize;

public:
	/** \brief  Konstruktor parametryczny tworzacy siec neuronowa 
	* 
	* Konstruktor tworzacy siec neuronowa na podstawie ilosci znakow w pliku wejsciowym
	* @param fileXSize - ilosc neuronow w jednym wierszu pliku
	* @param fileYSize - liczba wierszy pliku
	*/
	Network(int fileXSize,int fileYSize) {
		size = fileXSize * fileYSize; //ilosc neuronow w sieci, jeden neuron to jeden znak w pliku
		filexSize = fileXSize;
		for (int i = 0; i < size; i++) {
			neurons.push_back(new Neuron());
		}
		for (int i = 0; i < size * size; i++) { //polaczenia = neurony^2
			connections.push_back(new Synapsa());
		}	
	}; 
	///Destruktor sieci neuronowej usuwajacy kolejne neurony i synapsy ze zbiorow klasy Network
	~Network() {
		for (Neuron* neuron : neurons)
			delete neuron;
		for (Synapsa* synaps : connections)
			delete synaps;
	}

	//metody

	/** \brief Metoda przypisujaca neuronom stan aktywny lub nieaktywny zgodnie z plikiem wejsciowym 
	* 
	* Dzialanie metody: \n gdy znak w pliku == '+' => neuron przechodzi w stan aktywny, w innym wypadku pozostaje nieaktywny
	* @param file - plik wzorcowy, z ktorego pobierane sa kolejne znaki 
	* @param i - iterator po zbiorze neuronow sieci
	* 
	*/
	void insertNeurons(std::ifstream& file,int i);

	/** \brief Metoda przypisujaca odpowiednie wartosci polaczeniom w sieci
	*
	* Dzialanie metody: \n Jesli dwa neurony maja taki sam stan -> zwiekszamy wage polaczenia pomiedzy nimi, jesli nie -> zmniejszamy wage
	*/
	void insertSynapses();

	/**
	* \brief Metoda odpowiedzialna za resetowanie neuronow do stanu poczatkowego (nieaktywnego)
	*/
	void resetNeurons();

	/** \brief Implementacja algorytmu dopasowywania obrazu do wzorca
	* 
	* Dzialanie metody: \n ->Dla losowego neuronu wyznaczamy sile polaczen (suma stanow innych neuronow przemnozona przez wage polaczenia) \n
	* -> Jesli sila < 0 => neuron przechodzi w stan nieaktywny, jesli sila >= 0 => neuron przechodzi w stan aktywny \n
	* -> operacje te wykonujemy tak dlugo, az kazdy neuron bedzie w odpowiednim stanie (nie bedzie zmian stanu zadnego z neuronow)
	*/
	void recognizingAlg();

	/**\brief  Metoda odpowiedzialna za wyswietlanie stanu neurownow na ekran konsoli
	* 
	* Dzieki tej metodzie mozemy zobaczyc, czy plik zostal odpowiednio wczytany do sieci neuronowej
	*/
	void showNeurons();

	/** \brief Metoda w ktorej zostal zaimplementowany proces zapamietywania wzorcow przez siec neuronowa
	* @param fileNames - wektor nazw plikow zawierajacych wzorce do zapamietania przez siec 
	* Dzialanie metody: \n Dla kolejnych plikow wejsciowych alokowane sa neurony, wagi polaczen sa modyfikowane a na koniec neurony resetowane, 
	* aby mozliwe bylo przyjecie kolejnych plikow
	* @see insertNeurons(), insertSynapses(), resetNeurons()
	*/
	void teach(std::vector<std::string>& fileNames);

	/**\brief Metoda w ktorej zostal zaimplementowany proces rozpoznawania wzorca
	* 
	* @param fileName - nazwa pliku ze wzorcem do odtworzenia
	* Dzialanie metody: \n Dla podanego pliku alokowane sa neurony, wyswietlany jest obraz do rozpoznania i wywolywana jest funkcja 
	* algorytmu rozpoznawania wzorca 
	* @see recognizingAlg(), insertNeurons(), showNeurons(), resetNeurons()
	*/
	void recognize(std::string& fileName);

	

	

	
};
