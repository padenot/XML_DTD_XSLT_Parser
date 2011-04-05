/*************************************************************************
 * CompositeMarkupNode  -  «Description»
 * -------------------
 * Début      : lun. 04 avril 2011 08:54:19 CEST
 * Auteur(s)  : H4215
 *************************************************************************/

//---- Interface de la classe <CompositeMarkupNode> (fichier CompositeMarkupNode.hh) ----
#ifndef COMPOSITEMARKUPNODE_HH
#define COMPOSITEMARKUPNODE_HH

//--------------------------------------------------- Interfaces utilisées
#include <list>
#include "MarkupNode.hh"

//------------------------------------------------------------------------
// Rôle de la classe <CompositeMarkupNode>
//	«Rôle»
//
//------------------------------------------------------------------------

namespace xml
{

class CompositeMarkupNode: public MarkupNode
{
protected:
	typedef std::list<Node*> _Children;
public:
	//------------------------------------------------------------- Constantes

	//------------------------------------------------------------------ Types
	typedef std::list<Node*> Children;
	typedef _Children::const_iterator ChildrenIterator;

	//----------------------------------------------------- Méthodes publiques
	// type Méthode ( liste de paramètres );
	// Mode d'emploi :
	//	«TODO»
	// Contrat :
	//	«TODO»

	virtual void accept (InterfaceNodeVisitor& visitor) const;
	// Mode d'emploi :
	//	Permet à un visiteur d'inspecter ce noeud sous sa vraie identité
	//	(en lui révélant son type réel).
	// Contrat :
	//	Aucun.

	ChildrenIterator begin() const;
	// Mode d'emploi :
	//	Renvoie un itérateur vers le premier enfant du noeud.
	//	La méthode est compatible avec la STL.
	//	L'itérateur pointe vers un pointeur (l'accès aux méthodes des fils
	//	se fait donc de la façon suivante : (*it)->foo()).
	// Contrat :
	//	L'itérateur n'est plus valable en cas de modification du noeud, de
	//	même que les itérateurs obtenus par son intermédiaire.

	ChildrenIterator end() const;
	// Mode d'emploi :
	//	Renvoie un itérateur pointant juste après le dernier enfant du noeud.
	//	La méthode est compatible avec la STL.
	//	L'itérateur pointe vers un pointeur (l'accès aux méthodes des fils
	//	se fait donc de la façon suivante : (*it)->foo()).
	// Contrat :
	//	L'itérateur n'est plus valable en cas de modification du noeud, de
	//	même que les itérateurs obtenus par son intermédiaire.


	//------------------------------------------------- Surcharge d'opérateurs


	//-------------------------------------------- Constructeurs - destructeur
	CompositeMarkupNode(CompositeMarkupNode *& parent, const std::string & ns,
			const std::string & name, const Attributes & attributes,
			CompositeMarkupNode *& selfPointer, const Children & children);
	// Mode d'emploi (constructeur) :
	//	«TODO»
	// Contrat :
	//	«TODO»

	virtual ~CompositeMarkupNode();
	// Mode d'emploi (destructeur) :
	//	«TODO»
	// Contrat :
	//	«TODO»

protected:
	_Children _children;

	CompositeMarkupNode*& _selfPointer;
};

} // namespace xml

#endif // COMPOSITEMARKUPNODE_HH
