/*************************************************************************
 * NonEmptyContent  -  «Description»
 * -------------------
 * Début      : 5 avr. 2011
 * Auteur(s)  : H4215
 *************************************************************************/

//---------- Interface de la classe <NonEmptyContent> (fichier NonEmptyContent.hh) ------
#if ! defined ( NONEMPTYCONTENT_HH_ )
#define NONEMPTYCONTENT_HH_

//--------------------------------------------------- Interfaces utilisées
#include "Content.hh"

namespace dtd
{

class NonEmptyContent: public Content
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


	//------------------------------------------------- Surcharge d'opérateurs


	//-------------------------------------------- Constructeurs - destructeur
	NonEmptyContent();
	// Mode d'emploi :
	//	TODO
	// Contrat :
	//	TODO

	virtual ~NonEmptyContent();
	// Mode d'emploi :
	//	TODO
	// Contrat :
	//	TODO

protected:

};

} // namespace dtd

#endif // NONEMPTYCONTENT_HH_
