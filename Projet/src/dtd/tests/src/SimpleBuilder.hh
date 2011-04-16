/*************************************************************************
 * SimpleBuilder  -  «Description»
 * -------------------
 * Début      : 15 avr. 2011
 * Auteur(s)  : H4215
 *************************************************************************/

//---------- Interface de la classe <SimpleBuilder> (fichier SimpleBuilder.hh) ------
#if ! defined ( SIMPLEBUILDER_HH_ )
#define SIMPLEBUILDER_HH_

//--------------------------------------------------- Interfaces utilisées
#include "Builder.hh"
#include "CompositeMarkupNode.hh"

class SimpleBuilder: public Builder
{
public:
	//------------------------------------------------------------- Constantes

	//------------------------------------------------------------------ Types

	//----------------------------------------------------- Méthodes publiques
	void buildDTD(dtd::DTD& dtd) const;
	std::list<xml::Node*> buildValidTrees() const;
	std::list<xml::Node*> buildInvalidTrees() const;

	//------------------------------------------------- Surcharge d'opérateurs


	//-------------------------------------------- Constructeurs - destructeur
	SimpleBuilder();
	virtual ~SimpleBuilder();

protected:
	xml::Node * buildTree(xml::CompositeMarkupNode::Children markup1Chosen,
			xml::CompositeMarkupNode*& markup1Proxy, bool withMarkup7,
			bool withMarkup1 = true, bool withMarkup4 = true,
			bool withMarkup2 = true, bool withMarkup3 = true) const;
	// Default values with no "chosen" will build a valid tree

};

#endif // SIMPLEBUILDER_HH_
