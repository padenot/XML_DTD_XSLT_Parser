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
public:
	//------------------------------------------------------------- Constantes

	//------------------------------------------------------------------ Types
	typedef std::map<std::string, std::string> Attributes;

	//----------------------------------------------------- Méthodes publiques
	// type Méthode ( liste de paramètres );
	// Mode d'emploi :
	//	«TODO»
	// Contrat :
	//	«TODO»

	virtual std::ostream
	& Write(std::ostream& out, unsigned char indent) const;

	//------------------------------------------------- Surcharge d'opérateurs
	MarkupNode & operator =(const MarkupNode & unMarkupNode);
	// Mode d'emploi :
	//	«TODO»
	// Contrat :
	//	«TODO»


	//-------------------------------------------- Constructeurs - destructeur
	MarkupNode(const MarkupNode & unMarkupNode);
	// Mode d'emploi (constructeur de copie) :
	//	«Mode emploi»
	// Contrat :
	//	«TODO»

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
	typedef std::map<std::string, std::string> _Attributes;

	static const char OPEN_MARKUP_CHAR;
	static const char NS_SEPARATOR_CHAR;
	static const char INSIDE_MARKUP_SPACE_CHAR;
	static const char CLOSING_MARKUP_CHAR;
	static const char CLOSE_MARKUP_CHAR;
	static const char ASSIGN_ATTRIBUTE_VALUE_CHAR;
	static const char OPEN_ATTRIBUTE_VALUE_CHAR;
	static const char CLOSE_ATTRIBUTE_VALUE_CHAR;

	std::string _namespace;
	std::string _name;
	_Attributes _attributes;

	std::ostream& writeAttributes(std::ostream& out) const;
};

} // namespace xml

#endif // MARKUPNODE_HH
