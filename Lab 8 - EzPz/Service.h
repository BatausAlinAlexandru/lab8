#pragma once
#include "RepoSmecher.h"
#include "Tranzactie.h"
class Service {
private:
	RepoSmecher<Tranzactie>& repo;
public:
	Service(RepoSmecher<Tranzactie>& repo);
	~Service();

	std::vector<Tranzactie> getAll();

	void addTranzactie(int zi, int suma, std::string tip, std::string descriere);

};

