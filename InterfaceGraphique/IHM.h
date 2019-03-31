int longueurChaineEnPixels(char *chaine, int hauteur_chaine);
int xminChaineCentree(char *chaine, int hauteur_chaine);

void changeTitre(zone *zTitre, char *titre);
void initZoneTitre(zone *zTitre, char *titre);
void initZones(zone *zQuit, zone *zHome, zone *zRetour);
void redimensionneZones(zone *zQuit, zone *zHome, zone *zRetour, DonneesImageRGB *retour, DonneesImageRGB *home, DonneesImageRGB *croix);
void changeZoneTitre(zone *zTitre,int numPage);
void redimmensionneZoneTitre(zone *zTitre);

void monIHM(zone zQuit, zone zHome, zone zRetour, int numpage); //affiche éléments principaux de l'IHM (boutons quitter retour home, logo)

void afficheTitre(zone zTitre, int epaisseur_trait); 
void afficheAcceuil(zone zTitre);

void afficheImage(zone zITest, DonneesImageRGB *image);//affiche image dans zone

