/*************************************************************************
 * Attribute  -  «Description»
 * -------------------
 * Début      : 13 avr. 2011
 * Auteur(s)  : H4215
 *************************************************************************/

//---------- Interface de la classe <Attribute> (fichier Attribute.hh) ------
#if ! defined ( ATTRIBUTE_HH_ )
#define ATTRIBUTE_HH_

//--------------------------------------------------- Interfaces utilisées
#include <string>

namespace dtd
{

class Attribute
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

	//------------------------------------------------- Surcharge d'opérateurs


	//-------------------------------------------- Constructeurs - destructeur
	Attribute(const std::string & name);

	virtual ~Attribute();

protected:
	std::string _name;

};

} // namespace dtd

#endif // ATTRIBUTE_HH_
