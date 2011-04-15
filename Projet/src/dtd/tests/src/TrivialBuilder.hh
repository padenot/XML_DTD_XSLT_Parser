/*************************************************************************
 * TrivialBuilder  -  «Description»
 * -------------------
 * Début      : 15 avr. 2011
 * Auteur(s)  : H4215
 *************************************************************************/

//---------- Interface de la classe <TrivialBuilder> (fichier TrivialBuilder.hh) ------
#if ! defined ( TRIVIALBUILDER_HH_ )
#define TRIVIALBUILDER_HH_

//--------------------------------------------------- Interfaces utilisées
#include "Builder.hh"

class TrivialBuilder : public Builder
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
	TrivialBuilder();
	virtual ~TrivialBuilder();

protected:

};

#endif // TRIVIALBUILDER_HH_
