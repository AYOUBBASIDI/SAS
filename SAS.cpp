#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
	void menu(){
	printf("\n============================Bienvenue dans *banque de triche*============================\n\n\n");
	printf("\t\t\t\t======== Menu ========\n\n");
	printf("\t\t\t\t1 . Creation du compte \n");
	printf("\t\t\t\t2 . Creation du plusieurs comptes \n");
	printf("\t\t\t\t3 . Crediter un compte \n");
	printf("\t\t\t\t4 . Debiter un compte \n");
	printf("\t\t\t\t5 . Affichage : \n");
	printf("\t\t\t\t6 . La fidelidation\n");
	printf("\t\t\t\t7 . Quiter\n\n");
    printf("\t\t\t\t======================\n\n");
    printf("Entrer votre choix:\n");    
	}
	void Ma(){
	printf("\n============================Bienvenue dans *banque de triche*============================\n\n\n");
	printf("\t\t\t\t============= Menu ============\n");
	printf("\t\t\t\t========== Affichage ==========\n\n");
	printf("\t\t\t\t1 . Par Order Ascendant \n");
	printf("\t\t\t\t2 . Par Order Descendant \n");
	printf("\t\t\t\t3 . Par Order Ascendant Avec Filtre \n");
	printf("\t\t\t\t4 . Par Order Descendant Avec Filtre \n");
	printf("\t\t\t\t5 . Recherche par CIN \n");
	printf("\t\t\t\t6 . retour au menu \n\n");
	printf("\t\t\t\t==============++++=============");
	}
	void s_sleep(int seconds) {
    /* Init. */
    time_t start_time = 0;
    time_t current_time = 0;
 
    /* Operate. */
    start_time = time(NULL);
    while(current_time-start_time+1 <= seconds) {
        current_time = time(NULL);
    }
}
int main () {
//variables//////////////////////////////////////////////////////////////////////////////////////////////////////
		int choixMenu,choixAffich;
		char nom[30][50];
		char prenom[30][50];
		char cin[30][50];
		float sold[30];
		int nbrdc=0,i,retourn=2;
		char CIN[10];
		float S;
		int a,position,ech,rep=1,temp;
//for repetition//////////////////////////////////////////////////////////////////////////////////////////////////	    
do
{
	system("cls");//clear
    menu();
    scanf("%d", &choixMenu);
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////	
	if (choixMenu == 1)
	{
		printf("\n\nMerci de vouloir faire partie de mes comptes veuillez saisir vos information\n\n");
		printf("1.Nom :  ");
		scanf("%s",&nom[0]);
		printf("\n2.Prenom :  ");
		scanf("%s",&prenom[0]);
		printf("\n3.Numero de CIN :  ");
		scanf("%s",&cin[0]);
		printf("\n4.Le premier solde en (DH) :  ");
		scanf("%f",&sold[0]);
	    printf("\n Le compte a etait creer ");
	    s_sleep(2);
	}	
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////	
	else if (choixMenu == 2)
	{
		printf("entrer le nombre des compte vous voulez creer :  ");
		scanf("%d",&nbrdc);
		for(i=1;i<nbrdc+1;i++)
		{
		printf("\n1.Nom du %d compte :  ",i);
		scanf("%s",&nom[i]);
		printf("\n2.Prenom du %d compte :  ",i);
		scanf("%s",&prenom[i]);
		printf("\n3.Numero de CIN :  ",i);
		scanf("%s",&cin[i]);
		printf("\n4.Le premier solde :  ",i);
		scanf("%f",&sold[i]);	
		} 
	}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	
	else if (choixMenu == 3)
	{
		printf("saisir le CIN du compte : \n");
		scanf("%s",&CIN);
		for(i=0;i<nbrdc+1;i++)
		{
			if(strcmp(CIN,cin[i])==0)
			{
				a=1;
				position = i;
			}
	   	}
	    if (a==1)
		{
	    	printf("le compte est exist (%s)\n-saisir le montant qui vous voulez credite(dh) : ",nom[position]);
			scanf("%f",&S);
			sold[position] += S;
			a=0;
			printf("\nAttendre...");
            s_sleep(2);
            printf("\nTerminer.");
            s_sleep(2);
		}
		else  
		printf("le compte n'est pas exist");
		s_sleep(2);
	    
	}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////	
	else if (choixMenu == 4)
    {
		printf("saisir le CIN du compte  : \n");
		scanf("%s",&CIN);
				for(i=0;i<nbrdc+1;i++)
		{
		if(strcmp(CIN,cin[i])==0){
		a=1;
		position = i;
		}
	   	}
		    if (a==1)
		    {
	    	printf("le compte est exist (%s)\n-saisir le montant qui vous voulez credite(dh) : ",nom[position]);
				scanf("%f",&S);
				if (S <= sold[position]){
				sold[position] -= S;
				a=0;
                printf("\nAttendre...");
                s_sleep(2);
                printf("\nTerminer.");
                s_sleep(2);
			    }
			    else if (S > sold[position])
			    {
			    printf("compte non soldable\n");
			    s_sleep(2);
				}
			}
			else
			{
			printf("le compte n'est pas exist");
			s_sleep(2);
	    	}
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////	
    else if (choixMenu == 6)
    {
    int ech;
     //le tri
     do
     {
	 ech=0;	
     for (i=0;i<nbrdc;i++){
	
	 if(sold[i]<sold[i+1])
 	{
	 position=i;	
	 float tmp;
	 char Tmp[50];
	 //SOLD
		tmp = sold[position];
		sold[position] = sold[position+1];
		sold[position+1]= tmp;
	 //NOM
		strcpy(Tmp,nom[position]);
		strcpy(nom[position],nom[position+1]);
		strcpy(nom[position+1],Tmp);
     //prenom
		strcpy(Tmp,prenom[position]);
		strcpy(prenom[position],prenom[position+1]);
		strcpy(prenom[position+1],Tmp);
	 //cin
		strcpy(Tmp,cin[position]);
		strcpy(cin[position],cin[position+1]);
		strcpy(cin[position+1],Tmp);	    				
		ech++;
	}//fin de if
    }//fin de for
    }//fin de do
     while(ech>0);
     for(i=0;i<3;i++)
	{
	     sold[i] += sold[i]*0.013;
	   }  
     printf("Operation terminee");
     s_sleep(2);
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////			
    else if (choixMenu == 5)
    {
     do
    {
	system("cls");	
	Ma();//menu d'affich
	printf("\nEntrer votre choix : \n");
	scanf("%d",&choixAffich);
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////	
	if (choixAffich==1)
	{
     do
     {
	 ech=0;
 	
     for (i=0;i<nbrdc;i++){
       	
	 if(sold[i]>sold[i+1])
 	{
	 position=i;
	 float tmp;
	 char Tmp[50];
	 //SOLD
		tmp = sold[position];
		sold[position] = sold[position+1];
		sold[position+1]= tmp;
	 //NOM
		strcpy(Tmp,nom[position]);
		strcpy(nom[position],nom[position+1]);
		strcpy(nom[position+1],Tmp);
     //prenom
		strcpy(Tmp,prenom[position]);
		strcpy(prenom[position],prenom[position+1]);
		strcpy(prenom[position+1],Tmp);
	 //cin
		strcpy(Tmp,cin[position]);
		strcpy(cin[position],cin[position+1]);
		strcpy(cin[position+1],Tmp);	    				
		ech++;
     }//fin de if
     }//fin de for
     }//fin de do
     while(ech>0);
     for(i=0;i<nbrdc+1;i++)
	 printf("\n\n (%s %s) (%s) => [%f] ",nom[i],prenom[i],cin[i],sold[i]);
	 s_sleep(3);
}//fin de choix d'aff1
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	
	else if (choixAffich==2)
	{
	 do
     {
	 ech=0;
	
     for (i=0;i<nbrdc;i++){
	
 	 if(sold[i]<sold[i+1])
 	 {position=i;
		float tmp;
		char Tmp[50];
	 //SOLD
		tmp = sold[position];
		sold[position] = sold[position+1];
		sold[position+1]= tmp;
	 //NOM
		strcpy(Tmp,nom[position]);
		strcpy(nom[position],nom[position+1]);
		strcpy(nom[position+1],Tmp);
     //prenom
		strcpy(Tmp,prenom[position]);
		strcpy(prenom[position],prenom[position+1]);
		strcpy(prenom[position+1],Tmp);
	 //cin
		strcpy(Tmp,cin[position]);
		strcpy(cin[position],cin[position+1]);
		strcpy(cin[position+1],Tmp);	    				
		ech++;
	 }//fin de if
     }//fin de for
     }//fin de do
     while(ech>0);
     for(i=0;i<nbrdc+1;i++)
	 printf("\n (%s %s) (%s) => [%f] ",nom[i],prenom[i],cin[i],sold[i]);
   	 s_sleep(3);
}//fin de choix d'aff2
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////    
	else if (choixAffich==3)
	{
     do
     {
	 ech=0;
 	
     for (i=0;i<nbrdc;i++)
	 {  	
	 if(sold[i]>sold[i+1])
 	 {
	 position=i;
	 float tmp;
	 char Tmp[50];
	 //SOLD
		tmp = sold[position];
		sold[position] = sold[position+1];
		sold[position+1]= tmp;
	 //NOM
		strcpy(Tmp,nom[position]);
		strcpy(nom[position],nom[position+1]);
		strcpy(nom[position+1],Tmp);
     //prenom
		strcpy(Tmp,prenom[position]);
		strcpy(prenom[position],prenom[position+1]);
		strcpy(prenom[position+1],Tmp);
	 //cin
		strcpy(Tmp,cin[position]);
		strcpy(cin[position],cin[position+1]);
		strcpy(cin[position+1],Tmp);	    				
		ech++;
	}
}
}
while(ech>0);
     printf("saisir un solde : ");
	 scanf("%f",&S);
	 for(i=0;i<nbrdc+1;i++)
	 if (sold[i] == S){
	 	a=1;
	 	position=i;
	 }
	 if (a=1)
	 {
     for(i=position;i<nbrdc+1;i++)
	 printf("\n (%s %s) (%s) => [%f] ",nom[i],prenom[i],cin[i],sold[i]);
	 s_sleep(3);
	 a=0;
     }
     else
     printf("solde pas trouvé");
     s_sleep(3);
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////	
	else if (choixAffich==4)
	{
     do
     {
	 ech=0;
     for (i=0;i<nbrdc;i++)
	 {
	 if(sold[i]<sold[i+1])
 	 {
	 position=i;
	 float tmp;
	 char Tmp[50];
	 //SOLD
		tmp = sold[position];
		sold[position] = sold[position+1];
		sold[position+1]= tmp;
	 //NOM
		strcpy(Tmp,nom[position]);
		strcpy(nom[position],nom[position+1]);
		strcpy(nom[position+1],Tmp);
     //prenom
		strcpy(Tmp,prenom[position]);
		strcpy(prenom[position],prenom[position+1]);
		strcpy(prenom[position+1],Tmp);
	 //cin
		strcpy(Tmp,cin[position]);
		strcpy(cin[position],cin[position+1]);
		strcpy(cin[position+1],Tmp);	    				
		ech++;
	 }//fin de if
     }//fin de for
     }//fin de do
     while(ech>0);
     printf("saisir un solde : ");
	 scanf("%f",&S);
	 for(i=0;i<nbrdc+1;i++)
	 if (sold[i] == S){
	 	a=1;
	 	position=i;
	 }
	 if (a=1)
	 {
     for(i=position;i<nbrdc+1;i++)
	 printf("\n (%s %s) (%s) => [%f] ",nom[i],prenom[i],cin[i],sold[i]);
	 s_sleep(3);
	 a=0;
     }
     else
     printf("solde pas trouvé");
     s_sleep(3);    
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////	
	else if (choixAffich==5)
	{
	 printf("saisir le CIN du compte : \n");
	 scanf("%s",&CIN);
	 for(i=0;i<nbrdc+1;i++)
		{
		if(strcmp(CIN,cin[i])==0)
		{
			a=1;
			position = i;
		}
	   	}
         if (a==1)
         {
         	printf("le compte est exist\n\n (%s %s) (%s) => [%f] ",nom[position],prenom[position],cin[position],sold[position]);
	    	s_sleep(3);
	    	a=0;
		 }
		 else
		 printf("le compte n'est pas exist");
		 s_sleep(3);
	}
}//fin de do
    while (choixAffich != 6);
    {
     printf("\t\t\t\t========== Retourne ===========");
     s_sleep(2);
    }
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////    

    }//fin de choixMenu 5}
    }//fin de premiere do
 ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////   
    
    while (choixMenu != 7);
     printf("\t\t\t\t=====+ au revoir +=====\n");
}
