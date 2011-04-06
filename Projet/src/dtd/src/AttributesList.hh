/*************************************************************************
 * AttributesList  -  «Description»
 * -------------------
 * Début      : 5 avr. 2011
 * Auteur(s)  : H4215
 *************************************************************************/

//---------- Interface de la classe <AttributesList> (fichier AttributesList.hh) ------
#if ! defined ( ATTRIBUTESLIST_HH_ )
#define ATTRIBUTESLIST_HH_

//--------------------------------------------------- Interfaces utilisées
#include <string>

namespace dtd
{
class InterfaceDTDVisitor;

class AttributesList
{
public:
	//------------------------------------------------------------- Constantes

	//------------------------------------------------------------------ Types

	//----------------------------------------------------- Méthodes publiques
	// type Méthode ( liste des paramètres );
	// Mode d'emploi :
	//	
	// Contrat :
	//	

	std::string name() const;
	// Mode d'emploi :
	//	Renvoie le nom de l'élément associé à cette liste d'attributs.
	// Contrat :
	//	Aucun.

	virtual void accept(InterfaceDTDVisitor& visitor) const;
	// Mode d'emploi :
	//	Permet à un visiteur d'inspecter cette liste d'attributs sous sa
	//	vraie identité (en lui révélant son type réel).
	//	Actuellement cette classe n'a pas de descendants et cette méthode
	//	n'est donc présente qu'à des fins de généricité.
	// Contrat :
	//	Aucun.

	//------------------------------------------------- Surcharge d'opérateurs


	//-------------------------------------------- Constructeurs - destructeur
	AttributesList(const std::string & name);
	// Mode d'emploi :
	//	TODO
	// Contrat :
	//	TODO

	virtual ~AttributesList();
	// Mode d'emploi :
	//	TODO
	// Contrat :
	//	TODO

protected:
	std::string _name;

};

} // namespace dtd

#endif // ATTRIBUTESLIST_HH_
