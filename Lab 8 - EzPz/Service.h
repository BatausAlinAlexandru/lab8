#pragma once
#include "RepoSmecher.h"
#include "Tranzactie.h"
class Service {
private:
	RepoSmecher<Tranzactie>& repo;
public:
	Service();
	Service(RepoSmecher<Tranzactie>& repo);
	~Service();

	std::vector<Tranzactie> getAll();

	void addTranzactieService(int zi, int suma, std::string tip, std::string descriere);

};

