/*************************************************************************
 * TransformerVisitor  -  Visiteur écrivant un noeud et ses descendants
 * sur un flot au format .dot
 * -------------------
 * Début      : mar. 05 avril 2011 14:35:25 CEST
 * Auteur(s)  : H4215
 *************************************************************************/

//---- Interface de la classe <TransformerVisitor> (fichier TransformerVisitor.hh) ----
#ifndef TransformerVisitor_HH
#define TransformerVisitor_HH

//--------------------------------------------------- Interfaces utilisées
#include "InterfaceNodeVisitor.hpp"
#include <map>
#include <string>

namespace xml
{
class TransformerVisitor: public InterfaceNodeVisitor
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


	//-------------------------------------------- Constructeurs - destructeur
	TransformerVisitor();
	// Mode d'emploi (constructeur) :
	//	Construit un nouveau visiteur.
	// Contrat :
	//	Aucun.


	virtual ~TransformerVisitor();
	// Mode d'emploi (destructeur) :
	//	Libère les éventuelles ressources allouées par le visiteur.
	// Contrat :
	//	Aucun.


protected:
	typedef std::map<std::string, const Node*> map;
	map * templatesMap;
	
	void creerMap(const Node& node);
	void getTemplateName(const MarkupNode& node);
	virtual void visit(const TextNode& node);
	virtual void visit(const MarkupNode& node);
	virtual void visit(const CompositeMarkupNode& node);

};

} // namespace xml

#endif // TransformerVisitor_HH
