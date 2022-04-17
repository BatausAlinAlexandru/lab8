#pragma once
#include "Tranzactie.h"
#include <iostream>
#include <fstream>
#include <vector>

template <class T>
class RepoSmecher {
private:
	std::vector<T> vector;
	std::string filename;

public:
	RepoSmecher();
	RepoSmecher(std::string filename);
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

template<class T>
inline RepoSmecher<T>::RepoSmecher() {
	this->filename = "";
}


template<class T>
inline RepoSmecher<T>::RepoSmecher(std::string filename) {
	if (filename.empty()) {
		std::cout << "Pune un nume la fisier.\n";
		return;
	}
	else {
		this->filename = filename;
	}
	this->loadFromFile();
};


template<class T>
inline RepoSmecher<T>::~RepoSmecher() {
	this->filename = "";
}

template<class T>
std::vector<T> RepoSmecher<T>::getAll()
{
	return this->vector;
};



template<class T>
void RepoSmecher<T>::addElem(const T& elem) {
	this->vector.push_back(elem);
	this->saveToFile();
};


template<class T>
void RepoSmecher<T>::updateElem(const T& oldelem, const T& newelem) {
	for (int i = 0; i < this->vector.size(); i++)
		if (this->vector[i] == oldelem)
			this->vector[i] = newelem;

	this->saveToFile();
};


template<class T>
void RepoSmecher<T>::deleteElem(const T& elem) {
	typename std::vector<T>::iterator it = find(this->vector.begin(), this->vector.end(), elem);
	if (it != this->vector.end())
		this->vector.erase(it);
	this->saveToFile();
};

template<class T>
void RepoSmecher<T>::loadFromFile()
{
	if (this->filename.empty()) {
		std::cout << "Este gol !!!! \n";
	}
	else {
		std::ifstream file(this->filename);
		T element;
		while (!file.eof()) {
			file >> element;
			if (!(element == T()))
				this->addElem(element);
		}
		file.close();
	}
};

template<class T>
void RepoSmecher<T>::saveToFile() {
	if (this->filename.empty()) {
		std::cout << "probleme\n";
	}
	else {
		std::ofstream file(this->filename);
		for (int i = 0; i < this->vector.size(); i++)
			if(i < this->vector.size() - 1)
				file << this->vector[i] << '\n';
			else
				file << this->vector[i];
	}
};
