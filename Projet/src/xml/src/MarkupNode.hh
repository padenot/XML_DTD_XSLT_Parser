/*************************************************************************
 * MarkupNode  -  «Description»
 * -------------------
 * Début      : lun. 04 avril 2011 08:48:07 CEST
 * Auteur(s)  : H4215
 *************************************************************************/

//---- Interface de la classe <MarkupNode> (fichier MarkupNode.hh) ----
#ifndef MARKUPNODE_HH
#define MARKUPNODE_HH

//--------------------------------------------------- Interfaces utilisées
#include <string>
#include <map>
#include "Node.hh"

//------------------------------------------------------------------------
// Rôle de la classe <MarkupNode>
//	«Rôle»
//
//------------------------------------------------------------------------

namespace xml
{

class MarkupNode: public Node
{
protected:
	typedef std::map<std::string, std::string> _Attributes;

public:
	//------------------------------------------------------------- Constantes

	//------------------------------------------------------------------ Types
	typedef std::map<std::string, std::string> Attributes;
	typedef _Attributes::const_iterator AttributesIterator;

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

	std::string ns() const;
	// Mode d'emploi :
	//	Renvoie le namespace associé au noeud.
	//	Renvoie une chaîne vide par défaut.
	// Contrat :
	//	Aucun.

	std::string name() const;
	// Mode d'emploi :
	//	Renvoie le nom du noeud.
	//	Renvoie une chaîne vide par défaut.
	// Contrat :
	//	Aucun.

	AttributesIterator begin() const;
	// Mode d'emploi :
	//	Renvoie un itérateur vers le premier enfant du noeud.
	//	La méthode est compatible avec la STL.
	//	L'itérateur pointe vers un pointeur (l'accès aux méthodes des fils
	//	se fait donc de la façon suivante : (*it)->foo()).
	// Contrat :
	//	L'itérateur n'est plus valable en cas de modification du noeud, de
	//	même que les itérateurs obtenus par son intermédiaire.

	AttributesIterator end() const;
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
	MarkupNode(CompositeMarkupNode *& parent, const std::string & ns,
			const std::string & name, const Attributes & attributes);
	// Mode d'emploi (constructeur) :
	//	«TODO»
	// Contrat :
	//	«TODO»

	virtual ~MarkupNode();
	// Mode d'emploi (destructeur) :
	//	«TODO»
	// Contrat :
	//	«TODO»

protected:

	std::string _namespace;
	std::string _name;
	_Attributes _attributes;

};

} // namespace xml

#endif // MARKUPNODE_HH
