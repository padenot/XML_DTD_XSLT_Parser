/*************************************************************************
 * _InterfaceValidator  -  «Description»
 * -------------------
 * Début      : 7 avr. 2011
 * Auteur(s)  : H4215
 *************************************************************************/

//---------- Interface de la classe <_InterfaceValidator> (fichier _InterfaceValidator.hpp) ------
#if ! defined ( _INTERFACEVALIDATOR_HPP_ )
#define _INTERFACEVALIDATOR_HPP_

//--------------------------------------------------- Interfaces utilisées
#include <string>

namespace dtd
{
class NonEmptyContent;

class _InterfaceValidator
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

	virtual bool _newValidation(
			xml::CompositeMarkupNode::ChildrenIterator firstToken,
			xml::CompositeMarkupNode::ChildrenIterator endToken,
			NonEmptyContent* nextStep) = 0;
	// Mode d'emploi :
	//	TODO.
	// Contrat :
	//	Aucun.

	virtual bool _continueValidation(
			xml::CompositeMarkupNode::ChildrenIterator currentToken) = 0;
	// Mode d'emploi :
	//	TODO.
	// Contrat :
	//	Aucun.


	//------------------------------------------------- Surcharge d'opérateurs


	//-------------------------------------------- Constructeurs - destructeur
	virtual ~_InterfaceValidator()
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

#endif // _INTERFACEVALIDATOR_HPP_
