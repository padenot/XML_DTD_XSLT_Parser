/*************************************************************************
 * XslTransformation  -  ���Description���
 * -------------------
 * D��but      : lun. 11 avril 2011 11:22:13 CEST
 * Auteur(s)  : H4215
 *************************************************************************/

//---- R��alisation de la classe <XslTranformation> (fichier XslTransformation.cpp) ----

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst��me

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

//----------------------------------------------------------- Types priv��s


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- M��thodes publiques
Node & Transformation(Node & XmlTree, Node & XslTree)
{
	/*
	 Transformation(docXmlI, docXSL) : DocXmlF
	 xmlI = analyser(docXmlI) //appel la m̩thode pour la construction de la SDD XML
	 xsl = analyser(docXSL) //id̩m, variable globale
	 //pour pouvoir acc̩der rapidement au template
	 global_map = create Map<NomTemplate, NoeudTemplate>();
	 xmlF = analyse_noeud(xmlI.racine());
	 return afficher(xmlF); //m̩thode d�affichage (3.2.1)
	 end */
} //----- Fin de Transformation

//------------------------------------------------- Surcharge d'op��rateurs


//-------------------------------------------- Constructeurs - destructeur
XslTransformation::XslTransformation()
{
	templatesMap = new map();
} //----- Fin de XslTransformation

XslTransformation::~XslTransformation()
{
	delete templatesMap;
} //----- Fin de ~XslTransformation


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- M��thodes prot��g��es

//------------------------------------------------------- M��thodes priv��es

Node & XslTransformation::AnalyserNoeud(Node & noeud)
{
	/*analyser_noeud(Noeud x)
	 Template t = rechercher_template(x); //recherche un template qui matche x
	 if (t == vide) //si ce template n�existe pas
	 return recopier(x);
	 else
	 copier (t -> res) //on r̩copie le contenu du template ...
	 //on l�analyse pour l��̩tendre� avec les apply-template et apr̬s on le renvoie
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
		/*	it = Recopier(noeud);
			TransformerVisitor trans(CompositeMarkupNode** parent, ....);
			noeud.accept(trans);
			Node* = trans.result();*/
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
	/*list<Node *> * node = new list<Node *>();
	node->push_back(&noeud);
	return *node;*/
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

Node & XslTransformation::RechercherTemplate(const Node & noeudXML)
{

}

void creerMap(const Node& noeudXSL )
{
	/*std::string key = noeudXSL.;
	map.*/
}

} // namespace xsl
