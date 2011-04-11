/*************************************************************************
 * Element  -  «Description»
 * -------------------
 * Début      : 5 avr. 2011
 * Auteur(s)  : H4215
 *************************************************************************/

//---------- Réalisation de la classe <Element> (fichier Element.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;

//------------------------------------------------------ Include personnel
#include "Element.hh"
#include "DTD.hh"
#include "InterfaceDTDVisitor.hpp"
#include "Node.hh"
#include "BadReferenceException.hpp"

namespace dtd
{
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Element::Méthode ( liste des paramètres )
// Algorithme :
//	
//{
//}

bool Element::matches(xml::Node& node)
{
	return false; //TODO
}

string Element::ns() const
{
	return _namespace;
}

string Element::name() const
{
	return _name;
}

const AttributesList& Element::attributesList() const
		throw (BadReferenceException)
{
	const AttributesList* attlist = _dtd.getAttributesList(_namespace, _name);
	if (attlist == 0)
	{
		throw BadReferenceException();
	}
	else
	{
		return *attlist;
	}
}

const Content& Element::content() const
{
	return _content;
}

void Element::accept(InterfaceDTDVisitor& visitor) const
{
	visitor.visit(*this);
}

bool Element::isValid(xml::Node& node) const
{
	return false; //TODO
}

//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
Element::Element(DTD& dtd, const string & ns, const string & name,
		Content & content) :
	_dtd(dtd), _namespace(ns), _name(name), _content(content)
{
	//TODO
}

Element::~Element()
{
	//TODO
}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

} // namespace dtd
