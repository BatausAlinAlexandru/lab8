#pragma once
#include <vector>
#include "Service.h"

class Meniu {
private:
	Service& service;
public:
	Meniu(Service& service);
	~Meniu();


	virtual void RunUI();
private:
	virtual void PrintMenu();
	std::vector<std::string> desparteComanda(std::string linie);

	void UIAddTranzactie(std::string zi, std::string suma, std::string tip, std::string descriere);

};

