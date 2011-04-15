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
	//	ATTENTION : cette méthode occulte MarkupNode::begin, qui a une
	//	sémantique différente. Pour y accéder, utiliser node.MarkupNode::begin.
	// Contrat :
	//	L'itérateur n'est plus valable en cas de modification du noeud, de
	//	même que les itérateurs obtenus par son intermédiaire.

	ChildrenIterator end() const;
	// Mode d'emploi :
	//	Renvoie un itérateur pointant juste après le dernier enfant du noeud.
	//	La méthode est compatible avec la STL.
	//	L'itérateur pointe vers un pointeur (l'accès aux méthodes des fils
	//	se fait donc de la façon suivante : (*it)->foo()).
	//	ATTENTION : cette méthode occulte MarkupNode::end, qui a une
	//	sémantique différente. Pour y accéder, utiliser node.MarkupNode::end.
	// Contrat :
	//	L'itérateur n'est plus valable en cas de modification du noeud, de
	//	même que les itérateurs obtenus par son intermédiaire.


	//------------------------------------------------- Surcharge d'opérateurs


	//-------------------------------------------- Constructeurs - destructeur
	CompositeMarkupNode(CompositeMarkupNode ** parent, const std::string & ns,
			const std::string & name, const Attributes & attributes,
			CompositeMarkupNode *& proxyToSelf, const Children & children);
	// Mode d'emploi (constructeur) :
	//	Crée un noeud composite.
	//	Si "parent" est nul, le noeud n'a pas de parent, sinon son parent est
	//	donné par "**parent".
	//	L'espace de nom du noeud est donné par "ns", le nom par "name", la
	//	map des attributs est "attributes" (elle est recopiée).
	//	"proxyToSelf" est une référence vers le pointeur qui a été passé
	//	en paramètre aux différents fils du noeud. Il est affecté à l'adresse du
	//	CompositeMarkupNode nouvellement créé dans le constructeur et détruit
	//	dans le destructeur.
	// Contrat :
	//	Si "parent" est non nul, "*parent" doit être non nul.
	//	Tous les élément du conteneur "Children" doivent avoir "parent"
	//	pour pointeur vers le parent.

	virtual ~CompositeMarkupNode();
	// Mode d'emploi (destructeur) :
	//	Détruit tous les enfants du noeud ainsi que le proxy ("proxyToSelf"
	//	ci-dessus).
	// Contrat :
	//	Aucun.

protected:
	_Children _children;

	CompositeMarkupNode*& _proxyToSelf;
};

} // namespace xml

#endif // COMPOSITEMARKUPNODE_HH
