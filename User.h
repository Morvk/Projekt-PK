#pragma once

class User
{
	virtual ~User() {}
	// funkcja wirtualna (destruktor)


	static void filerror(int opt);
	// Statyczna metoda, w ktorej zaimplementowalem komunikaty 
	// informujace o bledach zwiazanych z przeslanym plikiem
	// obsluguje nastepujace komunikaty:
	// pusty plik lub linie o roznych dlugosciach
	// nieprawidlowe otwarcie pliku


	virtual void argerror()const = 0;
	//odpowiada za wyswietlanie komunikatow o bledach wejsciowych argumentow


	virtual void showhelp()const = 0;
	// dotyczy wyswietlania okna pomocy programu
}