/*************************************************************************
 * Element  -  «Description»
 * -------------------
 * Début      : 5 avr. 2011
 * Auteur(s)  : H4215
 *************************************************************************/

//---------- Interface de la classe <Element> (fichier Element.hh) ------
#if ! defined ( ELEMENT_HH_ )
#define ELEMENT_HH_

//--------------------------------------------------- Interfaces utilisées
#include <string>
#include "InterfaceElement.hpp"
#include "BadReferenceException.hpp"

namespace dtd
{
class DTD;
class InterfaceDTDVisitor;
class Content;

class Element: public InterfaceElement
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

	virtual bool matches(xml::Node& node);

	virtual std::string ns() const;

	virtual std::string name() const;

	virtual const AttributesList& attributesList() const
			throw (BadReferenceException);

	virtual const Content& content() const;

	virtual void accept(InterfaceDTDVisitor& visitor) const;
	// Mode d'emploi :
	//	Permet à un visiteur d'inspecter cet élément sous sa vraie identité
	//	(en lui révélant son type réel).
	//	Actuellement cette classe n'a pas de descendants et cette méthode
	//	n'est donc présente qu'à des fins de généricité.
	// Contrat :
	//	Aucun.

	virtual bool isValid(xml::Node& node) const;
	// Mode d'emploi :
	//	Renvoie vrai si le noeud passé en paramètre respecte la strucure
	//	imposée par l'élément (attributs et contenu), et si ses descendants
	// 	sont référencés dans la même DTD que cet élément et respectent
	//	également la structure imposée par les éléments correspondants de
	//	la même DTD (attributs et contenu).
	//	Renvoie faux sinon.
	// Contrat :
	//	Aucun.

	//------------------------------------------------- Surcharge d'opérateurs


	//-------------------------------------------- Constructeurs - destructeur
	Element(DTD& dtd, const std::string & ns, const std::string & name,
			Content & content);
	// Mode d'emploi :
	//	TODO
	// Contrat :
	//	TODO

	virtual ~Element();
	// Mode d'emploi :
	//	TODO
	// Contrat :
	//	TODO

protected:
	DTD& _dtd;
	std::string _namespace;
	std::string _name;
	Content& _content;

};

} // namespace dtd

#endif // ELEMENT_HH_
