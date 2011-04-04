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

class TextNode : public Node
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


//------------------------------------------------- Surcharge d'opérateurs
	TextNode & operator = ( const TextNode & unTextNode );
	// Mode d'emploi :
	//	«TODO»
	// Contrat :
	//	«TODO»


//-------------------------------------------- Constructeurs - destructeur
	TextNode ( const TextNode & unTextNode );
	// Mode d'emploi (constructeur de copie) :
	//	«Mode emploi»
	// Contrat :
	//	«TODO»

	TextNode ( );
	// Mode d'emploi (constructeur) :
	//	«TODO»
	// Contrat :
	//	«TODO»

	virtual ~TextNode ( );
	// Mode d'emploi (destructeur) :
	//	«TODO»
	// Contrat :
	//	«TODO»

protected:
	std::string _content;
};

} // namespace xml

#endif // TEXTNODE_HH

