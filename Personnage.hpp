/*
	Auteur :
		* Max Bleriot Mba Fossi - 2417938
		* Roosevelt Sonfack Ngoune - 2464064
	Date : 03/18/2026
*/

#pragma once 

#include <string>
#include <fstream>
#include "Affichable.hpp"
#include <cstdint>

using namespace std;

class Personnage : public Affichable {
public:
	Personnage() = default;
	Personnage(string nom, string parution) : nom_(nom), parution_(parution){}

	~Personnage() = default;

	ostream& afficher(ostream& os) const override {
		os << "Nom: " << nom_ << endl;
		os << "Parution: " << parution_ << endl;
		return os;
	}

	ostream& changerCouleur(ostream& os, Couleur couleur) const override {
		int color = couleur == 0 ? 0 : couleur - 1 + this->moduloCouleur_;
		if (color != 0) {
			color = color % 16;
			color = color <= 8 ? color + 30 : color + 90;
		}

		os << "\033[" + to_string(color) + 'm';
		return os;
	}
	
	string getNom() const { return nom_; }
	string getParution() const { return parution_; }

	void setNom(string nom) { nom_ = nom; }
	void setParution(string parution) { parution_ = parution; }
	

private:
	string nom_;
	string parution_;

protected:
	Personnage(const Personnage& autre) : nom_(autre.nom_), parution_(autre.parution_) {}

	uint8_t moduloCouleur_ = 0;
};