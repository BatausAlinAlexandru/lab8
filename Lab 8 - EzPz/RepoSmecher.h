#pragma once
#include <fstream>
#include <vector>

template <class T>
class RepoSmecher {
private:
	std::vector<T> vector;
	std::string filename;

public:
	RepoSmecher();
	RepoSmecher(const std::string filename);
	~RepoSmecher();

	std::vector<T> getAll();
	// Functii 
	void addElem(const T& elem);
	void updateElem(const T& oldelem, const T& newelem);
	void deleteElem(const T& elem);
private:
	void loadFromFile();
	void saveToFile();
};
template <class T>
extern RepoSmecher<T> repo;