/*************************************************************************
 * MapCreator  -  «Description»
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

using namespace xml;
using namespace std;

namespace xsl
{

class MapCreator: public InterfaceNodeVisitor
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
	void populateMap(const Node& xslTree);

	//------------------------------------------------- Surcharge d'opérateurs


	//-------------------------------------------- Constructeurs - destructeur
	MapCreator(map<string, const Node*> * theMap);
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

	static const string TEMPLATE;

	map<string, const Node*> * mapTemp;

	virtual void visit(const TextNode& node);
	virtual void visit(const MarkupNode& node);
	virtual void visit(const CompositeMarkupNode& node);

	void checkTemplate(const CompositeMarkupNode& node);
};

} // namespace xsl

#endif // MAPCREATOR_HH_
