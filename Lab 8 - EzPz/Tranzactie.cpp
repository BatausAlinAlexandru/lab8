#include "Tranzactie.h"
#include <sstream>
Tranzactie::Tranzactie() {
	this->zi = 0;
	this->suma = 0;
	this->tip = "";
	this->descriere = "";
};

Tranzactie::Tranzactie(int zi, int suma_bani, std::string tip, std::string descriere) {
	this->zi = zi;
	this->suma = suma_bani;
	this->tip = tip;
	this->descriere = descriere;
};

Tranzactie::Tranzactie(const Tranzactie& tranzactie) {
	this->zi = tranzactie.zi;
	this->suma = tranzactie.suma;
	this->tip = tranzactie.tip;
	this->descriere = tranzactie.descriere;
};

Tranzactie::~Tranzactie() {
};

int Tranzactie::getZi() {
	return this->zi;
};

int Tranzactie::getSuma() {
	return this->suma;
};

std::string Tranzactie::getTip() {
	return this->tip;
};

std::string Tranzactie::getDescriere() {
	return this->descriere;
};

void Tranzactie::setZi(int value) {
	this->zi = value;
};

void Tranzactie::setSuma(int value) {
	this->suma = value;
};

void Tranzactie::setTip(std::string value) {
	this->tip = value;
};

void Tranzactie::setDescriere(std::string value) {
	this->descriere = value;
};

Tranzactie& Tranzactie::operator=(const Tranzactie& tranzactie) {
	if (this != &tranzactie)
		this->setZi(tranzactie.zi), this->setSuma(tranzactie.suma), this->setTip(tranzactie.tip), this->setDescriere(tranzactie.descriere);
	return *this;
}
bool Tranzactie::operator==(const Tranzactie& tranzactie)
{
	return ((this->zi == tranzactie.zi) && (this->suma == tranzactie.suma) && (this->tip == tranzactie.tip));
};

std::ostream& operator<<(std::ostream& os, const Tranzactie& tranzactie)
{
	if (tranzactie.descriere.empty())
		os << tranzactie.zi << " " << tranzactie.suma << " " << tranzactie.tip << " ";
	else
		os << tranzactie.zi << " " << tranzactie.suma << " " << tranzactie.tip << " " << tranzactie.descriere;
	return os;
}
#include <iostream>
std::istream& operator>>(std::istream& is, Tranzactie& tranzactie)
{
	std::string descrierea_mea;
	is >> tranzactie.zi >> tranzactie.suma >> tranzactie.tip;
	std::getline(is, descrierea_mea);
	if (descrierea_mea[0] == ' ') {
		descrierea_mea.erase(std::remove(descrierea_mea.begin(), descrierea_mea.begin() + 1, ' '), descrierea_mea.begin() + 1);
	}
	tranzactie.descriere = descrierea_mea;
	std::cout << descrierea_mea << std::endl;

	return is;
}
