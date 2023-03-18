#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include <unistd.h>
#define BUFFER_MAX 1000

int pgcd(int a, int b){
    if (b != 0){
       return pgcd(b, a%b);
    }else{
       return (a);
    }
}
	
int premier_entreux(int a, int b){ 
	int PGCD = pgcd(a,b); 
	if(PGCD == 1){
		return(true);
	}else{
		return(false); 
	}
}	

int chercheCara(char c){   //cette fonction va nous permettre de connaitre le rang d'un caractère dans l'alphabe que j'ai crée
    int i;
    for (i = 0; i < tailleAlphabet; i ++) {
        if (c == ALPHABET[i]){     //si la letre est comprise dans l'alphabet on retourne son eang sinon -1
            return (i);
        }
    }
	return(-1);
}
 
int puissance(int n, int p) { //ici une fonction classique de calcul de puissance dont on aura besoin
    int res = 1;
    for (int i = 1; i <= p; i ++) {
        res *= n;
    } 
    return (res);
}
 
char* creeNombre(int val, int taille){ //La fonction créer nombre permet de créer un bloc de la forme [...] à partir du rang d'un caractere dans l'alphabet et de la taille du bloc 
    char *nombre = NULL;               // exemple si mon caractere est au range 3 de l'alphabet et que la taille du bloc souhaitée est 4 on obtient [0003]
    int max = puissance(10, taille - 1), i = 0; 
    
    nombre = (char *) malloc(sizeof (char)* taille); 
    
    while (max != 0) { 							 
        nombre[i] = val/max + '0';			
        val = val%max;								
        max = max/10;
        i++; 
    }
    
    return (nombre);
}

int crypter_lettre(int c,int n,int e){ 		//soit que le char C congru à m^e(mod n);
	int i,resultat=1; 
	
	for(i=0;i<e;i++)
	{
    	resultat = resultat*c;
	 	resultat = resultat%n;
	}
	
	return (resultat);
}

int decrypter_lettre(int c, int d, int n){		//soit que le nombre m est congru à c^d(mod n);
	int i, resultat = 1;
		
	for(i=0; i<d; i++){
		resultat = resultat*c; 
		resultat = resultat%n;  
	}
	 	
	return(resultat); 
}


int * crible_eratostene(int val1, int val2, int *p){
	int i,j,n=0;  
	bool * nopremier = calloc(val2+1, sizeof(bool)); 
	int * tab = malloc((val2-val1)*sizeof(int)); 
	
	for(i=2; i<=val2; i++){
		if(nopremier[i] == false){
			for(j=i; j<=val2; j+=i){
				nopremier[j] = true; 
			}
			tab[n] =i; 
			n++; 
		}
	}
	*p = n; 
	
	return(tab);  
}
		
//srand(time(NULL)); 
	//int a = (rand() % (max - min + 1)) + min;
	 
void generer_premier(int *p1, int *p2){
	int i, j, p; 
	int * tab = crible_eratostene(10,50,&p);
	i = (rand() % p);
	do{
		j = (rand() % p);
	}while(j==i); 
	
	*p1 = tab [i];
	*p2= tab [j];
} 
	 
void calcul_key(int *pn, int *pe, int *pd){
	int p1, p2, phi, n,e,d; 
	
	//~ do{
		generer_premier(&p1, &p2); 						 //generer de grands nombre premier minimum supérieur à 40
	//~ }while(p1*p2 > tailleAlphabet*tailleAlphabet);  
	
	n = (p1*p2); 
	phi = (p1-1)*(p2-1); 
	
	
	do{
		e = rand() % (10-3)+2;  			//e doit etre à la fois inférieur à phi et à la fois premier avec phi

	}while(premier_entreux(e, phi) == false);
	
	
	d = (phi+1)/e;
	
	*pn = n; 
	*pe = e; 
	*pd = d;  
	printf("les deux nombres premiers sont %d et %d\n", p1, p2); 
	printf("la clé publique est : (%d,%d)\nla clé privée est : %d\n",n, e, d);
}

int taille_bloc(int n){
	int i = 0; 
	while(n!= 0){
		n = n/10; 
		i++; 
	}
	return i; 
}

// INTERFACE // 
void affichage(){
	int i; 
	for(i=0; i<80; i++){
		printf("*"); 
	}                                     
	printf("\n                             CHIFFREMENT  R S A                \n"); 
	printf("                        (by badr agrad and walid boudiar)        \n");
	printf("Bienvenue sur l'algorithme de chiffrement RSA développé par Badr Agrad et Walid Boudiar!\n"); 
}

void interactif(char ans){
	printf("Voulez chiffrer un message?[o/n] : ");	
	scanf("%c", &ans); 
	if(ans == 'n'){
		sleep(2); 
		printf("Aurevoir et à bientot sur nos algorithmes !\n"); 
		exit(EXIT_FAILURE); 
	}else{
		if(ans == 'o'){
			printf("OK génial, nous allons vous chiffrer un message assez sympa...\n");
		}
	}

}

void satisfaction(char ans){  
	printf("\nEtes vous satisfait ?[o/n] : \n"); 
	scanf("%c", &ans); 
	if(ans == 'n'){
		sleep(2); 
		printf("Merci de nous faire des recommandations par mail aux adresses suivantes : badragrad@gmail.com et wboudiar5@gmail.com\n"); 
	}else{
		if(ans == 'o'){
			sleep(2); 
			printf("Nous sommes fiers de vous avoir satisfaits !\n");
		}
	}
	sleep(1); 
	printf("A bientot sur nos algorithmes!\n(powered by Badr Agrad & Walid Boudiar)\n"); 	
}
