#include <stdio.h>
#include <string.h>
typedef	struct compte {
	char cin[10], nom[100], prenom[100];
	float montant;
} cmp;

int main() {
		printf("*****************Projet SAS Gestion Bancaire*****************\n");

	int choix;
	cmp comptes[50] ;
	int size = 0 ;
menu:
	printf(" 1--> Introduire un compte bancaires \n");
	printf(" 2--> Introduire des compte bancaires \n");
	printf(" 3--> Operations : Retrait Depot\n");
	printf(" 4--> Affichage \n");
	printf(" 5--> Fidelisation \n");
	printf(" 6--> Quitter \n");
	scanf("%d",&choix);

	switch (choix) {
		case 1: {
			printf(" enterer votre CIN :  \n ");
			scanf("%s",&comptes[size].cin);
			printf(" enterer votre nom : \n");
			scanf("%s", &comptes[size].nom);
			printf("entrer votre prenom \n");
			scanf("%s", &comptes[size].prenom);
			printf(" enterer votre capitale : \n");
			scanf("%f", &comptes[size].montant);
			system("cls");
			printf("ton nom %s ton prenom %s ton cin %s ton capital %.2f\n", comptes[size].nom, comptes[size].prenom, comptes[size].cin, comptes[size].montant);
			size++;
			goto menu ;
		}
		case 2: {
			int nbrcompte;
			printf("entrer le nobre du compte que tu veux intoduir \n");
			scanf("%d",&nbrcompte);
			for (int i=0; i<nbrcompte; i++) {
				printf(" enterer votre CIN :  \n ");
				scanf("%s",&comptes[size].cin);
				printf(" enterer votre nom : \n");
				scanf("%s", &comptes[size].nom);
				printf("entrer votre prenom \n");
				scanf("%s", &comptes[size].prenom);
				printf(" enterer votre capitale : \n");
				scanf("%f", &comptes[size].montant);
				size++;
			}
			system("cls");
			goto menu;
		}
		case 3: {

			int opera,  idx =-1 ;
			char cin[10];
			printf("quelle operation tu veux ? \n");
			printf("1--> retrait \n");
			printf("2--> depot \n");
			scanf("%d", &opera);
			printf("entrer ton cin \n");
			scanf("%s",&cin);
			for(int i = 0 ; i<size ; i++) 
			{
				if (strcmp(comptes[i].cin, cin) == 0) {
					idx=i;
				}

			}
			if (idx == -1) printf("compte introuvable\n");
			else {

				if (opera == 1) {
					float retrai;
					printf("entrer le montant a retrait : \n");
					scanf("%f", &retrai);
					system("cls");
					comptes[idx].montant -= retrai;
					printf("ton monton apres votre retrait est : %.2f \n",comptes[idx].montant);
					goto menu;
				} else if (opera == 2) {
					float depot;
					printf("entrer le montant a depot : \n");
					scanf("%f", &depot);
					system("cls");
					comptes[idx].montant+=depot;
					printf("ton monton apres votre depot est : %.2f \n",comptes[idx].montant);
					goto menu;
				} else
					printf("operation introuvable \n");
				goto menu ;

			}

		}

		case 4: {
			
		int affich ;
		printf("selectioner votre methode d'affichage : \n");
		printf("1---> affichage Par Ordre Ascendant \n");
		printf("2---> affichage Par Ordre Descendant \n");
		printf("3---> affichage Par Ordre Ascendant (les comptes bancaires ayant un montant superieur a un chiffre introduit) \n");
		printf("4---> affichage Par Ordre Descendant (les comptes bancaires ayant un montant superieur a un chiffre introduit) \n");
		printf("5---> affichage Par Cin \n");
		scanf("%d",&affich);
		if (affich == 1)
		{
			for(int i = 0; i < size-1; i++)
			{
			    int idx = i;
			    for(int j = i+1; j < size; j++){
			      if(comptes[j].montant < comptes[idx].montant) idx = j;
			    }
			    
		      cmp tmp = comptes[i];
		      comptes[i] = comptes[idx];
		      comptes[idx] = tmp;
			    
			}
			for (int i=0 ; i<size ; i++) {
				printf("ton nom %s ton prenom %s ton cin %s ton capital %.2f\n", comptes[i].nom, comptes[i].prenom, comptes[i].cin, comptes[i].montant);
			}
		}
		else if(affich == 2){
			for(int i = 0; i < size-1; i++){
			    int idx = i;
			    for(int j = i+1; j < size; j++){
			      if(comptes[j].montant > comptes[idx].montant) idx = j;
			    }
			    
			      cmp tmp = comptes[i];
			      comptes[i] = comptes[idx];
			      comptes[idx] = tmp;
			    
			  }
			for (int i=0 ; i<size ; i++) {
				printf("ton nom %s ton prenom %s ton cin %s ton capital %.2f\n", comptes[i].nom, comptes[i].prenom, comptes[i].cin, comptes[i].montant);
			}
		}
		else if(affich == 3 )
		{
			float min ;
			printf("enter le min pour afficher par ordre Ascendant \n");
			scanf("%f",&min);		
			for(int i = 0; i < size-1; i++)
			{
			    int idx = i;
			    for(int j = i+1; j < size; j++)
				{
			      if(comptes[j].montant < comptes[idx].montant) idx = j;
			    }
			    
		      cmp tmp = comptes[i];
		      comptes[i] = comptes[idx];
		      comptes[idx] = tmp;
			    
			}
			for (int i=0 ; i<size ; i++) {
				if(comptes[i].montant>=min) 
					printf("ton nom %s ton prenom %s ton cin %s ton capital %.2f\n", comptes[i].nom, comptes[i].prenom, comptes[i].cin, comptes[i].montant);
			}
		}

		else if(affich == 4 )
		{
			float min ;
			printf("enter le min pour afficher par ordre Descendant \n");
			scanf("%f",&min);		
			for(int i = 0; i < size-1; i++)
			{
			    int idx = i;
			    for(int j = i+1; j < size; j++)
				{
			      if(comptes[j].montant > comptes[idx].montant) idx = j;
			    }
			    
		      cmp tmp = comptes[i];
		      comptes[i] = comptes[idx];
		      comptes[idx] = tmp;
			    
			}
			for (int i=0 ; i<size ; i++)
			 {
				if(comptes[i].montant>=min) 
					printf("ton nom %s ton prenom %s ton cin %s ton capital %.2f\n", comptes[i].nom, comptes[i].prenom, comptes[i].cin, comptes[i].montant);
			}
		}

		else if (affich == 5)
			{
				int idx =-1;
				char cin[10];
				printf("entrer ton cin pour chercher \n");
				scanf("%s",&cin);
				for(int i = 0 ; i<size ; i++) 
			{
				
				if (strcmp(comptes[i].cin, cin) == 0) {
					idx=i;
				}
			
			}
				if (idx == -1) printf("compte introuvable\n");
			else
				printf("le compte rechercher est : votre nom et %s votre prenom %s votre cin %s votre capitale %.2f\n",comptes[idx].nom, comptes[idx].prenom, comptes[idx].cin, comptes[idx].montant);
 						
			
			}	
			goto menu;

			system("cls");

		}

		case 5: {
				for(int i = 0; i < size-1; i++)
			{
			    int idx = i;
			    for(int j = i+1; j < size; j++)
				{
			      if(comptes[j].montant > comptes[idx].montant) idx = j;
			    }
			    
		      cmp tmp = comptes[i];
		      comptes[i] = comptes[idx];
		      comptes[idx] = tmp;
			    
			}
		
			for(int i=0; i<3 ; i++)
			{
				comptes[i].montant += (comptes[i].montant * 0.013 );
				
			}
			
			printf("\n apres fedilisation \n");
			
				for (int i=0 ; i<size ; i++)
			 {
					printf("ton nom %s ton prenom %s ton cin %s ton capital %.2f\n", comptes[i].nom, comptes[i].prenom, comptes[i].cin, comptes[i].montant);
			}
		}

		case 6: {
			printf("cliquer sur entrer pour terminer le programme");
		
				return 0;
		}
	}

	return 0;
}