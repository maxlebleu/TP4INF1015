/*
	Auteur :
		* Max Bleriot Mba Fossi - 2417938
		* Roosevelt Sonfack Ngoune - 2464064
	Date : 03/18/2026
*/

#pragma once 

#include <string>
#include "Personnage.hpp"
#include <vector>

using namespace std;

class Heros : public Personnage {
public:
	Heros() = default;
	Heros(string nom, string parution, string ennemi): 
		Personnage(nom, parution), ennemi_(ennemi) {}
	void ajouterAllies(string nom) {		
		if (allies_.size() == allies_.capacity()) {
			auto capacite = (allies_.capacity() == 0) ? 1 : 2 * allies_.capacity();
			allies_.reserve(capacite);
		}
		allies_.push_back(nom);
	}
	~Heros() = default;
	string getEnnemi() const { return ennemi_; }
	ostream& afficher(ostream& os) const override {
		//Personnage::changerCouleur(os, 94);
		Personnage::afficher(os);
		os << "Ennemi: " << ennemi_ << endl;
		os << "Alliés: " << endl;
		for (auto nom : allies_) {
			os << "\t" << nom << endl;
		}
		return os;
	}
	ostream& changerCouleur(ostream& os, int couleur) const override {
		os << "\033[" + to_string(couleur) + 'm';
		return os;
	}
protected:
	string ennemi_;
	vector<string> allies_;
};