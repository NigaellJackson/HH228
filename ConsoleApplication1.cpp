#include <iostream>
#include <cstring>
#include <cmath>
#include <ctime>
#include "Header.h"
using namespace std;

int main()
{
	srand(time(0));
	setlocale(LC_ALL, "Russian");
	Photograph p1("Александр", "Смирнов", "Мужской", 1979, 2000, 7.2);
	p1.printInfo();
	cout << "\n";
	Photograph p2("Анастасия", "Козловская", "Женский", 1984, 2006, 7.5);
	p2.printInfo();
	cout << "\n";
	Photograph p3("Иван", "Иванов", "Мужской", 1974, 1999, 6.8);

	Photograph spisok[3] = { p1, p2, p3 };
	for (int i = 0; i < 3; i++) {
		int golosa = rand() % 21;
		spisok[i].addRating(golosa);
		cout << spisok[i].getName() << "\nПолучил голосов: " << golosa << endl << "\n";
	}
	cout << "\n";
	for (int i = 0; i < 3 - 1; i++) {
		for (int j = 0; j < 3 - i - 1; j++) {
			if (spisok[j].getRating() < spisok[j + 1].getRating()) {
				Photograph a = spisok[j];
				spisok[j] = spisok[j + 1];
				spisok[j + 1] = a;
			}
		}
	}
	
	for (int i = 0; i < 3; i++) {
		spisok[i].printInfo();
		cout << "\n";
	}

	p1.serialize("photograph.txt");
	p2.serialize("photograph.txt");
	p3.serialize("photograph.txt");
}