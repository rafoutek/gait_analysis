#include <stdbool.h>

#define AFFICHAGE false

#define NB_LAYERS 2 // dont la couche de sortie
#define NB_NEURONES_LAYER_1 30
#define NB_NEURONES_LAYER_2 25
#define NB_NEURONES_LAYER_3 10


#define ACTIVATION_BIAIS 1
#define LEARNING_SPEED 0.15
#define ERROR 2

typedef struct ENTREE ENTREE;
struct ENTREE{
	double x; 
	double poids;
	double erreur_locale;
};

//structures du modèle (exemples à entrer à la main)
typedef struct MODELE MODELE;
struct MODELE{
	int nb_entrees;
	ENTREE *entrees;
	int nb_sorties;
	double *sorties_attendues;
};

typedef struct MODELE_COMPLET MODELE_COMPLET;
struct MODELE_COMPLET{
	int nb_entrees;
	int nb_sorties;
	int nb_modeles;
	MODELE *modeles;
};

//structures du réseau
typedef struct PERCEPTRON PERCEPTRON;
struct PERCEPTRON{
	double biais;
	int nb_entrees;
	ENTREE *entrees;
	double sortie_somme;
	double sortie_sigmoide, sortie_seuil, sortie;
	double erreur_globale, erreur_locale; //erreur globale si neurone appartient à la couche sortie
	int nb_entrees_suivantes_liees;
	ENTREE **entrees_suivantes_liees; //sortie du neurone va à ces entrées
};

typedef struct COUCHE COUCHE;
struct COUCHE{
	int numero_couche;
	int nb_neurones;
	PERCEPTRON *neurones;
};

typedef struct RESEAU RESEAU;
struct RESEAU{
	int nb_couches;
	COUCHE *couches;
};

typedef struct CLASSEMENT CLASSEMENT;
struct CLASSEMENT{
	int chiffre;
	double pourcentage_ressemblance;
};