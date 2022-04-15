#include "Service.h"

Service::Service(RepoSmecher<Tranzactie>& repo) : Repo(repo) {
}

Service::~Service() {
};

std::vector<Tranzactie> Service::getAll()
{
    return this->repo.getAll();
}

void Service::addTranzactie(int zi, int suma, std::string tip, std::string descriere) {
    Tranzactie tranzactie(zi, suma, tip, descriere);
    this->repo.addElem(tranzactie);
};
