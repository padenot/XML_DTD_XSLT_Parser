/*************************************************************************
 * XslTransformation  -  «Description»
 * -------------------
 * Début      : lun. 11 avril 2011 11:22:13 CEST
 * Auteur(s)  : H4215
 *************************************************************************/

//---- Réalisation de la classe <XslTranformation> (fichier XslTransformation.cpp) ----

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;

//------------------------------------------------------ Include personnel
#include "XslTransformation.hh"

namespace xsl
{
//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques
Node & Transformation(Node & XmlTree, Node & XslTree)
{

} //----- Fin de Transformation

//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
XslTransformation::XslTransformation()
{

} //----- Fin de XslTransformation

XslTransformation::~XslTransformation()
{

} //----- Fin de ~XslTransformation


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées

list<Node> & XslTransformation::AnalyserNoeud(Node & noeud)
{

} //----- Fin de AnalyserNoeud


void XslTransformation::AnalyserTemplate(Node & patron, Node & noeud)
{

} //----- Fin de AnalyserTemplate

list<Node> & XslTransformation::Recopier(Node & noeud)
{

} //----- Fin de Recopier


} // namespace xsl
