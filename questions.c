#include <mysql.h>
#include <string.h>
#include <stdio.h>
//#include "co_deco_sql.c"
#include <time.h>
#include <stdlib.h>

int* var_table;


//proto
void malloc_variable();
int describe_table();
void printf_question(char *phrase);
void free_variable();


//func

/* MALLOC DU TABLEAU CONTENANT LES REPETITIONS DE QUESTIONS */
void malloc_variable(){
	int count;

	count = describe_table();
	var_table = malloc(sizeof(int)*count);
	if(var_table != NULL){ //Si malloc reussi
	        for(int i=0;i<count;i++){ //initialiser les cases a 0
		        var_table[i]=0;
	        }
	}else
		printf("erreur");
}

/* RECUPERE LE NOMBRE DE CLES ETRANGERES DE LA TABLEAU QUESTION */
int describe_table(){
	int count=0;
	int result;

        mysql_query(&mysql,"desc QUESTIONS");
        MYSQL_RES * res = mysql_store_result(&mysql);

        while((row = mysql_fetch_row(res)))
		count++;

	result = count-2;

        mysql_free_result(res);

	return result;
}

/* RECUPERE UNE QUESTION RANDOM */
void printf_question(char *phrase){
	int id;
	int max;
	char sql_cmd[2000];
	int count;
	int i=3;
	//char question[255];

	//ID RANDOM
	srand(time(NULL));
	sprintf(sql_cmd,"SELECT MAX(ID) FROM QUESTIONS");
	mysql_query(&mysql,sql_cmd);
	MYSQL_RES * res = mysql_store_result(&mysql);
	while((row = mysql_fetch_row(res))) {
		max =*row[0]-'0';
	}
	mysql_free_result(res);

	//SELECT QUESTION DE L'ID RANDOM
	do{
		id = rand()%max+1;
		sprintf(sql_cmd,"SELECT * FROM QUESTIONS WHERE ID = %d",id);
		mysql_query(&mysql,sql_cmd);
		res = mysql_store_result(&mysql);
		row = mysql_fetch_row(res);
	}while(row == NULL);//refaire la requete si l'ID de la question n'existe pas

	strcpy(phrase,row[1]);

/* 	eviter la repetition de question si rep OUI
	while(i<mysql_num_fields(res)){
		if(row[i] != NULL && var_table[i-3] == 0){
			var_table[i-3] = 1;
			strcpy(question,row[1]);
		}
		i++;
	}
*/
	mysql_free_result(res);//Free de la requete de la question

}

/* FREE DU TABLEAU CONTENANT LES REPETITIONS DE QUESTIONS */
void free_variable(){
free(var_table);
}


/* FONCTION MAIN UTILISEE POUR LES TESTS */
/*int main(int argc,char** argv){
char question[255];

connect_bdd();
malloc_variable();
printf_question(question);
printf("question : %s\n",question);

free_variable();
close_mysql();
return 0;
}*/
