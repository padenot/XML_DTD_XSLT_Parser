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
#include "InterfaceNodeVisitor.hpp"

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
	virtual void accept (InterfaceNodeVisitor& visitor) const = 0;
	// Mode d'emploi :
	//	Permet à un visiteur d'inspecter ce noeud sous sa vraie identité
	//	(en lui révélant son type réel).
	// Contrat :
	//	Aucun.

	Node* parent ( ) const;
	// Mode d'emploi :
	//	Renvoie le noeud parent, ou un pointeur nul s'il n'y en a pas.
	// Contrat :
	//	Aucun.


	//------------------------------------------------- Surcharge d'opérateurs


	//-------------------------------------------- Constructeurs - destructeur
	Node(CompositeMarkupNode ** parent);
	// Mode d'emploi (constructeur) :
	//	«TODO»
	// Contrat :
	//	La valeur de "*parent" ne doit plus changer après la construction de
	//		l'arbre.
	//	Si le noeud construit représente la racine, "parent" doit être nul.
	//	Si "parent" est non nul, "*parent" doit être non nul.
	//	La destruction du pointeur "*parent" (et non de l'objet "**parent") est
	//		à la charge de l'objet qui sera ultimement référencé par "*parent".

	virtual ~Node();

protected:

	CompositeMarkupNode ** _parent;
};

} // namespace xml

#endif // NODE_HH
