/*
	Auteur :
		* Max Bleriot Mba Fossi - 2417938
		* Roosevelt Sonfack Ngoune - 2464064
	Date : 03/18/2026
*/

#include <fstream>
#include <iostream>
#include "bibliotheque_cours.hpp"
#include "VilainHeros.hpp"
#include <span>
#include "constantes.hpp"
#include <cstdint>
#include <memory>

using namespace std;

using UInt8  = uint8_t;
using UInt16 = uint16_t;

UInt8 lireUint8(istream& fichier)
{
	UInt8 valeur = 0;
	fichier.read(reinterpret_cast<char*>(&valeur), sizeof(valeur));
	return valeur;
}

UInt16 lireUint16(istream& fichier)
{
	UInt16 valeur = 0;
	fichier.read(reinterpret_cast<char*>(&valeur), sizeof(valeur));
	return valeur;
}

string lireString(istream& fichier)
{
	string texte;
	texte.resize(lireUint16(fichier));
	fichier.read(reinterpret_cast<char*>(&texte[0]), streamsize(sizeof(texte[0])) * texte.length());
	return texte;
}

template <class T>
concept Dereferencable = requires (T&& t) { *std::forward<T>(t); };

// Surcharge quand c'est un pointeur
template <Dereferencable T> 
decltype(auto) as_ref(T&& t)
{
	return *std::forward<T>(t);
}

// Surcharge moins contrainte (donc quand ce n'est pas un pointeur)
template <class T>
T&& as_ref(T&& t) {
	return std::forward<T>(t);
}

template<typename T>
void lireT(istream& f, vector<shared_ptr<T>>& listeT) {
	static_assert(std::is_same<T, Heros>::value || std::is_same<T, Vilain>::value);
	unsigned taille = lireUint16(f);
	while (taille > 0) {
		string nom = lireString(f);
		string parution = lireString(f);
		shared_ptr<T> t;
		if constexpr (std::is_same_v<T, Vilain>) {
			string objectif = lireString(f);
			t = make_shared<T>(nom, parution, objectif);
		}
		else {
			string ennemi = lireString(f);
			t = make_shared<T>(nom, parution, ennemi);
			unsigned sousTaille = lireUint8(f);
			while (sousTaille > 0) {
				t->ajouterAllies(lireString(f));
				sousTaille--;
			}
		}		
		taille--;
		listeT.push_back(t);
	}
	
}

template<typename T>
void afficherListe(vector<shared_ptr<T>>& listeT, const string& ligneSeparation, int couleur) {
	static_assert(std::is_same<T, Heros>::value || std::is_same<T, Vilain>::value || std::is_same<T, Personnage>::value || std::is_same<T, VilainHeros>::value);
	
	for (const auto t : listeT) {
		t->changerCouleur(cout, couleur);
		t->afficher(cout);
		cout << ligneSeparation;
	}
	//Personnage::changerCouleur(cout, 0);
}

int main()
{
	#pragma region "Bibliothèque du cours"
	// Permet sous Windows les "ANSI escape code" pour changer de couleur
	// https://en.wikipedia.org/wiki/ANSI_escape_code ; les consoles Linux/Mac
	// les supportent normalement par défaut.
	bibliotheque_cours::activerCouleursAnsi();
	#pragma endregion
	
	// Trait de separation
	static const string trait =
		"\n═════════════════════════════════════════════════════════════════════════\n";

	// Ouverture des fichiers binaires
	ifstream fichierHeros("heros.bin", ios::binary);
	ifstream fichierVilains("vilains.bin", ios::binary);
	fichierHeros.exceptions(ios::failbit);
	fichierVilains.exceptions(ios::failbit);

	//TODO: Votre code pour le main commence ici
	auto listeHeros = vector<shared_ptr<Heros>>();
	auto listeVilains = vector<shared_ptr<Vilain>>();
	auto listePersonnage = vector<shared_ptr<Personnage>>();
	auto listeVH = vector<shared_ptr<VilainHeros>>();
	lireT<Heros>(fichierHeros, listeHeros);
	lireT<Vilain>(fichierVilains, listeVilains);		
	
	cout << "***************  HEROS  *************** " << endl;
	afficherListe<Heros>(listeHeros, trait, 1);
	cout << "***************  VILAINS  *************** " << endl;
	afficherListe<Vilain>(listeVilains, trait, 4);
		
	listePersonnage.insert(listePersonnage.end(), listeHeros.begin(), listeHeros.end());
	listePersonnage.insert(listePersonnage.end(), listeVilains.begin(), listeVilains.end());

	cout << "***************  PERSONNAGES  *************** " << endl;
	
	afficherListe<Personnage>(listePersonnage, trait, 0);
	
	for (auto h : listeHeros) {
		int pos = 0;
		do {
			pos = rand() % listeVilains.size();
		} while (h->getEnnemi() == listeVilains[pos]->getNom());
		
		auto vilainHeros = make_shared<VilainHeros>(*listeVilains[pos], *h);

		listeVH.push_back(vilainHeros);
	}

	cout << "***************  VILAIN-HEROS  *************** " << endl;

	afficherListe<VilainHeros>(listeVH, trait, 7);

}
