/*************************************************************************
 * DTD  -  «Description»
 * -------------------
 * Début      : 5 avr. 2011
 * Auteur(s)  : H4215
 *************************************************************************/

//---------- Réalisation de la classe <DTD> (fichier DTD.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;

//------------------------------------------------------ Include personnel
#include "DTD.hh"
#include "Element.hh"
#include "AttributesList.hh"

namespace dtd
{
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type DTD::Méthode ( liste des paramètres )
// Algorithme :
//	
//{
//}

void DTD::accept(InterfaceDTDVisitor& visitor) const
{
	for (_Elements::const_iterator it = _elements.begin(); it != _elements.end(); ++it)
	{
		(*it)->accept(visitor);
	}
	for (_AttributesLists::const_iterator it = _attributesLists.begin(); it
			!= _attributesLists.end(); ++it)
	{
		(*it)->accept(visitor);
	}
}

void DTD::addElement(Element & element)
{
	_elements.push_back(&element);
}

void DTD::addAttributesList(AttributesList & attlist)
{
	_attributesLists.push_back(&attlist);
}

const Element * DTD::getElement(std::string ns, std::string name)
{
	return 0; // TODO
}

const AttributesList * DTD::getAttributesList(std::string ns, std::string name)
{
	return 0; // TODO
}

bool DTD::isValid(const xml::Node& root)
{
	return false; // TODO
}

//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
DTD::DTD() :
	_elements(), _attributesLists()
{
	//TODO
}

DTD::~DTD()
{
	for (_Elements::iterator it = _elements.begin(); it != _elements.end(); ++it)
	{
		delete *it;
	}
	for (_AttributesLists::iterator it = _attributesLists.begin(); it
			!= _attributesLists.end(); ++it)
	{
		delete *it;
	}
}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

} // namespace dtd
