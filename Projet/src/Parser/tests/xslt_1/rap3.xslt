<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet 
  version="1.0"
  xsl="http://www.w3.org/1999/XSL/Transform"
  xmlns="http://www.w3.org/1999/xhtml">
 
  <xsl:output method="xml" indent="yes" encoding="UTF-8"/>
 
  <xsl:template match="chapitre">
    <html>
      <body>
      	<h1>
         <xsl:apply-templates />
        </h1>
      </body>
    </html>
  </xsl:template>
  
  <xsl:template match="section">
	<h2><xsl:apply-templates/></h2>
   </xsl:template>
   
   <xsl:template match="titre">
	<p><b><xsl:apply-templates/></b></p>
   </xsl:template>
</xsl:stylesheet>
