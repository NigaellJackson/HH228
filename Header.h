#pragma once
#include <string>
#include <cmath>
using namespace std;

class Photograph {
private:
	string name;
	string surname;
	string gender;
	int yearbirth;
	int yearjob;
	double rating;
public:
	Photograph();
	Photograph(string n, string s, string g, int yb, int yj, double r);
	void setName(string n);
	void setSurname(string s);
	void setGender(string g);
	void setYearBirth(int yb);
	void setYearjob(int yj);
	void setRating(double r);
	string getName();;
	string getSurname();
	double getRating() const;
	void addRating(int golosa);
	void printInfo();
	void serialize() const;
	void serialize(const std::string& filename) const;
	void deserialize();
	void deserialize(const std::string& filename);

};