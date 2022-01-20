#pragma once
#include "Network.h"
#include "IUser.h"
using namespace std;

void Network::teach(vector<std::string>& fileNames) {
	int i = 0; //iterator po vectorze neuronow przesylany do metody 'insertNeurons()'
	auto it = fileNames.begin();
	while (it != fileNames.end()) {//przejscie po wszystkich plikach wzorcow
		FileHandling::checkFile(*it);
		ifstream file(*it);
		
		insertNeurons(file, i); //alokacja neuronow
		file.close();
		insertSynapses(); //alokacja synaps
		cout << "Wzorzec liczby zapamietany w sieci: " << endl; showNeurons(); cout << endl;
		resetNeurons(); //reset neuronow przed przetwarzaniem kolejnego wzorca (cala pamiec sieci znajduje sie w synapsach)
		it++;
	}
}

void Network::recognize(std::string& fileName) {

	FileHandling::checkFile(fileName); //sprawdzanie poprawnosci pliku (czy otwarty i niepusty)
	ifstream file(fileName);
	int i = 0; //iterator po vectorze neuronow
	insertNeurons(file, i);
	cout <<endl<<endl<<endl<< "Liczba do rozpoznania:" << endl;
	showNeurons(); cout << endl;
	file.close();
	recognizingAlg();
	resetNeurons();
}

void Network::insertNeurons(std::ifstream& file,int i) {
	std::string line;
	while (std::getline(file, line)) {
		for (int j = 0; j < (int)line.length(); j++) {
			if (line[j] == '+')
				this->neurons[i]->setStan(1); //stan aktywny neuronu, kazde inne maja stan nieaktywny ( z konstruktora)
			i++;
		}
	}
}

void Network::insertSynapses() {
	for (int k = 0; k < size; k++) {
		for (int n = 0; n < size; n++) {
			if (n == k)
				continue; //neuron dla samego siebie ma polaczenie o wadze 0
			if (neurons[k]->getStan() == neurons[n]->getStan()) {
				*connections[k * size + n] + 1; //gdy neurony maja taka sama wartosc, zwiekszamy wage (przeciazony operator)
			}
			else {
				*connections[k * size + n] - 1; //(przeciazony operator) zmniejszamy wage polaczenia 
			}
		}
	}
}

void Network::resetNeurons() {
	for (int i = 0; i < (int)neurons.size(); i++)
		neurons[i]->setStan(0);
}

//wyswietlenie stanu neuronow (wzorca zapisanegow sieci)
void Network::showNeurons() {
	int k = 0;
	for (int i = 0; i < size; i++) {
		if (k % filexSize == 0)
			std::cout << std::endl;
		if (neurons[i]->getStan() == 1)
			std::cout << "+";
		else
			std::cout << " ";
		k++;
	}
}

void Network::recognizingAlg() {
	bool check = true;
	int sila; //sila polaczen
	int losowa, num; // losowa -> indeks neuronu ; num -> indeks synapsy
	cout << "\n\n\n\nEtap rozpoznawania liczby: " << endl;
	while (check) {
		check = false;
		for (int i = 0; i < size; i++) {
			sila = 0;
			losowa = (int)rand() % size; 
			for (int j = 0; j < (int)neurons.size(); j++) { //dla neuronu[losowa] sumujemy stany przemnozone przez wage
				if (losowa == j)
					continue; //neuron nie ma polaczenia do samego siebie

				num = losowa * size + j; // numer synapsy; 
				sila += neurons[j]->getStan() * connections[num]->getValue(); //sumator potencjalu neuronu, kazdy z neuronow wchodzi na wejscie kazdego
			}
			//funkcja aktywacji -> sila < 0 -> nieaktywny
			if (sila < 0) {
				if (neurons[losowa]->getStan() != -1) //zmiana
					check = true;

				neurons[losowa]->setStan(-1);
			}
			else {
				if (neurons[losowa]->getStan() != 1)//zmiana
					check = true;
				neurons[losowa]->setStan(1);
			}

		}
		showNeurons();
	}
	std::cout << endl << endl << endl<<"Liczba rozpoznany przez siec: " << std::endl;
	showNeurons();
}


