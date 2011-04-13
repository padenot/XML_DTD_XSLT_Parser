/*************************************************************************
 * XslTransformation  -  Â¬Â´DescriptionÂ¬Âª
 * -------------------
 * D√Â©but      : lun. 11 avril 2011 11:22:13 CEST
 * Auteur(s)  : H4215
 *************************************************************************/

//---- R√Â©alisation de la classe <XslTranformation> (fichier XslTransformation.cpp) ----

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst√Â®me

//------------------------------------------------------ Include personnel
#include "XslTransformation.hh"
#include "TextNode.hh"
#include "CompositeMarkupNode.hh"

using namespace std;
using namespace xml;

namespace xsl
{
//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types priv√Â©s


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- M√Â©thodes publiques
Node & Transformation(Node & XmlTree, Node & XslTree)
{
	/*
	 Transformation(docXmlI, docXSL) : DocXmlF
	 xmlI = analyser(docXmlI) //appel la mÃ©thode pour la construction de la SDD XML
	 xsl = analyser(docXSL) //idÃ©m, variable globale
	 //pour pouvoir accÃ©der rapidement au template
	 global_map = create Map<NomTemplate, NoeudTemplate>();
	 xmlF = analyse_noeud(xmlI.racine());
	 return afficher(xmlF); //mÃ©thode d’affichage (3.2.1)
	 end */
} //----- Fin de Transformation

//------------------------------------------------- Surcharge d'op√Â©rateurs


//-------------------------------------------- Constructeurs - destructeur
XslTransformation::XslTransformation()
{
} //----- Fin de XslTransformation

XslTransformation::~XslTransformation()
{
} //----- Fin de ~XslTransformation


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- M√Â©thodes prot√Â©g√Â©es

//------------------------------------------------------- M√Â©thodes priv√Â©es

Node & XslTransformation::AnalyserNoeud(Node & noeud)
{
	/*analyser_noeud(Noeud x)
	 Template t = rechercher_template(x); //recherche un template qui matche x
	 if (t == vide) //si ce template n’existe pas
	 return recopier(x);
	 else
	 copier (t -> res) //on rÃ©copie le contenu du template ...
	 //on l’analyse pour l’“Ã©tendre” avec les apply-template et aprÃ¨s on le renvoie
	 analyse_template(res,x)
	 return res;
	 end*/
} //----- Fin de AnalyserNoeud


void XslTransformation::AnalyserTemplate(CompositeMarkupNode & patron, Node & noeud)
{
	for (CompositeMarkupNode::ChildrenIterator it = (patron.begin()); it
			!= (patron.end()); it++)
	{
		//if(it.isapplytemplate()){
			it = Recopier(noeud);
		//} else (if
	}
	/*
	 foreach (fils **f de t)
		 if (f.is(apply_template))
			 **f = recopier(x);
		 else if (!f.isTexte())
			 analyse_template(f,x)
		 else
			 //do nothing
	 end_for
	 end*/

} //----- Fin de AnalyserTemplate

list<Node *> & XslTransformation::Recopier(TextNode & noeud)
{
	list<Node *> * node = new list<Node *>();
	node->push_back(&noeud);
	return *node;
	/*
	 else
	 foreach (fils f de x)
	 res.add(analyser_noeud(f))
	 return res;
	 end;*/
} //----- Fin de Recopier

list<Node *> & XslTransformation::Recopier(CompositeMarkupNode & noeud)
{
	list<Node *> * node = new list<Node *>();
	for (CompositeMarkupNode::ChildrenIterator it = (noeud.begin()); it
			!= (noeud.end()); it++)
	{
		node->push_back(&AnalyserNoeud(**it));
	}

	return *node;
} //----- Fin de Recopier


} // namespace xsl
