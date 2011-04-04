/*************************************************************************
 * Node  -  «Description»
 * -------------------
 * Début      : lun. 04 avril 2011 08:46:08 CEST
 * Auteur(s)  : H4215
 *************************************************************************/

//---- Interface de la classe <Node> (fichier Node.hh) ----
#ifndef NODE_HH
#define NODE_HH

//--------------------------------------------------- Interfaces utilisées
#include <iosfwd>
namespace xml
{
class CompositeMarkupNode;

//------------------------------------------------------------------------
// Rôle de la classe <Node>
//	«Rôle»
//
//------------------------------------------------------------------------


class Node
{
public:
	//------------------------------------------------------------- Constantes

	//------------------------------------------------------------------ Types

	//----------------------------------------------------- Méthodes publiques
	// type Méthode ( liste de paramètres );
	// Mode d'emploi :
	//	«TODO»
	// Contrat :
	//	«TODO»


	virtual std::ostream
			& Write(std::ostream& out, unsigned char indent = 0) const = 0;
	// Mode d'emploi :
	//	Écrit le noeud sur le flot "out", en indentant la ligne "indent" fois.
	//	La nature des caractères écrits sur le flot dépend du type du noeud.
	// Contrat :
	//	En cas de surcharge, les noeuds inclus doivent être indentés par
	//	rapport à celui-ci ("indent" doit être incrémenté).

	//------------------------------------------------- Surcharge d'opérateurs
	friend std::ostream & operator <<(std::ostream& out, const Node & aNode);
	// Mode d'emploi :
	//	Appelle aNode.Write(out).
	// Contrat :
	//	Aucun.

	//-------------------------------------------- Constructeurs - destructeur
	Node(CompositeMarkupNode *& parent);
	// Mode d'emploi (constructeur) :
	//	«TODO»
	// Contrat :
	//	La valeur de "parent" ne doit plus changer après la construction de
	//		l'arbre.
	//	Si le noeud construit représente la racine, "parent" doit être nul.
	//	La destruction du pointeur "parent" (et non de l'objet "*parent") est
	//		à la charge de l'objet construit (le noeud).

	virtual ~Node();
	// Mode d'emploi (destructeur) :
	//	«TODO»
	// Contrat :
	//	«TODO»

protected:
	static const char INDENT_CHAR;
	static const unsigned char INDENT_UNIT;

	CompositeMarkupNode *& _parent;

	static std::ostream
	& doIndent(std::ostream& out, unsigned char indent);
};

} // namespace xml

#endif // NODE_HH
