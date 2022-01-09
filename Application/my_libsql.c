#include <string.h>
#include <mysql.h>
#include <stdlib.h>
#include <stdio.h>

#include <unistd.h>

MYSQL mysql;
MYSQL_ROW row;


//prototype
void my_fgets(char *string,int size);
void clean_stdin();//remplace fflush

void printf_tables();
void choose_table(char* name_table);
void delete_element(char* name_table);
void insert_employe();
void insert_questions();
void func_insert_element(char* name_table);
void insert_element(char* name_table);
void modify_element(char* name_table);

//func

//func pour saisir strings
void my_fgets(char *string,int size){
	fgets(string,size,stdin);
        if(string[strlen(string)-1]== '\n');
        string[strlen(string)-1]= '\0';
}

void clean_stdin(void)
{
    int c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}

//print les TABLES de la bdd
void printf_tables(){

	int count=1;

        mysql_query(&mysql,"SHOW TABLES");// permit to do sql query => &mysql is pointer who ref at our bdd
        MYSQL_RES * res = mysql_store_result(&mysql);//store result in res =>&mysql is pointer who ref at our bdd

        while((row = mysql_fetch_row(res))) {
            printf("\t %d) %s\n",count,row[0]);
		count++;
          }//print result to the request

	mysql_free_result(res);//emply the buffer
}

//renvoie le nom de la table select
void choose_table(char* name_table){
int error=0;
	do{
		if(error==1){
			printf("la table selectionnee n'existe pas \n");
		}
		printf("Quelle table voulez-vous modifer ? (entrez le nom de la table en majuscule)\n");
		my_fgets(name_table,20);
		char sql_cmd[2000];
        	sprintf(sql_cmd,"SELECT * FROM %s",name_table);
        	mysql_query(&mysql,sql_cmd);
		MYSQL_RES * res = mysql_store_result(&mysql);
		error=1;
	}while((long) mysql_affected_rows(&mysql) == -1);

	if((long) mysql_affected_rows(&mysql) == 0)
		printf("aucune information n'est dans la table pour le moment\n");
	else{
		char sql_cmd[2000];
                sprintf(sql_cmd,"SELECT * FROM %s",name_table);
                mysql_query(&mysql,sql_cmd);
                MYSQL_RES * res = mysql_store_result(&mysql);
		printf("voici les informations contenues dans la table\n");
                        while((row = mysql_fetch_row(res))) {
				printf("|id:%s |",row[0]);
                                for (int i=1 ; i < mysql_num_fields(res); i++)
              				printf(" %s |",row[i]);
                               printf("\n");
                        }
		mysql_free_result(res);//emply the buffer
		}
		printf("Vous avez choisi la table %s. Continuez ? (o/n): ",name_table);
}

void  delete_element(char* name_table){
int id;

	char sql_cmd[2000];
	sprintf(sql_cmd,"SELECT * FROM %s",name_table);
	mysql_query(&mysql,sql_cmd);
	MYSQL_RES * res = mysql_store_result(&mysql);

	if((long) mysql_affected_rows(&mysql) == 0)
                printf("aucune information a supprimer\n");
	else{
                sprintf(sql_cmd,"SELECT * FROM %s",name_table);
                mysql_query(&mysql,sql_cmd);
                MYSQL_RES * res = mysql_store_result(&mysql);
 		printf("voici les informations contenues dans la table\n");
  		while((row = mysql_fetch_row(res))) {
			printf("|id:%s |",row[0]);
  			for (int i=1 ; i < mysql_num_fields(res); i++)
  				printf(" %s |",row[i]);
                        printf("\n");
        	}
  		mysql_free_result(res);//emply the buffer

  		printf("Entrez l'ID de l'element a supprimer \n");
  		clean_stdin();
		scanf("%d",&id);
		char sql_cmd[2000];
  		sprintf(sql_cmd,"DELETE FROM %s WHERE id = %d",name_table,id);
  		mysql_query(&mysql,sql_cmd);

  		if((long) mysql_affected_rows(&mysql) == 0)
                	printf("aucune information supprimes\n");
  		else if((long) mysql_affected_rows(&mysql) == -1)
                	printf("erreur lors de la suppression\n");
  		else
			printf("suppression effectuee avec succes\n");
  	}
}

