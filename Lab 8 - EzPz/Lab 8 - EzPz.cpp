#include <iostream>
#include "RepoSmecher.h"
#include "Tranzactie.h"
#include "Service.h"
int main() {
	RepoSmecher<Tranzactie> repo{ "alin.txt" };
	Service service(repo);
	service.addTranzactie(17, 245, "in", "alin 2002");
	service.addTranzactie(17, 245123, "out", "alin 2002");
}