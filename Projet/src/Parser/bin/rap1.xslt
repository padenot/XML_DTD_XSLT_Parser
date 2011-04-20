<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet 
  version="1.0"
  xsl="http://www.w3.org/1999/XSL/Transform"
  xmlns="http://www.w3.org/1999/xhtml">
 
  <xsl:output method="xml" indent="yes" encoding="UTF-8"/>
 
  <xsl:template match="/rapport">
    <html>
      <body>
        <xsl:apply-templates />
      </body>
    </html>
  </xsl:template>
 
   <xsl:template match="chapitre">
	<xsl:apply-templates />
    <br/><br/>
   </xsl:template>
   
   <xsl:template match="section">
	<p><xsl:apply-templates/></p>
   </xsl:template>

   <xsl:template match="title">
	<h2><xsl:apply-templates /></h2>
   </xsl:template>

</xsl:stylesheet>
