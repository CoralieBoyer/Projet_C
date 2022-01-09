#include <mysql.h>
#include <stdio.h>
#include <string.h>

//  MYSQL mysql;
//  MYSQL_ROW row;


//proto
int connect_bdd();
void close_mysql();

//func

/* CONNEXION A LA BDD*/
int connect_bdd(){
                mysql_init(&mysql);
                // mysql_options(&mysql,MYSQL_READ_DEFAULT_GROUP,"your_prog_name");
                if (!mysql_real_connect(&mysql,dbValues[0],dbValues[1],dbValues[2],dbValues[3],0,NULL,0))
                {
                        fprintf(stderr, "Erreur de connexion à  la base de données. Code erreur: %s\n",
                        mysql_error(&mysql));
			return 1;
		}
}

/* FERMER LA CONNEXION */
void close_mysql(){
   mysql_close(&mysql);

}
