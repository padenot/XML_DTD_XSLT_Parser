/*************************************************************************
 * Content  -  «Description»
 * -------------------
 * Début      : lun. 04 avril 2011 10:12:33 CEST
 * Auteur(s)  : H4215
*************************************************************************/

//---- Interface de la classe <Content> (fichier Content.hh) ----
#ifndef CONTENT_HH
#define CONTENT_HH

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------------------
// Rôle de la classe <Content>
//	«Rôle»
//
//------------------------------------------------------------------------

namespace dtd
{

class Content
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
	Content & operator = ( const Content & unContent );
	// Mode d'emploi :
	//	«TODO»
	// Contrat :
	//	«TODO»


//-------------------------------------------- Constructeurs - destructeur
	Content ( const Content & unContent );
	// Mode d'emploi (constructeur de copie) :
	//	«Mode emploi»
	// Contrat :
	//	«TODO»

	Content ( );
	// Mode d'emploi (constructeur) :
	//	«TODO»
	// Contrat :
	//	«TODO»

	virtual ~Content ( );
	// Mode d'emploi (destructeur) :
	//	«TODO»
	// Contrat :
	//	«TODO»

protected:

};

} // namespace dtd

#endif // CONTENT_HH

