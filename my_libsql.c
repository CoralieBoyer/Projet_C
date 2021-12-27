#include <string.h>
#include <mysql.h>
#include <stdlib.h>
#include <stdio.h>

MYSQL mysql;
MYSQL_ROW row;

//prototype
void printf_tables();


//func

//print les TABLES de la bdd
void printf_tables(){
	int count=1;

        mysql_query(&mysql,"SHOW TABLES");// permit to do sql query => &mysql is pointer who ref at our bdd
        MYSQL_RES * res = mysql_store_result(&mysql);//store result in res =>&mysql is pointer who ref at our bdd

        while((row = mysql_fetch_row(res))) {
         for (int i=0 ; i < mysql_num_fields(res); i++)
            printf("\t %d) %s\n",count,row[i]);
            count++;
          }//print result to the request

         mysql_free_result(res);//emply the buffer
}
