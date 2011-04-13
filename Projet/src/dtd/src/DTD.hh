/*************************************************************************
 * DTD  -  «Description»
 * -------------------
 * Début      : 5 avr. 2011
 * Auteur(s)  : H4215
 *************************************************************************/

//---------- Interface de la classe <DTD> (fichier DTD.hh) ------
#if ! defined ( DTD_HH_ )
#define DTD_HH_

//--------------------------------------------------- Interfaces utilisées
#include <string>
#include <map>
#include "Node.hh"
#include "AttributesList.hh"

namespace dtd
{
class InterfaceDTDVisitor;
class Content;

class DTD
{
public:
	//------------------------------------------------------------- Constantes

	//------------------------------------------------------------------ Types

	//----------------------------------------------------- Méthodes publiques
	// type Méthode ( liste des paramètres );
	// Mode d'emploi :
	//	
	// Contrat :
	//	

	void addElement(const std::string & ns, const std::string & elementName,
			Content& content);
	// Mode d'emploi :
	//	Ajoute un element à la DTD. Si aucun AttributesList n'existe pour
	//	cet élément, il sera créé (vide).
	//	L'élément sera détruit par la DTD.
	// Contrat :
	//	Aucun.

	void addAttributesList(const std::string & ns,
			const std::string & elementName, const AttributesList& attribute);
	// Mode d'emploi :
	//	Ajoute une liste d'attributs à la DTD. Si une liste d'attributs
	//	existe déjà portant sur le même élément, elle seront fusionnées.
	//	La liste et ses éléments seront détruite par la DTD.
	// Contrat :
	//	Aucun.

	const Content * getContent(std::string ns, std::string name) const;
	// Mode d'emploi :
	//	Récupère l'élement associé à l'espace de nom "ns" et au nom "name".
	//	S'il n'existe pas, renvoie un pointeur nul.
	// Contrat :
	//	Aucun.

	const AttributesList
			* getAttributesList(std::string ns, std::string name) const;
	// Mode d'emploi :
	//	Récupère la liste d'attributs associée à l'espace de nom "ns" et au
	//	nom "name".
	//	Si elle n'existe pas, renvoie un pointeur nul.
	// Contrat :
	//	Aucun.

	bool isValid(const xml::Node& root);
	// Mode d'emploi :
	//	Valide un document XML selon la DTD.
	// Contrat :
	//	Aucun.


	//------------------------------------------------- Surcharge d'opérateurs


	//-------------------------------------------- Constructeurs - destructeur
	DTD();
	// Mode d'emploi :
	//	TODO
	// Contrat :
	//	TODO

	virtual ~DTD();
	// Mode d'emploi :
	//	TODO
	// Contrat :
	//	TODO

protected:
	typedef std::pair<std::string, std::string> _ElementId;
	typedef std::map<_ElementId, Content*> _Elements;
	typedef std::map<_ElementId, AttributesList*> _AttributesLists;

	_Elements _elements;
	_AttributesLists _attributesLists;

};

} // namespace dtd

#endif // DTD_HH_
