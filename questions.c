#include <mysql.h>
#include <string.h>
#include <stdio.h>
#include "co_deco_sql.c"
#include <time.h>
#include <stdlib.h>

//proto
int describe_table();
void answerRequest();
void printf_question();

//func
void answerRequest(){ //Recupere la personne pensée par le joueur
int count;
int* var_table;

connect_bdd();

count = describe_table();

var_table = malloc(sizeof(int)*count);
if(var_table != NULL){
	for(int i=0;i<count;i++){
	var_table[i]=0;
	}
	printf_question();
	free(var_table);

}else
printf("erreur");




close_mysql();
}

int describe_table(){
int count=0;
                mysql_query(&mysql,"desc QUESTIONS");
                MYSQL_RES * res = mysql_store_result(&mysql);

                while((row = mysql_fetch_row(res)))
				count++;

		return count-2;

                mysql_free_result(res);

}

void printf_question(){
int id;
int max;
char sql_cmd[2000];

srand(time(NULL));
sprintf(sql_cmd,"SELECT MAX(ID) FROM QUESTIONS");
mysql_query(&mysql,sql_cmd);
 MYSQL_RES * res = mysql_store_result(&mysql);
while((row = mysql_fetch_row(res))) {
max =*row[0]-'0';
  printf("%d\n",max);
 }
mysql_free_result(res);

max +=1;
printf("%d\n",max);
id = rand()%max;
printf("%d\n",id);
/*
sprintf(sql_cmd,"SELECT Phrase FROM QUESTIONS WHERE ID = %d",id);
mysql_query(&mysql,sql_cmd);
res = mysql_store_result(&mysql);
row = mysql_fetch_row(res);
printf("%s\n",row[0]);
mysql_free_result(res);*/
}

int main(int argc,char** argv){

answerRequest();

return 0;
}
