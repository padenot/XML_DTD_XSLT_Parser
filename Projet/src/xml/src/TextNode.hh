/*************************************************************************
 * TextNode  -  «Description»
 * -------------------
 * Début      : lun. 04 avril 2011 08:51:06 CEST
 * Auteur(s)  : H4215
 *************************************************************************/

//---- Interface de la classe <TextNode> (fichier TextNode.hh) ----
#ifndef TEXTNODE_HH
#define TEXTNODE_HH

//--------------------------------------------------- Interfaces utilisées
#include <string>
#include "Node.hh"

//------------------------------------------------------------------------
// Rôle de la classe <TextNode>
//	«Rôle»
//
//------------------------------------------------------------------------

namespace xml
{

class TextNode: public Node
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

	virtual void accept (InterfaceNodeVisitor& visitor) const;
	// Mode d'emploi :
	//	Permet à un visiteur d'inspecter ce noeud sous sa vraie identité
	//	(en lui révélant son type réel).
	// Contrat :
	//	Aucun.

	std::string content() const;
	// Mode d'emploi :
	//	Renvoie le contenu du noeud.
	// Contrat :
	//	Aucun.

	//------------------------------------------------- Surcharge d'opérateurs

	//-------------------------------------------- Constructeurs - destructeur
	TextNode(CompositeMarkupNode *& parent, const std::string & content);
	// Mode d'emploi (constructeur) :
	//	«TODO»
	// Contrat :
	//	«TODO»

	virtual ~TextNode();
	// Mode d'emploi (destructeur) :
	//	«TODO»
	// Contrat :
	//	«TODO»

protected:
	std::string _content;

};

} // namespace xml

#endif // TEXTNODE_HH
