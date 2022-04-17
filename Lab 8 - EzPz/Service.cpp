#include "Service.h"

Service::Service() : repo(repo)
{
}

Service::Service(RepoSmecher<Tranzactie>& repo) : repo(repo) {
}

Service::~Service() {
};

std::vector<Tranzactie> Service::getAll()
{
    return this->repo.getAll();
    
}

void Service::addTranzactieService(int zi, int suma, std::string tip, std::string descriere) {
    Tranzactie tranzactie(zi, suma, tip, descriere);
    this->repo.addElem(tranzactie);
};
