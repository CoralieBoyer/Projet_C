#include <stdio.h>
#include <mysql.h>
#include <string.h>


    MYSQL mysql;
    MYSQL_ROW row;

//prototype
void saisir(char* val,int size);
//void connect_bdd();//connexion bdd
void print_tables();//print list des tables de bdd
void print_table(char* table);//print donnee de la table select
int  delete_element(char* table,int id);//suppr element de table
void  insert_table(int tables);//choisir table ou ajouter element

void insert_age();
void insert_employe();
void insert_entreprise();
void insert_physique();
void insert_questions();
void insert_travail();
void insert_visage();

//void close_mysql();//free pointer

//func

	void saisir(char* val,int size){
		fflush(stdin);
		fgets(val,size,stdin);
		fflush(stdin);
	}



	//connexion bdd
/*	void connect_bdd(){
		mysql_init(&mysql);
   		// mysql_options(&mysql,MYSQL_READ_DEFAULT_GROUP,"your_prog_name");
    		if (!mysql_real_connect(&mysql,"localhost","usr","mdp","2vine_ki_C",0,NULL,0))
    		{
        		fprintf(stderr, "Failed to connect to database: Error: %s\n",
                	mysql_error(&mysql));
    		}
	}*/

	//print liste des tables de bdd
	void print_tables(){
		int count=1;

		mysql_query(&mysql,"SHOW TABLES");// permit to do sql query => &mysql is pointer who ref at our bdd
		MYSQL_RES * res = mysql_store_result(&mysql);//store result in res =>&mysql is pointer who ref at our bdd

    		while((row = mysql_fetch_row(res))) {
        		for (int i=0 ; i < mysql_num_fields(res); i++)
            			printf("\n \t\t %d) \t %s \n",count,row[i]);
	    			count++;
    		}//print result to the request

    		mysql_free_result(res);//emply the buffer
	}

	//print donnee de la table select
	void print_table(char* table){
		char sql_cmd[2000];
		sprintf(sql_cmd,"SELECT * FROM %s",table);
		mysql_query(&mysql,sql_cmd);
			MYSQL_RES * res = mysql_store_result(&mysql);
			printf("\nvoici les informations contenues dans la table\n");
    			while((row = mysql_fetch_row(res))) {
        			for (int i=0 ; i < mysql_num_fields(res); i++)
        		    		printf("%s\n",row[i]);
    			}
    		mysql_free_result(res);
	}

	/**delete element
	renvoie code d'erreur
	*@param1: nom de table
	*@param2: id de l'element a suppr
	**/
	int  delete_element(char* table,int id){
	int error;
	char sql_cmd[2000];
	sprintf(sql_cmd,"DELETE FROM %s WHERE id = %d",table,id);
	error=mysql_query(&mysql,sql_cmd);
	if(error != 0){
		return 1;
	}
	return 0;
	}

	/**choisir table ou ajouter element ==> renvoie vers fonc dedier a chaque table
	*@param1: nom de table
	**/
	void  insert_table(int tables){
		switch (tables){
			case 1:
				insert_age();
				break;
			case 2:
                                insert_employe();
                                break;
			case 3:
                                insert_entreprise();
                                break;
			case 4:
                                printf("impossible de modifier cette table");
                                break;
			case 5:
                                insert_physique();
                                break;
			case 6:
                                insert_questions();
                                break;
			case 7:
                                insert_travail();
                                break;
			case 8:
                                insert_visage();
                                break;
		};
	}

	void insert_age(){
        char sql_cmd[2000];
	int min;
	int max;

	printf("\nEntrez la tranche d'age");
	printf("\nage min: ");
	scanf("%d",&min);

	printf("\nage max: ");
        scanf("%d",&max);

        sprintf(sql_cmd,"INSERT INTO AGE(Age_min,Age_max) VALUES(%d,%d)",min,max);
        mysql_query(&mysql,sql_cmd);
        }

	void insert_employe(){
        /*char sql_cmd[2000];
        char name[100] = "2vine_ki_C";
        char link[100]= "link2vine_ki_C";

        sprintf(sql_cmd,"INSERT INTO ENTREPRISE (Nom,Lien) VALUES('%s','%s')",name,link);
        mysql_query(&mysql,sql_cmd);
*/      printf("ok employe");
        }



	//insert element dans entreprise
	void insert_entreprise(){
	char sql_cmd[2000];
	char name[100];
	char link[100];

	printf("Entrez le nom de l'entreprise: ");
	scanf(" ");
	saisir(name,100);

	printf("\nEntrez le lien de l'entreprise: ");
        fflush(stdin);
	//scanf("%s",link);
	saisir(link,100);

	sprintf(sql_cmd,"INSERT INTO ENTREPRISE (Nom,Lien) VALUES('%s','%s')",name,link);
	mysql_query(&mysql,sql_cmd);
	printf("ok entreprise\n");
	}

	void insert_physique(){
        /*char sql_cmd[2000];
        char name[100] = "2vine_ki_C";
        char link[100]= "link2vine_ki_C";

        sprintf(sql_cmd,"INSERT INTO ENTREPRISE (Nom,Lien) VALUES('%s','%s')",name,link);
        mysql_query(&mysql,sql_cmd);
*/      printf("ok physique\n");
        }

	void insert_questions(){
        /*char sql_cmd[2000];
        char name[100] = "2vine_ki_C";
        char link[100]= "link2vine_ki_C";

        sprintf(sql_cmd,"INSERT INTO ENTREPRISE (Nom,Lien) VALUES('%s','%s')",name,link);
        mysql_query(&mysql,sql_cmd);
*/      printf("ok questions");
        }

	void insert_travail(){
	char sql_cmd[2000];
	char domaine[100];
	printf("\nEntrez le metier: ");
	scanf("\n");
        saisir(domaine,100);
	
        sprintf(sql_cmd,"INSERT INTO TRAVAIL (Domaine) VALUES('%s')",domaine);
        mysql_query(&mysql,sql_cmd);
        }

	void insert_visage(){
        /*char sql_cmd[2000];
        char name[100] = "2vine_ki_C";
        char link[100]= "link2vine_ki_C";

        sprintf(sql_cmd,"INSERT INTO ENTREPRISE (Nom,Lien) VALUES('%s','%s')",name,link);
        mysql_query(&mysql,sql_cmd);
*/      printf("ok visage");
        }



/*	//fermer connexion
	void close_mysql(){
		mysql_close(&mysql);//free the pointer /close connect
	}*/

//structure
/*
Struct ENTREPRISE{
char name[200];
char lien[200];
};

*/
