#include <mysql.h>
#include <stdio.h>
#include <string.h>

  MYSQL mysql;
  MYSQL_ROW row;


//proto
void connect_bdd();
void close_mysql();

//func

/* CONNEXION A LA BDD*/
void connect_bdd(){
                mysql_init(&mysql);
                // mysql_options(&mysql,MYSQL_READ_DEFAULT_GROUP,"your_prog_name");
                if (!mysql_real_connect(&mysql,"localhost","usr","mdp","2vine_ki_C",0,NULL,0))
                {
                        fprintf(stderr, "Failed to connect to database: Error: %s\n",
                        mysql_error(&mysql));
		}
}


/* FERMER LA CONNEXION */
void close_mysql(){
   mysql_close(&mysql);

}
