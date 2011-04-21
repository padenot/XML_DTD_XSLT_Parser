<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet 
  version="1.0"
  xsl="http://www.w3.org/1999/XSL/Transform"
  xmlns="http://www.w3.org/1999/xhtml">
 
  <xsl:output method="xml" indent="yes" encoding="UTF-8"/>
 
   <xsl:template match="chapitre">
	<YOUHOUDEBUT/>
	<!--
	<h2><xsl:apply-templates select="titre"/></h2>
    <xsl:apply-templates select="section"/>-->
	<xsl:apply-templates />
    <YOUHOUFIN/>
   </xsl:template>
   
   <xsl:template match="section">
	<SECTION><xsl:apply-templates/></SECTION>
   </xsl:template>

</xsl:stylesheet>
