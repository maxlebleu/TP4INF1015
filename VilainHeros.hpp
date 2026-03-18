/*
	Auteur :
		* Max Bleriot Mba Fossi - 2417938
		* Roosevelt Sonfack Ngoune - 2464064
	Date : 03/18/2026
*/

#pragma once 

#include "Heros.hpp"
#include "Vilain.hpp"
#include <string>

using namespace std;

class VilainHeros : virtual public Heros, virtual public Vilain {
public:
	VilainHeros(){}
	VilainHeros(Vilain v, Heros h): Heros(h), Vilain(v)
	{
		Vilain::setNom(v.getNom() + "-" + h.getNom());
		Vilain::setParution(v.getParution() + "-" + h.getParution());
		
		mission_speciale_ = objectif_ + " dans le monde de " + h.getParution();
	}
	~VilainHeros() = default;
	ostream& changerCouleur(ostream& os, int couleur) const override {
		os << "\033[" + to_string(couleur) + 'm';
		return os;
	}
	ostream& afficher(ostream& os) const override {
		Vilain::afficher(os);
		os << "Ennemi: " << ennemi_ << endl;
		os << "Alliés: " << endl;
		for (auto nom : allies_) {
			os << "\t" << nom << endl;
		}
		os << "Mission spéciale : " << mission_speciale_;
		return os;
	}
private:
	string mission_speciale_;
};