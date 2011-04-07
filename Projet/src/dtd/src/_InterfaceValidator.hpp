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
class _InterfaceValidator
{
public:
	//------------------------------------------------------------- Constantes

	//------------------------------------------------------------------ Types

	//----------------------------------------------------- Méthodes publiques
	virtual bool _newValidation(
			xml::CompositeMarkupNode::ChildrenIterator firstToken,
			xml::CompositeMarkupNode::ChildrenIterator endToken,
			_InterfaceValidator* nextStep) = 0;
	// Mode d'emploi :
	//	Initialise et exécute une nouvelle validation pour la plage de jetons
	//	donnée en paramètres, en exécutant ensuite une validation avec
	//	"nextStep" sur les jetons restants (même s'il n'y en a plus).
	// Contrat :
	//	Aucun.

	virtual bool _continueValidation(
			xml::CompositeMarkupNode::ChildrenIterator currentToken) = 0;
	// Mode d'emploi :
	//	Continue la validation déjà commencée sans réinitialiser le validateur,
	//	en continuant au jeton donné en paramètre.
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
