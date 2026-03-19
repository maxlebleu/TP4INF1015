/*
	Auteur :
		* Max Bleriot Mba Fossi - 2417938
		* Roosevelt Sonfack Ngoune - 2464064
	Date : 03/18/2026
*/

#pragma once 

#include <string>
#include "Personnage.hpp"

using namespace std;


class Vilain : public Personnage {
public:
	Vilain() {};
	Vilain(string nom, string parution, string objectif) : 
		Personnage(nom, parution), objectif_(objectif) {}
	~Vilain() = default;
	ostream& afficher(ostream& os) const override {
		Personnage::afficher(os);
		os << "Objectif: " << objectif_ << endl;		
		return os;
	}

protected:
	uint8_t moduloCouleur_ = 2;

	string objectif_;
};