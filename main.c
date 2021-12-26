//main ==>pour partie en ligne de commande

#include <stdio.h>
#include <mysql.h>
#include "test_my_lib.c" //func sql
#include <string.h>

//prototype
void chose_table(int tables,char *table);

//func
void chose_table(int tables,char *table){
  switch(tables){
   case 1:
        strcpy(table,"AGE");
        break;
   case 2:
        strcpy(table,"EMPLOYE");
        break;
   case 3:
        strcpy(table,"ENTREPRISE");
        break;
   case 4:
        strcpy(table,"FICHIER");
        break;
   case 5:
        strcpy(table,"PHYSIQUE");
        break;
   case 6:
        strcpy(table,"QUESTIONS");
        break;
   case 7:
        strcpy(table,"TRAVAIL");
        break;
   case 8:
        strcpy(table,"VISAGE");
        break;
   default:
        printf("valeur inconnu, veuillez recommencer\n");
        break;
 };
}

//main
int main(int argc, char** argv) {
int tables;
char table[50]="false";
char menu;
char next='a';
int id;
int error;

  printf("Bienvenue dans le menu de modification \nIci, vous pouvez ajouter/modifier/supprimer une information");

   //connect bdd
   connect_bdd();

  printf("\nvoici les TABLES modificables :\n ");
  print_tables();//afficher tt les tables de la bdd

  printf("\nQuelle table voulez-vous modifer ? \(entrez son numero)\n");
  scanf("%d",&tables);

  //switch pour select table
  chose_table(tables,table);

  if(strstr(table,"false")==NULL){
  printf("\nVous avez choisi la table %s. Continuez ? (o/n): ",table);
  }else{
  printf("Recommencer ou quitter (r/q): ");
  }

  scanf("\n%c",&next);

  if(next == 'o'){
 	print_table(table);
 	printf("\nVoulez-vous ajouter (a),modifier (m) ou supprimer (s) un element ?: ");
 	scanf("\n%c",&menu);
	if(menu == 's'){
		printf("\nEntrez l'ID de l'element a supprimer: ");
		scanf("%d",&id);
		error = delete_element(table,id);
		if(error !=0){
			printf("erreur lors de la suppression\n");
		}else{
			printf("suppression reussie\n");
		}
	}else if(menu == 'a'){
	insert_table(tables);
	}
 }else if(next == 'n'){
	printf("Recommencer ou quitter (r/q): ");
	scanf("\n%c",&next);
 }
/*
   //insert
   insert_entreprise();

   //print * ENTREPRISE
   print_entreprise();
*/

  close_mysql();
    return 0;
}
