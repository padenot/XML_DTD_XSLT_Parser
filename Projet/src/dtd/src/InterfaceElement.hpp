/*************************************************************************
 * InterfaceElement  -  «Description»
 * -------------------
 * Début      : 5 avr. 2011
 * Auteur(s)  : H4215
 *************************************************************************/

//---------- Interface de la classe <InterfaceElement> (fichier InterfaceElement.hpp) ------
#if ! defined ( INTERFACEELEMENT_HPP_ )
#define INTERFACEELEMENT_HPP_

//--------------------------------------------------- Interfaces utilisées
#include <string>
#include "Node.hh"
#include "InterfaceNodeVisitor.hpp"

namespace dtd
{
class AttributesList;
class Content;

class InterfaceElement: public xml::InterfaceNodeVisitor
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

	virtual bool matches(xml::Node& node) const = 0;
	// Mode d'emploi :
	//	Renvoie vrai si le noeud passé en paramètre a le même espace de noms
	//	et le même nom que l'élément, faux sinon.
	// Contrat :
	//	Aucun.

	virtual std::string ns() const = 0;
	// Mode d'emploi :
	//	Renvoie l'espace de nom associé à cet élément.
	// Contrat :
	//	Aucun.

	virtual std::string name() const = 0;
	// Mode d'emploi :
	//	Renvoie le nom associé à cet élément.
	// Contrat :
	//	Aucun.

	virtual const AttributesList& attributesList() const = 0;
	// Mode d'emploi :
	//	Renvoie la liste d'attributs associée à cet élément.
	// Contrat :
	//	Aucun.

	virtual const Content& content() const = 0;
	// Mode d'emploi :
	//	Renvoie le contenu de cet élément.
	// Contrat :
	//	Aucun.


	//------------------------------------------------- Surcharge d'opérateurs


	//-------------------------------------------- Constructeurs - destructeur
	virtual ~InterfaceElement()
	// Mode d'emploi (destructeur) :
	//	Ne fait rien (interface).
	// Contrat :
	//	Aucun.
	{
		// Vide
	}

protected:

};

} // namespace dtd

#endif // INTERFACEELEMENT_HPP_
