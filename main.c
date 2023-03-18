#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include <unistd.h>
#include "rsa.h"
#define BUFFER_MAX 1000


//Variable globale du programme 
char ALPHABET[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz !:;,.?/_-'(){}[]<>\n\t0123456789";
int tailleAlphabet; 
int TAILLE_BLOC; //on va chiffrer grace à un bloc en mettant les chiffres que l'on obtient entre crochets
//



int main(int argc, char **argv){
	
	srand(time(NULL));
	//~ int n = 1022117, e = 7, d = 767597;
	tailleAlphabet = strlen(ALPHABET);
	//char str[BUFFER_MAX]; 
	int n, e, d;
 	char ans = 0; 
	affichage(); 
	interactif(ans);  
	
	
	sleep(2); 
	printf("Etes vous prêts?...\n");
	sleep(2);  
	
	
	calcul_key(&n, &e, &d);
	TAILLE_BLOC = taille_bloc(n); //si n fait 5 chiffre le bloc fera 5 cases et ainsi de suite...
	//~ printf("la taille du bloc est %d\n", TAILLE_BLOC); 
	
		
	FILE *fp1 = fopen("MESSAGE.txt", "r"); 
	FILE *fp2 = fopen("message codé.txt", "w"); 
	
	
	if(fp1 == NULL){
		printf("ERREUR FILE"); 
		exit(EXIT_FAILURE);
	}
	
	char c;
	int val;  
		
	sleep(2); 
	printf("VOICI LE FICHIER CRYPTÉ ! :\n"); 
	sleep(1); 
	
	while((c=fgetc(fp1))!= EOF){
			val = chercheCara(c);
	
		if(val == -1){
			fprintf(fp2, "[%c]", c); 
		}else{
			val = crypter_lettre(val, n, e); 
			fprintf(fp2, "[%s]", creeNombre(val, TAILLE_BLOC));
			fprintf(stderr, "[%s]", creeNombre(val, TAILLE_BLOC));
			
		}
	}
	printf("\n"); 
	
	fclose(fp1); 
	fclose(fp2); 
	
	
	fp2 = fopen("message codé.txt", "r");
	FILE *fp3 = fopen("message décrypté.txt", "w");  
	
	sleep(2); 
	printf("VOICI LE FICHIER DÉCRYPTÉ ! :\n"); 
	sleep(1); 
	while ((c = fgetc(fp2)) != EOF) {
		fscanf(fp2, "%d", &val);
		val = decrypter_lettre(val, d, n);
		fprintf(fp3, "%c", ALPHABET[val % tailleAlphabet]);
		fprintf(stderr, "%c",ALPHABET[val % tailleAlphabet]); 
		fgetc(fp2);
    }
	
    
    /*
	while(fgets(str, BUFFER_MAX, fp)!= NULL){
		printf("%s\n",str); 
	}
	*/
	
	fclose(fp2); 
	fclose(fp3); 
	
	ans = 0; 
	satisfaction(ans);  
	/*
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
	*/
	
	exit(EXIT_SUCCESS);
}
