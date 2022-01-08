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
void insert_element(char* name_table);

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
		my_fgets(name_table,10);
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

void insert_element(char* name_table){
	char** tmp;
	char champs[500] = "";
        char value[500] = "";
	int count=0;
	int i = 0;

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
        printf("\nInserez les informations que vous voulez ajouter (écrire NULL si vous ne voulez pas mettre quelque chose):\n");
	while((row = mysql_fetch_row(res))) { //ranger les noms des lignes + insertion par le user
		strcat(champs,row[0]); //noms des lignes
		strcat(champs,",");

		printf("%s : %s\n",row[0],row[1]); //affiche les noms et types des lignes

		tmp[i]=malloc(sizeof(char)*255); //valeurs a inserer
		my_fgets(tmp[i],255);
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
