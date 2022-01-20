#include "FileHandling.h"
using namespace std;

void FileHandling::checkArguments(int argc, char* argv[]){
	//zmienne pomocnicze
	bool u = false;
	bool r = false;
	string arg, arg2;

	//petla przechodzaca po przeslanych argumentach
	for (int i = 1; i < argc; i++) {
			arg = argv[i];
			if (arg == "-h") {
				showHelp();
				exit(1);
			}
			//czesc odpowiedzialna za zapis plikow uczacych do wektora
			if (arg == "-u") {
				bool check = true;
				
				while(check){
					int j = i + 1;
					if (i+1 >= argc) { //jesli argument jest ostatni na liscie
						if (teachData.empty()) {
							argErrorMess();
							exit(1);
						}
						else
							check = false;
					}
					else {
						arg2 = argv[j];
						if (arg2[0] == '-') {//kolejny rodzaj argumentu
							if (teachData.empty()) {
								argErrorMess();
								exit(1);
							}
							else {
								check = false;
							}

						}
						else {
							u = true;
							teachData.push_back(arg2);
							i++;
						}
					}
					
					
				}

			}
			if (arg == "-r") {
				if (i + 1 >= argc) {
					argErrorMess();
					exit(1);
				}
				r = true;
				arg2 = argv[i + 1];
				forRecognise = arg2;
				i++;
			}
	
	}
	if (u == false || r == false) {
		argErrorMess();
		exit(1);
	}
	cout << "Argumenty OK, przechodzimy do budowania sieci..." << endl;
}

void FileHandling::runNetwork(){
	auto pair = buildNetwork();
	Network network(pair.first, pair.second);
	network.teach(teachData);
	network.recognize(forRecognise);
}

pair<int,int> FileHandling::buildNetwork() {
	checkFile(teachData[0]);
	ifstream file(teachData[0]);
	std::string line;
	std::getline(file, line);
	fileYSize++;
	fileXSize = line.length();
	while (std::getline(file, line)) {
		fileYSize++;
		if (fileXSize != line.length()) {
			IUser::fileErrorMess(2);
		}
	}
	file.close();
	pair<int, int> sizePair;
	sizePair.first = fileXSize;
	sizePair.second = fileYSize;
	return sizePair;
}

void FileHandling::checkFile(std::string& fileName) {
	ifstream file(fileName);
	if (!file.is_open()) {
		IUser::fileErrorMess(2);
		exit(1);
	}
	file.seekg(0, ios::end);
	if (file.tellg() == 0) //plik jest pusty
	{
		IUser::fileErrorMess(3);
		exit(1);
	}
	file.seekg(0); //powrot na poczatek pliku, gdy nie jest pusty
	string line;
	int  fileX;
	getline(file, line);
	fileX = line.length();
	while (std::getline(file, line)) {
		if (fileX != line.length()) {
			IUser::fileErrorMess(2);
			exit(1);
		}
	}
	file.seekg(0);
	file.close();
}

void FileHandling::showHelp()const {
	cout << " \t\t** HELP ** \nPrawidlowe parametry przeslane do pliku:" << endl <<
		"-u <plikUczacy> -r <plikDoRozpoznania>" << endl << "[-h = wyswietlenie helpa]" << endl
		<< "*Kolejnosc parametrow nie ma znaczenia*" << endl;
		exit(1);
	}

void FileHandling::argErrorMess()const{
	cout << "Zle argumenty wejsciowe. Aby wyswietlic pomoc wpisz '-h'"<<endl;
}
