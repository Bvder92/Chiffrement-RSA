#ifndef __RSA_H_
#define __RSA_H_



int pgcd(int a, int b);

int premier_entreux(int a, int b);

int chercheCara(char c);
 
int puissance(int n, int p);
 
char* creeNombre(int val, int taille);
                 

int crypter_lettre(int c,int n,int e); 		

int decrypter_lettre(int c, int d, int n);	
	

int * crible_eratostene(int val1, int val2, int *p);
		

	 
void generer_premier(int *p1, int *p2);
	 
void calcul_key(int *pn, int *pe, int *pd);

int taille_bloc(int n);

// INTERFACE // 
void affichage();

void interactif(char ans);

void satisfaction(char ans);

#endif