void func_insert_element(char* name_table){
	if(strstr(name_table,"QUESTIONS") != NULL )
		insert_questions();
	else if(strstr(name_table,"EMPLOYE") != NULL)
		insert_employe();
	else
		insert_element(name_table);
}


void insert_element(char* name_table){
	char** tmp;
	char champs[500] = "";
        char value[500] = "";
	int count=0;
	int i = 0;
	char val1[20]="";
	int error =0;

	char sql_cmd[2000];
	sprintf(sql_cmd,"DESC %s",name_table);

	mysql_query(&mysql,sql_cmd);
        MYSQL_RES * res = mysql_store_result(&mysql);
	row = mysql_fetch_row(res);
        while((row = mysql_fetch_row(res)))
                count++;

	tmp = malloc(sizeof(char*)*count);

	sql_cmd[2000];
        sprintf(sql_cmd,"DESC %s",name_table);
        mysql_query(&mysql,sql_cmd);
        res = mysql_store_result(&mysql);
        row = mysql_fetch_row(res);

	clean_stdin(); //Vider le cash
        printf("\nInserez les informations que vous voulez ajouter:\n");
	while((row = mysql_fetch_row(res))) { //ranger les noms des lignes + insertion par le user
		strcat(champs,row[0]); //noms des lignes
		strcat(champs,",");

		printf("%s : %s\n",row[0],row[1]); //affiche les noms et types des lignes

		tmp[i]=malloc(sizeof(char)*255); //valeurs a inserer
		do{
			error=0;
			my_fgets(tmp[i],255);
			if(strlen(tmp[i]) == 0){
				error=1;
				printf("veuillez resaisir: ");
			}
			if(error == 0 && (strstr(name_table,"AGE") != NULL || strstr(name_table,"TAILLE")!= NULL)){
				if(i == 0){
					if(atoi(tmp[i])<=0){
						printf("vous devez saisir val2>val1 ou val1 != val2 ou avec val1 et val2 tout deux positif \n");
				     		error =1;
						printf("val1: ");
					}
				}
				else{
					strncpy(val1,value+1,strlen(value)-2);//pour convertir value en int
					if(atoi(val1)>=atoi(tmp[i]) || atoi(tmp[i])<=0 ){
						printf("vous devez saisir val2>val1 ou val1 != val2 ou avec val1 et val2 tout deux positif \n");
						printf("val2: ");
						error =1;
					}
				}
			}

		}while(error == 1);

                strcat(value,"'");
                strcat(value,tmp[i]);
                strcat(value,"'");
                strcat(value,",");

		i++;
	}
        champs[strlen(champs)-1]= '\0'; //enlever la derniere virgule
        value[strlen(value)-1]= '\0'; //enlever la derniere virgule

	//free des tableaux dynamiques
	for (int i = 0; i < count; i++){
		free(tmp[i]);
	}
        free(tmp);

	//Insersion
        sql_cmd[2000];
        sprintf(sql_cmd,"INSERT INTO %s (%s) VALUES(%s)",name_table,champs,value);
        mysql_query(&mysql,sql_cmd);

        if((long) mysql_affected_rows(&mysql) == 0) //cas d erreur
                printf("aucune information inserees\n");
        else if((long) mysql_affected_rows(&mysql) == -1)
                printf("erreur lors de l'insersion\n");
        else
                printf("insersion effectuee avec succes\n");

        mysql_free_result(res);
}

