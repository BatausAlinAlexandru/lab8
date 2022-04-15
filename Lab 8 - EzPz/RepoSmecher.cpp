#include <fstream>
#include "RepoSmecher.h"



template<class T>
inline RepoSmecher<T>::RepoSmecher() {
	// Nothing here
}


template<class T>
inline RepoSmecher<T>::RepoSmecher(const std::string filename) {
	if (this->filename == "") {
		/*std::cout << "Pune un nume la fisier.\n";*/
		continue;
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
void RepoSmecher<T>::deleteElem(const T& elem){
	typename std::vector<T>::iterator it = find(this->vector.begin(), this->vector.end(), elem);
	if (it != this->vector.end())
		this->vector.erase(it);
	this->saveToFile();
};

template<class T>
void RepoSmecher<T>::loadFromFile()
{
	if (this->filename) {
		std::ifstream file(this->filename);
		T element;
		while (!file.eof()) {
			file >> element;
			if (!element == T())
				this->addElem(element);
		}
		file.close();
	}
}

template<class T>
void RepoSmecher<T>::saveToFile() {
	if (this->filename) {
		std::ofstream file(this->filename);
		for (int i = 0; i < this->vector.size(); i++)
			file << this->vector[i] << std::endl;
	}
};

