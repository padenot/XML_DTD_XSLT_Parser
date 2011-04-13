/*************************************************************************
 * AttributesList  -  «Description»
 * -------------------
 * Début      : 5 avr. 2011
 * Auteur(s)  : H4215
 *************************************************************************/

//---------- Interface de la classe <AttributesList> (fichier AttributesList.hh) ------
#if ! defined ( ATTRIBUTESLIST_HH_ )
#define ATTRIBUTESLIST_HH_

//--------------------------------------------------- Interfaces utilisées
#include <set>
#include "Attribute.hh"

namespace dtd
{

struct AttributesComparator: binary_function<Attribute*, Attribute*, bool>
{
	bool operator()(const Attribute* const & x, const Attribute* const & y) const
	{
		return x->name() < y->name();
	}
};

typedef std::set<Attribute*, AttributesComparator> AttributesList;

} // namespace dtd

#endif // ATTRIBUTESLIST_HH_
