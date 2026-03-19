/*
	Auteur :
		* Max Bleriot Mba Fossi - 2417938
		* Roosevelt Sonfack Ngoune - 2464064
	Date : 03/18/2026
*/

#pragma once

#include <string>
#include <ostream>

using namespace std;

class Affichable {
public:
	virtual ~Affichable() = default;
	virtual ostream& afficher(ostream& os) const = 0;

	enum Couleur {
		RESET,
		XXX, XXXI, XXXII, XXXIII, XXXIV, XXXV, XXXVI, XXXVII,
		IC, ICI, ICII, ICIII, ICIV, ICV, ICVI, ICVII
	};

	virtual ostream& changerCouleur(ostream& os, Couleur couleur) const = 0;
};