void insert_questions(){
	int count=0;
	int num_table;
	char fk[10]="";
	char name_table[25]="";
	char value[260]="'";
	char phrase[255]="";
	char champs[255] = "Phrase";
	char sql_cmd[2000];
	int error;

	printf("votre question est en rapport avec quelle table ?");
	mysql_query(&mysql,"SHOW TABLES");
        MYSQL_RES * res = mysql_store_result(&mysql);
	printf("\n");
        while((row = mysql_fetch_row(res))) {
            if(strstr(row[0],"FICHIER")==NULL && strstr(row[0],"QUESTIONS") == NULL && strstr(row[0],"EMPLOYE")== NULL && strstr(row[0],"ENTREPRISE")== NULL ){
		printf("\t %d) %s\n",count,row[0]);
		count++;
		}
	}
	mysql_free_result(res);

	do {
		error=0;
		printf("selectionner le numero de la table a changer: ");
		scanf("%d",&num_table);

		switch(num_table){

		case 0:
			strcpy(name_table,"AGE");
			strcat(champs,",ID_AGE");
			break;
		case 1:
			strcpy(name_table,"CHEVEUX");
			strcat(champs,",ID_CHEVEUX");
			break;
		case 2:
			strcpy(name_table,"PILOSITE");
			strcat(champs,",ID_PILOSITE");
			break;
		case 3:
			strcpy(name_table,"SEXE");
			strcat(champs,",ID_SEXE");
			break;
		case 4:
			strcpy(name_table,"TAILLE");
			strcat(champs,",ID_TAILLE");
			break;
		case 5:
			strcpy(name_table,"TRAVAIL");
			strcat(champs,",ID_TRAVAIL");
			break;
		case 6:
			strcpy(name_table,"YEUX");
			strcat(champs,",ID_YEUX");
			break;
		default:
			printf("table inconnu, veuillez recommencer\n");
			error=1;
		}
	}while(error ==1);
	printf("%s",champs);
	insert_element(name_table);
	do{
		printf("Entrez la question que vous voulez poser sans mettre d'accent ni d'apostrophe (veuillez reprendre les informations que vous avez saisie plus haut)\n");
		printf("Ex: Est-ce que votre personne a les yeux bleue?\n");
		my_fgets(phrase,255);
	}while(strlen(phrase) == 0 || strstr(phrase,"'") != NULL);
	strcat(value,phrase);
	strcat(value,"'");

        sprintf(sql_cmd,"SELECT MAX(ID)FROM %s",name_table);
        mysql_query(&mysql,sql_cmd);
        res = mysql_store_result(&mysql);
        while((row = mysql_fetch_row(res))) {
               strcpy(fk,row[0]);
        }
	mysql_free_result(res);
	strcat(value,",'");
	strcat(value,fk);
	strcat(value,"'");

        sprintf(sql_cmd,"INSERT INTO QUESTIONS(%s) VALUE(%s)",champs,value);
        mysql_query(&mysql,sql_cmd);
        res = mysql_store_result(&mysql);
	if((long) mysql_affected_rows(&mysql) == 0) //cas d erreur
           	printf("aucune information inserees\n");
        else if((long) mysql_affected_rows(&mysql) == -1)
                printf("erreur lors de l'insersion\n");
        else
                printf("insersion effectuee avec succes\n");

        mysql_free_result(res);

}

