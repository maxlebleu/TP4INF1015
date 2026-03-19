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
		
	~Heros() = default;

	void ajouterAllies(string nom) {		
		if (allies_.size() == allies_.capacity()) {
			auto capacite = (allies_.capacity() == 0) ? 1 : 2 * allies_.capacity();
			allies_.reserve(capacite);
		}
		allies_.push_back(nom);
	}

	string getEnnemi() const { return ennemi_; }
	ostream& afficher(ostream& os) const override {
		Personnage::afficher(os);
		os << "Ennemi: " << ennemi_ << endl;
		os << "Alli�s: " << endl;
		for (auto nom : allies_) {
			os << "\t" << nom << endl;
		}
		return os;
	}

protected:
	uint8_t moduloCouleur_ = 1;

	string ennemi_;
	vector<string> allies_;
};