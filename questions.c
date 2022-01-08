#include <mysql.h>
#include <string.h>
#include <stdio.h>
//#include "co_deco_sql.c"
#include <time.h>
#include <stdlib.h>

//liste chainee
/*typedef struct Item {
    int value;
    struct Item * next;
} IdQuestion;
*/

//var
char* var_table;
int i;
int id;
int boolean;
char id_fk[25]="";
char where[1000]="";
char id_element[5]="";
//IdQuestion *start = NULL;


//proto
void malloc_variable();
int describe_table();
void printf_question(char *phrase);
void free_variable();
IdQuestion * addId(int newValue, IdQuestion *pStart);
void searchId(IdQuestion *pStart);
void requete();

//pointeur func
//void (*pSearchId)(IdQuestion *);
//void * pSearchId = searchId;


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

void perdu(){
printf("ok");
}

/* RECUPERE UNE QUESTION RANDOM */
void printf_question(char *phrase){
	int max;
	char sql_cmd[2000];
	int count;
	char question[255];


	//ID RANDOM
	srand(time(NULL));
	sprintf(sql_cmd,"SELECT MAX(ID)FROM QUESTIONS");
	mysql_query(&mysql,sql_cmd);
	MYSQL_RES * res = mysql_store_result(&mysql);
	while((row = mysql_fetch_row(res))) {
		max =*row[0]-'0';
	}
	mysql_free_result(res);

	//SELECT QUESTION DE L'ID RANDOM
	do{
		do{
			id = rand()%max+1;
			sprintf(sql_cmd,"SELECT * FROM QUESTIONS WHERE ID = %d",id);
			mysql_query(&mysql,sql_cmd);
			res = mysql_store_result(&mysql);
			row = mysql_fetch_row(res);
		}while(row == NULL);//refaire la requete si l'ID de la question n'existe pas

		i = 3; //i[0]->ID / i[1]->phrase / i[2]->ID_employe
		strcpy(question,row[1]);
		while(row[i] == NULL && i<mysql_num_fields(res))
			++i;
		strcpy(id_element,row[i]);
		mysql_free_result(res);//Free de la requete de la question
		i-=3;
		searchId(start);
	}while(var_table[i] != 0 || boolean == 0);//Refaire la requete si une question a deja ete pose
	strcpy(phrase,question);
}

/* SI REP OUI */
void response_yes(){
		switch (i+3){
                        case 3:
				strcpy(id_fk,"ID_TRAVAIL");
                                break;
                        case 4:
				strcpy(id_fk,"ID_SEXE");
                                break;
                        case 5:
				strcpy(id_fk,"ID_YEUX");
                                break;
                        case 6:
				strcpy(id_fk,"ID_CHEVEUX");
                                break;
                        case 7:
				strcpy(id_fk,"ID_AGE");
                                break;
                        case 8:
				strcpy(id_fk,"ID_TAILLE");
                                break;
                        case 9:
				strcpy(id_fk,"ID_PILOSITE");
                                break;
                };

	printf("%s\n",id_fk);
	requete();
	*(var_table+i)+=1;
}

void requete(){
char sql_cmd[2000];
//printf("%s\n",id_element);
			if(strlen(where)!=0){
			strcat(where,"AND");
			}
			strcat(where,id_fk);
			strcat(where,"=");
			strcat(where,id_element);
			sprintf(sql_cmd,"SELECT * FROM EMPLOYE where %s",where);
                        mysql_query(&mysql,sql_cmd);
                        MYSQL_RES *res = mysql_store_result(&mysql);
			if((long) mysql_affected_rows(&mysql) > 0)
			{
				while((row = mysql_fetch_row(res))) {
					printf("%s\n",row[1]);
                		}
			}

}

/* SI REP NON*/
IdQuestion * response_no(IdQuestion *pStart) {
    IdQuestion *tmp;
    tmp = malloc(sizeof(IdQuestion));
    tmp->value = id;
    tmp->next = pStart;
    return tmp;
}

/* EVITE LA REPETITION DES QUESTIONS QUAND NON */
void searchId(IdQuestion *pStart) {
    IdQuestion *tmp;
    tmp = pStart;
    boolean = 1;
    while(tmp != NULL) {
        if(tmp->value == id)
                boolean = 0;
        tmp = tmp->next;
    }
}

/* VIDE LES REPETITIONS DE QUESTIONS QUAND NON*/
IdQuestion * deleteIds(IdQuestion *pStart) {
    while(pStart != NULL){
    IdQuestion *tmp = pStart->next;
    free(pStart);
    pStart = tmp;
    }
    return pStart; // ou return tmp;
}

/* FREE DU TABLEAU CONTENANT LES REPETITIONS DE QUESTIONS OUI*/
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
response_yes();
//start = response_no(start);

//printIds(start);
free(start);

free_variable();
close_mysql();
return 0;
}

*/
