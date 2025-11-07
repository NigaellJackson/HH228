#include "Header.h"
#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

Photograph::Photograph() {
	name = "";
	surname = "";
	gender = "";
	yearbirth = 0;
	yearjob = 0;
	rating = 0;
}

Photograph::Photograph(string n, string s, string g, int yb, int yj, double r) {
	name = n;
	surname = s;
	gender = g;
	yearbirth = yb;
	yearjob = yj;
	rating = r;
}

void Photograph::setName(string n) { name = n; }
void Photograph::setSurname(string s) { surname = s; }
void Photograph::setGender(string g) { gender = g; }
void Photograph::setYearBirth(int y) { yearbirth = y; }
void Photograph::setYearjob(int yj) { yearjob = yj; }
void Photograph::setRating(double r) { rating = r; }
string Photograph::getName() { return name; }
string Photograph::getSurname() { return surname; }
double Photograph::getRating() const { return rating; }

void Photograph::printInfo() {
	cout << "Имя: " << name << '\n';
	cout << "Фамилия: " << surname << '\n';
	cout << "Пол: " << gender << '\n';
	cout << "Год рождения: " << yearbirth << '\n';
	cout << "Год начала деятельности: " << yearjob << '\n';
	cout << "Рейтинг: " << rating << '\n';
}

void Photograph::serialize() const {
	ofstream out("photograph.txt");
	if (out.is_open()) {
		out << name << '\n' << surname << '\n' << gender << '\n' << yearbirth << '\n' << yearjob << '\n' << rating;
		out.close();
	}

}

void Photograph::deserialize() {
	ifstream in("photograph.txt");
	if (in.is_open()) {
		in >> name >> surname >> gender >> yearbirth >> yearjob >> rating;
		in.close();
	}
}

void Photograph::serialize(const string& filename) const {
	ofstream out(filename);
	if (out.is_open()) {
		out << name << '\n' << surname << '\n' << gender << '\n' << yearbirth << '\n' << yearjob << '\n' << rating;
		out.close();
	}
}

void Photograph::deserialize(const string& filename) {
	ifstream in(filename);
	if (in.is_open()) {
		in >> name >> surname >> gender >> yearbirth >> yearjob >> rating;
		in.close();
	}
}

void Photograph::addRating(int golosa) {
	
	if (golosa >= 10) {
		double dobavit = (rand() % 101) / 100.0;
		rating += dobavit;
	}
}

