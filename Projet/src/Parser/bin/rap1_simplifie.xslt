<stylesheet>
  <template match="rapport">
    <html>
      <body>
	 <apply-templates />
      </body>
    </html>
  </template>
 
  <template match="chapitre">
	  <apply-templates />
    <br/><br/>
   </template>
   
   <template match="section">
	<p><apply-templates/></p>
   </template>

   <template match="nom">
	<apply-templates/>
   </template>

   <template match="resume">
	<apply-templates/>
   </template>

   <template match="prenom">
	<apply-templates/>
   </template>

   <template match="auteur">
	<p><apply-templates/></p>
   </template>

   <template match="titre">
	<h2><apply-templates /></h2>
   </template>

</stylesheet>
