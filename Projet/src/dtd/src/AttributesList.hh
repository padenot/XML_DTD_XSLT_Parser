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
#include <list>
#include "Attribute.hh"

namespace dtd
{

typedef std::list<Attribute*> AttributesList;

} // namespace dtd

#endif // ATTRIBUTESLIST_HH_
