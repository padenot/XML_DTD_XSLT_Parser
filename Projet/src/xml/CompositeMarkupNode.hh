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
public:
	//------------------------------------------------------------- Constantes

	//------------------------------------------------------------------ Types
	typedef std::list<Node*> Children;

	//----------------------------------------------------- Méthodes publiques
	// type Méthode ( liste de paramètres );
	// Mode d'emploi :
	//	«TODO»
	// Contrat :
	//	«TODO»

	virtual std::ostream
	& Write(std::ostream& out, unsigned char indent) const;

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
	typedef std::list<Node*> _Children;
	_Children _children;

	CompositeMarkupNode*& _selfPointer;
};

} // namespace xml

#endif // COMPOSITEMARKUPNODE_HH
