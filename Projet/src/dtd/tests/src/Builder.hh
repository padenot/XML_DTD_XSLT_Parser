/*************************************************************************
 * Builder  -  «Description»
 * -------------------
 * Début      : 15 avr. 2011
 * Auteur(s)  : H4215
 *************************************************************************/

//---------- Interface de la classe <Builder> (fichier Builder.hh) ------
#if ! defined ( BUILDER_HH_ )
#define BUILDER_HH_

//--------------------------------------------------- Interfaces utilisées
#include <string>
#include <list>
#include "Node.hh"
#include "DTD.hh"

class Builder
{
public:
	//------------------------------------------------------------- Constantes

	//------------------------------------------------------------------ Types

	//----------------------------------------------------- Méthodes publiques
	virtual void buildDTD(dtd::DTD& dtd) const = 0;
	virtual std::list<xml::Node*> buildValidTrees() const = 0;
	virtual std::list<xml::Node*> buildInvalidTrees() const = 0;
	static void releaseTrees(std::list<xml::Node*> trees);

	//------------------------------------------------- Surcharge d'opérateurs


	//-------------------------------------------- Constructeurs - destructeur
	Builder();
	virtual ~Builder();

protected:
	static std::string ns(unsigned int offset = 0);
	static std::string name(unsigned int offset = 0);
	static std::string attname(unsigned int offset = 0);
	static std::string attval(unsigned int offset = 0);
	static std::string text(unsigned int offset = 0);
};

#endif // BUILDER_HH_
