/*************************************************************************
 * CompositeMarkupNode  -  «Description»
 * -------------------
 * Début      : lun. 04 avril 2011 09:05:13 CEST
 * Auteur(s)  : H4215
 *************************************************************************/

//---- Réalisation de la classe <CompositeMarkupNode> (fichier CompositeMarkupNode.cpp) ----

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <string>

//------------------------------------------------------ Include personnel
#include "CompositeMarkupNode.hh"

namespace xml
{
//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques
// type CompositeMarkupNode::Méthode ( liste de paramètres )
// Algorithme :
//	«TODO»
//{
//} //----- Fin de Méthode

void CompositeMarkupNode::accept (InterfaceNodeVisitor& visitor) const
{
	visitor.visit(*this);
}

CompositeMarkupNode::ChildrenIterator CompositeMarkupNode::begin() const
{
	return _children.begin();
}

CompositeMarkupNode::ChildrenIterator CompositeMarkupNode::end() const
{
	return _children.end();
}

//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
CompositeMarkupNode::CompositeMarkupNode(CompositeMarkupNode *& parent,
		const std::string & ns, const std::string & name,
		const Attributes & attributes, CompositeMarkupNode*& selfPointer,
		const Children & children) :
	MarkupNode(parent, ns, name, attributes), _children(children),
			_selfPointer(selfPointer)
{
	// Affectation du pointeur utilisé comme référence par les enfants
	_selfPointer = this;
} //----- Fin de CompositeMarkupNode

CompositeMarkupNode::~CompositeMarkupNode()
{
	for (_Children::const_iterator it = _children.begin(); it
			!= _children.end(); ++it)
	{
		delete *it;
	}

	// Destruction du pointeur utilisé comme référence par les enfants
	delete &_selfPointer;
} //----- Fin de ~CompositeMarkupNode


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées

} // namespace xml
