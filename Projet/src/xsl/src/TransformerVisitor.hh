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
	//	Construit un nouveau visiteur écrivant sur "out".
	// Contrat :
	//	Aucun.


	virtual ~TransformerVisitor();
	// Mode d'emploi (destructeur) :
	//	Libère les éventuelles ressources allouées par le visiteur.
	// Contrat :
	//	Aucun.


protected:

	virtual void visit(const TextNode& node)
	{
		// Recopier un TextNode
	}
	virtual void visit(const MarkupNode& node)
	{
		// Recopier un MarkupNode
	}

	virtual void visit(const CompositeMarkupNode& node)
	{
		// Recopier un CompositeMarkupNode
	}

	// Mode d'emploi :
	//	TODO
	// Contrat :
	//	Aucun.


};

} // namespace xml

#endif // TransformerVisitor_HH
