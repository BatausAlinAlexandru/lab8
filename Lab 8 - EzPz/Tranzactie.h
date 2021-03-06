#pragma once
#include <string>
#include <fstream>

class Tranzactie {
private:
	int zi;
	int suma;
	std::string tip;
	std::string descriere;
public:
	Tranzactie();
	Tranzactie(int zi, int suma_bani, std::string tip, std::string descriere);
	Tranzactie(const Tranzactie& tranzactie);
	~Tranzactie();

	int getZi();
	int getSuma();
	std::string getTip();
	std::string getDescriere();

	void setZi(int value);
	void setSuma(int value);
	void setTip(std::string value);
	void setDescriere(std::string value);

	// Operatori :D
	Tranzactie& operator=(const Tranzactie& tranzactie);
	bool operator==(const Tranzactie& tranzactie);
	friend std::ostream& operator<<(std::ostream& os, const Tranzactie& tranzactie);
	friend std::istream& operator>>(std::istream& is, Tranzactie& tranzactie);

};

