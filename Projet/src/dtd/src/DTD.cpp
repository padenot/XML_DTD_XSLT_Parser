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
#include "Content.hh"
#include "Attribute.hh"

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

void DTD::addElement(const std::string & ns, const std::string & elementName,
		Content& content)
{
	// TODO provoquer une erreur si l'élément existe déjà,
	//	ou remplacer l'ancien
	//_elements.push_back(&element);
}

void DTD::addAttributesList(const std::string & ns,
		const std::string & elementName, const AttributesList& attribute)
{
	// TODO: essayer de fusionner avec une autre attlist
	//_attributesLists.push_back(&attlist);
}

const Content * DTD::getContent(std::string ns, std::string name) const
{
	/*_Elements::iterator it;
	 for (it = _elements.begin(); it != _elements.end(); ++it)
	 {
	 if	()
	 }*/

	return 0; // TODO
}

const AttributesList * DTD::getAttributesList(std::string ns, std::string name) const
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
		delete it->second;
	}
	for (_AttributesLists::iterator it = _attributesLists.begin(); it
			!= _attributesLists.end(); ++it)
	{
		for (AttributesList::iterator it2 = it->second->begin(); it2
				!= it->second->end(); ++it2)
		{
			delete *it2;
		}
		delete it->second;
	}
}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

} // namespace dtd
