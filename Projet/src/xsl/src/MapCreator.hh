/*************************************************************************
 * MapCreator  -  Description
 * -------------------
 * Début      : 15 avr. 2011
 * Auteur(s)  : H4215
 *************************************************************************/

//---------- Interface de la classe <MapCreator> (fichier MapCreator.hh) ------
#if ! defined ( MAPCREATOR_HH_ )
#define MAPCREATOR_HH_

//--------------------------------------------------- Interfaces utilisées

#include "InterfaceNodeVisitor.hpp"
#include "Node.hh"
#include "TextNode.hh"
#include "MarkupNode.hh"
#include "CompositeMarkupNode.hh"
#include <map>

namespace xsl
{

class MapCreator: public xml::InterfaceNodeVisitor
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
	void populateMap(const xml::Node& xslTree);

	//------------------------------------------------- Surcharge d'opérateurs


	//-------------------------------------------- Constructeurs - destructeur
	MapCreator(std::map<std::string, const xml::Node*> * theMap);
	// Mode d'emploi :
	//	TODO
	// Contrat :
	//	TODO

	virtual ~MapCreator();
	// Mode d'emploi :
	//	TODO
	// Contrat :
	//	TODO

protected:

	static const std::string TEMPLATE;

	std::map<std::string, const xml::Node*> * mapTemp;

	virtual void visit(const xml::TextNode& node);
	virtual void visit(const xml::MarkupNode& node);
	virtual void visit(const xml::CompositeMarkupNode& node);

	void checkTemplate(const xml::CompositeMarkupNode& node);
};

} // namespace xsl

#endif // MAPCREATOR_HH_
