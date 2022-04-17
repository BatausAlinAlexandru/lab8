#include <iostream>
#include <vector>
#include "Meniu.h"
#include <sstream>



Meniu::Meniu(Service& service) : service(service) {
};

Meniu::~Meniu() {
};

void Meniu::RunUI() {
	std::string comanda;
	bool optiune_gresita;

	while (true) {
		this->PrintMenu();

		std::getline(std::cin, comanda);
		std::vector<std::string> parametriCmd = desparteComanda(comanda);
		optiune_gresita = true;
		if (parametriCmd[0] == "adauga") {
			if (parametriCmd.size() != 5)
			{
				std::cout << "Format comanda gresita!";
			}
			else
			{
				this->UIAddTranzactie(parametriCmd[1], parametriCmd[2], parametriCmd[3], parametriCmd[4]);
				optiune_gresita = false;
			}
		}

	}
}


void Meniu::PrintMenu() {
	std::cout << std::endl;

	std::cout << "adauga {zi} {suma} {in/out} {[descriere]} " << std::endl;


	std::cout << std::endl;
};

void push_backDemo(std::string str1, std::string str2)
{
	// Appends character by character str2
	// at the end of str1
	for (int i = 0; str2[i] != '\0'; i++)
	{
		str1.push_back(str2[i]);
	}
	std::cout << "After push_back : ";
	std::cout << str1 << std::endl;
	str1.push_back(' ');
}

std::vector<std::string> Meniu::desparteComanda(std::string linie)
{
	std::vector<std::string> rezultat;
	std::stringstream ss(linie);
	std::string token;

	std::string descriereS;
	bool merge = true;
	while (std::getline(ss, token, ' ') && merge)
	{
		if (token[0] == '[')
			merge = false;
		else
			rezultat.push_back(token);
	}

	bool pentru_for = false;
	for (int i = 0; linie[i] != '\0'; i++) {
		if (linie[i] == '[' || pentru_for)
			descriereS.push_back(linie[i]), pentru_for = true;
		if (linie[i] == ']')
			pentru_for = false;
	}

	
	rezultat.push_back(descriereS);
	return rezultat;
}
void Meniu::UIAddTranzactie(std::string zi, std::string suma, std::string tip, std::string descriere) {
	this->service.addTranzactieService(stoi(zi), stoi(suma), tip, descriere);
};