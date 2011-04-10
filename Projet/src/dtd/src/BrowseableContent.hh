/*************************************************************************
 * BrowseableContent  -  «Description»
 * -------------------
 * Début      : 5 avr. 2011
 * Auteur(s)  : H4215
 *************************************************************************/

//---------- Interface de la classe <BrowseableContent> (fichier BrowseableContent.hh) ------
#if ! defined ( BROWSEABLECONTENT_HH )
#define BROWSEABLECONTENT_HH

//--------------------------------------------------- Interfaces utilisées
#include "Content.hh"

namespace dtd
{

class BrowseableContent: public Content
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

	virtual bool validate(const xml::MarkupNode & node);
	virtual bool validate(const xml::CompositeMarkupNode & node);

	//------------------------------------------------- Surcharge d'opérateurs


	//-------------------------------------------- Constructeurs - destructeur
	BrowseableContent();
	// Mode d'emploi :
	//	TODO
	// Contrat :
	//	TODO

	virtual ~BrowseableContent();
	// Mode d'emploi :
	//	TODO
	// Contrat :
	//	TODO

protected:
	bool _newValidation(xml::CompositeMarkupNode::ChildrenIterator firstToken,
			xml::CompositeMarkupNode::ChildrenIterator endToken,
			BrowseableContent* nextStep);
	// Mode d'emploi :
	//	Initialise et exécute une nouvelle validation pour la plage de jetons
	//	donnée en paramètres, en exécutant ensuite une validation avec
	//	"nextStep" sur les jetons restants (même s'il n'y en a plus).
	//	Méthode destinée à être appelée par un "Content" composite sur ses
	//	noeuds fils (étape de descente lors du parcours de l'arbre).
	//	Cette méthode est accessible à d'autres instances via la classe
	//	_ValidatorAccessor (cf. ci-dessous).
	// Contrat :
	//	TODO

	virtual bool _startValidation(
			xml::CompositeMarkupNode::ChildrenIterator firstToken,
			xml::CompositeMarkupNode::ChildrenIterator endToken,
			BrowseableContent* nextStep) = 0;
	// Mode d'emploi :
	//	Exécute une nouvelle validation, juste après l'initialisation
	//	du validateur.
	// Contrat :
	//	TODO

	virtual bool _continueValidation(
			xml::CompositeMarkupNode::ChildrenIterator currentToken);
	// Mode d'emploi :
	//	Continue la validation déjà commencée sans réinitialiser le validateur,
	//	en continuant au jeton donné en paramètre.
	//	Méthode de callback destinée à être appelée par les fils d'un "Content"
	//	composite après exécution (réussie) de leur propre validation (étape
	//	de remontée lors du parcours de l'arbre). Par défaut, ne fait rien
	//	et renvoie "false" (implémentation pour des "Content" non composites).
	//	Cette méthode est accessible à d'autres instances via la classe
	//	_ValidatorAccessor (cf. ci-dessous).
	// Contrat :
	//	TODO

	virtual void _beforeValidation(
			xml::CompositeMarkupNode::ChildrenIterator firstToken,
			xml::CompositeMarkupNode::ChildrenIterator endToken,
			BrowseableContent* nextStep);
	// Mode d'emploi :
	//	Patron de méthode appelé par "_newValidation" avant l'appel
	//	initial à "_startValidation".
	//	Par défaut, ne fait rien.
	//	Peut être surchargé par les classes filles afin d'effectuer
	//	diverses opérations avant de commencer la validation.
	// Contrat :
	//	Aucun.

	virtual void _afterValidation();
	// Mode d'emploi :
	//	Patron de méthode appelé par "_newValidation" après l'appel
	//	à "_startValidation" (que la validation ait été un succès ou non).
	//	Par défaut, ne fait rien.
	//	Peut être surchargé par les classes filles afin d'effectuer
	//	diverses opérations après avoir effectué une validation
	//	(réussie ou non).
	// Contrat :
	//	Aucun.


	bool _browseDown(BrowseableContent & childContent,
			xml::CompositeMarkupNode::ChildrenIterator firstToken,
			xml::CompositeMarkupNode::ChildrenIterator endToken,
			BrowseableContent* nextStep);
	// Mode d'emploi :
	//	Continue la validation en descendant dans l'arbre des contenus.
	//	En pratique, appelle "childContent._newValidation(firstToken,endToken,nextStep)"
	//	et renvoie le résultat.
	//	Astuce très laide nécessaire pour donner aux instances des
	//	classes filles le droit d'appeler des méthodes protégées de
	//	la classes de base sur d'autres instances.
	//	L'autre solution aurait été de donner à ces méthodes une
	//	visibilité publique, ce qui n'est pas voulu.
	// Contrat :
	//	Ceux s'appliquant à BrowseableContent::_newValidation.

	bool _browseUp(BrowseableContent & parentContent,
			xml::CompositeMarkupNode::ChildrenIterator currentToken);
	// Mode d'emploi :
	//	Continue la validation en remontant dans l'arbre des contenus.
	//	En pratique, appelle "parentContent._continueValidation(currentToken)"
	//	et renvoie le résultat.
	//	Astuce très laide nécessaire pour donner aux instances des
	//	classes filles le droit d'appeler des méthodes protégées de
	//	la classes de base sur d'autres instances.
	//	L'autre solution aurait été de donner à ces méthodes une
	//	visibilité publique, ce qui n'est pas voulu.
	// Contrat :
	//	Ceux s'appliquant à BrowseableContent::_continueValidation.

};

} // namespace dtd

#endif // BROWSEABLECONTENT_HH
