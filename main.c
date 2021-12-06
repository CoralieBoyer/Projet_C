#include <stdio.h>
#include <mysql.h>


int main(int argc, char** argv) {

    MYSQL mysql;
    MYSQL_ROW row;

    mysql_init(&mysql);
   // mysql_options(&mysql,MYSQL_READ_DEFAULT_GROUP,"your_prog_name");
    if (!mysql_real_connect(&mysql,"localhost","usr","mdp","2vine_ki_C",0,NULL,0))
    {
        fprintf(stderr, "Failed to connect to database: Error: %s\n",
                mysql_error(&mysql));
    }

    mysql_query(&mysql,"SELECT * FROM entreprise");
	MYSQL_RES * res = mysql_store_result(&mysql);

    while((row = mysql_fetch_row(res))) {
        for (int i=0 ; i < mysql_num_fields(res); i++) 
            printf("%s\n",row[i]);
    }


    mysql_free_result(res);
    mysql_close(&mysql);

    return 0;
}
