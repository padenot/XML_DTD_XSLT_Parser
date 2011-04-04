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

class MarkupNode : public Node
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
	MarkupNode & operator = ( const MarkupNode & unMarkupNode );
	// Mode d'emploi :
	//	«TODO»
	// Contrat :
	//	«TODO»


//-------------------------------------------- Constructeurs - destructeur
	MarkupNode ( const MarkupNode & unMarkupNode );
	// Mode d'emploi (constructeur de copie) :
	//	«Mode emploi»
	// Contrat :
	//	«TODO»

	MarkupNode ( Node * parent, std::string ns, std::string name );
	// Mode d'emploi (constructeur) :
	//	«TODO»
	// Contrat :
	//	«TODO»

	virtual ~MarkupNode ( );
	// Mode d'emploi (destructeur) :
	//	«TODO»
	// Contrat :
	//	«TODO»

protected:
	typedef std::map<std::string,std::string> Attributs;

	std::string _name;
	std::string _namespace;
	Attributs _attributs;

};

} // namespace xml

#endif // MARKUPNODE_HH