void insert_employe(){
	char value[520]="'";
	char name[255]="";
	int id;
	int error;
	char tmp[10]="";
	char table_name[255]="";
	char champs[520]="";
	char row_gen[255]="";

	clean_stdin();

	//ajout nom
	do{
		error=0;
		printf("Entrez le nom de l'employe\n");
		my_fgets(name,255);
		if(strlen(name) == 0 || strstr(name,"'")){
			printf("veuiller saisir une valeur sans apostrophe ou non vide\n");
			error=1;
		}
	}while(error ==1);
	strcat(value,name);
	strcat(value,"',");

	//ajout prenom
	do{
		error=0;
		printf("Entrez le prenom de l'employe\n");
		my_fgets(name,255);
		if(strlen(name) == 0 || strstr(name,"'")){
                        printf("veuiller saisir une valeur sans apostrophe ou non vide\n");
                        error=1;
                }

	}while(error==1);
	strcat(value,"'");
        strcat(value,name);
        strcat(value,"',");

	char sql_cmd[2000];
        sprintf(sql_cmd,"DESC EMPLOYE");
        mysql_query(&mysql,sql_cmd);
        MYSQL_RES * res = mysql_store_result(&mysql);
        row = mysql_fetch_row(res);
	for(int i=0;i<3;i++){
	row = mysql_fetch_row(res);
	strcat(champs,row[0]);
	strcat(champs,",");
	}

	//supprimer le champs image
	champs[strlen(champs)-6]= '\0';

        while((row = mysql_fetch_row(res))){
		strcat(champs,row[0]);
		strcat(champs,",");
		strcpy(table_name,row[0]+3);


	printf("\n");
	printf("Entrez l'ID de l'element que vous voulez selectionnée pour : %s\n",table_name);
	char sql_cmd[2000];
        sprintf(sql_cmd,"DESC %s",table_name);
        mysql_query(&mysql,sql_cmd);
        MYSQL_RES * res = mysql_store_result(&mysql);
        row = mysql_fetch_row(res);
        printf("ID  |");
        while((row = mysql_fetch_row(res))){
		printf("%s |",row[0]);
	}
        mysql_free_result(res);
	sprintf(sql_cmd,"select * from %s",table_name);
        mysql_query(&mysql,sql_cmd);
        res = mysql_store_result(&mysql);

        while((row = mysql_fetch_row(res))){
		printf("\n");
		for (int i=0 ; i < mysql_num_fields(res); i++)
			printf("%s |", row[i]);
	}

      mysql_free_result(res);
		printf("\n");
	do{
		error=0;
		scanf("%d",&id);
			sprintf(sql_cmd,"select * from %s where id=%d",table_name,id);
        		mysql_query(&mysql,sql_cmd);
		        res = mysql_store_result(&mysql);
        		row = mysql_fetch_row(res);
			if((long) mysql_affected_rows(&mysql) == 0){ //cas d erreur
				printf("id selectionne non existant\n");
				error=1;
			}
        		else if((long) mysql_affected_rows(&mysql) == -1){
                		printf("erreur lors de la saisie\n");
				error=1;
		}
	}while(error == 1);

	sprintf(tmp,"%d",id);
	strcat(value,"'");
	strcat(value,tmp);
	strcat(value,"'");
	strcat(value,",");


}
	champs[strlen(champs)-1]= '\0'; //enlever la derniere virgule
	value[strlen(value)-1]= '\0'; //enlever la derniere virgule

	sprintf(sql_cmd,"INSERT INTO EMPLOYE(%s) VALUE(%s)",champs,value);
        mysql_query(&mysql,sql_cmd);
        res = mysql_store_result(&mysql);
        if((long) mysql_affected_rows(&mysql) == 0) //cas d erreur
                printf("aucune information inserees\n");
        else if((long) mysql_affected_rows(&mysql) == -1)
                printf("erreur lors de l'insersion\n");
        else
                printf("insersion effectuee avec succes\n");

	mysql_free_result(res);
}

void modify_element(char* name_table){
	int id;
	char champs[255] = "";
        char tmp[255] = "";
	char value[255] = "";

	printf("Entrez l'ID de l'element a modifier \n"); //ligne a modifier
        clean_stdin();
        scanf("%d",&id);

	printf("Voici le nom des lignes :\n");
        printf("Nom : | Type :\n");
	char sql_cmd[2000];
        sprintf(sql_cmd,"DESC %s",name_table);
        mysql_query(&mysql,sql_cmd);
        MYSQL_RES * res = mysql_store_result(&mysql);
        row = mysql_fetch_row(res);
        while((row = mysql_fetch_row(res)))
                printf("%s | %s\n",row[0], row[1]);
	mysql_free_result(res);

	printf("Entrez le nom de la ligne a modifier\n");
        clean_stdin();
	my_fgets(champs,255);

        printf("Entrez la nouvelle valeur\n");
        my_fgets(tmp,255);
        strcat(value,"'");
        strcat(value,tmp);
        strcat(value,"'");

        sql_cmd[2000];
        sprintf(sql_cmd,"UPDATE %s SET %s=%s where id=%d",name_table,champs,value,id);
        mysql_query(&mysql,sql_cmd);

        if((long) mysql_affected_rows(&mysql) == 0) //cas d'erreur
                printf("aucune information modifier\n");
        else if((long) mysql_affected_rows(&mysql) == -1)
                printf("erreur lors de la modification\n");
        else
              printf("modification effectuee avec succes\n");
}
