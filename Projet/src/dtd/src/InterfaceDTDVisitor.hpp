/*************************************************************************
 * InterfaceDTDVisitor  -  «Description»
 * -------------------
 * Début      : 5 avr. 2011
 * Auteur(s)  : H4215
 *************************************************************************/

//---------- Interface de la classe <InterfaceDTDVisitor> (fichier InterfaceDTDVisitor.hh) ------
#if ! defined ( INTERFACEDTDVISITOR_HH_ )
#define INTERFACEDTDVISITOR_HH_

//--------------------------------------------------- Interfaces utilisées

namespace dtd
{
class Element;
class AttributesList;
class EmptyContent;
class MixedContent;
class TextContent;
class ElementReference;
class Choice;
class Sequence;
class OptionalContent;
class RepeatableContent;
class RepeatedContent;

class InterfaceDTDVisitor
{
public:
	//------------------------------------------------------------- Constantes

	//------------------------------------------------------------------ Types

	//----------------------------------------------------- Méthodes publiques

	//------------------------------------------------- Surcharge d'opérateurs

	//-------------------------------------------- Constructeurs - destructeur
	virtual ~InterfaceDTDVisitor()
	// Mode d'emploi (destructeur) :
	//	Ne fait rien (interface).
	// Contrat :
	//	Aucun.
	{
		// Vide
	}

protected:
	friend class Element;
	friend class AttributesList;
	friend class EmptyContent;
	friend class MixedContent;
	friend class TextContent;
	friend class ElementReference;
	friend class Choice;
	friend class Sequence;
	friend class OptionalContent;
	friend class RepeatableContent;
	friend class RepeatedContent;
	virtual void visit(const Element & element) = 0;
	virtual void visit(const AttributesList & attlist) = 0;
	virtual void visit(const EmptyContent & content) = 0;
	virtual void visit(const MixedContent & content) = 0;
	virtual void visit(const TextContent & content) = 0;
	virtual void visit(const ElementReference & element) = 0;
	virtual void visit(const Choice & content) = 0;
	virtual void visit(const Sequence & content) = 0;
	virtual void visit(const OptionalContent & content) = 0;
	virtual void visit(const RepeatableContent & content) = 0;
	virtual void visit(const RepeatedContent & content) = 0;
	// Mode d'emploi :
	//	Visite l'objet donné en paramètre, pour inspection.
	// Contrat :
	//	L'objet visité doit appeler cette méthode avec son type réel
	//	(non hérité) lorsqu'on fait appel à sa méthode accept().

};

} // namespace dtd

#endif // INTERFACEDTDVISITOR_HH_
