/*************************************************************************
 * ElementContent  -  «Description»
 * -------------------
 * Début      : 5 avr. 2011
 * Auteur(s)  : H4215
 *************************************************************************/

//---------- Interface de la classe <ElementContent> (fichier ElementContent.hh) ------
#if ! defined ( ELEMENTCONTENT_HH_ )
#define ELEMENTCONTENT_HH_

//--------------------------------------------------- Interfaces utilisées
#include "QuantifiableContent.hh"

namespace dtd
{

class ElementContent: public QuantifiableContent
{
public:
	//------------------------------------------------------------- Constantes

	//------------------------------------------------------------------ Types

	//----------------------------------------------------- Méthodes publiques


	//------------------------------------------------- Surcharge d'opérateurs


	//-------------------------------------------- Constructeurs - destructeur
	ElementContent();

	virtual ~ElementContent();

	//------------------------------------------------------------------ PRIVE

protected:

};

} // namespace dtd

#endif // ELEMENTCONTENT_HH_
