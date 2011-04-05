/*************************************************************************
 * InterfaceNodeVisitor  -  Interface pour les classes destinée à inspecter
 * un arbre DOM (donc ses noeuds)
 * -------------------
 * Début      : lun. 04 avril 2011 08:46:08 CEST
 * Auteur(s)  : H4215
 *************************************************************************/

#ifndef INTERFACENODEVISITOR_HPP
#define INTERFACENODEVISITOR_HPP

namespace xml
{
class Node;
class TextNode;
class MarkupNode;
class CompositeMarkupNode;

class InterfaceNodeVisitor
{
public:
	virtual ~InterfaceNodeVisitor()
	// Mode d'emploi (constructeur) :
	//	Ne fait rien (interface).
	// Contrat :
	//	Aucun.
	{
		// Vide
	}

protected :
	friend class Node;
	virtual void visit(const TextNode& node) = 0;
	virtual void visit(const MarkupNode& node) = 0;
	virtual void visit(const CompositeMarkupNode& node) = 0;
	// Mode d'emploi :
	//	Visite le noeud donné en paramètre, pour inspection.
	// Contrat :
	//	Le noeud visité doit appeler cette méthode avec son type réel
	//	(non hérité) lorsqu'on fait appel à sa méthode accept().
};

} // namespace xml

#endif // INTERFACENODEVISITOR_HPP
