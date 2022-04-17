#include "RepoSmecher.h"
#include "Tranzactie.h"
#include "Service.h"

#include "Meniu.h"
int main() {
	RepoSmecher<Tranzactie> repo("alin.txt");
	Service service(repo);
	Meniu meniu(service);
	meniu.RunUI();

	
}