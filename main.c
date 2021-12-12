#include <stdio.h>
#include <mysql.h>


int main(int argc, char** argv) {

    MYSQL mysql; //initiate structure MYSQL who is a pointer /sim to a malloc
    MYSQL_ROW row;//initiate structure MYSQL

   mysql_init(&mysql);

    //test connecion bdd (&pointer,host,user,pwd,name bdd,port,socket use,flag)
    if (!mysql_real_connect(&mysql,"localhost","usr","mdp","2vine_ki_C",0,NULL,0))
    {
        fprintf(stderr, "Failed to connect to database: Error: %s\n",
                mysql_error(&mysql));
    }

    mysql_query(&mysql,"INSERT INTO entreprise VALUE('ICAN',2)");

    mysql_query(&mysql,"SELECT * FROM entreprise");// permit to do sql query => &mysql is pointer who ref at our bdd
    MYSQL_RES * res = mysql_store_result(&mysql);//store result in res =>&mysql is pointer who ref at our bdd

    while((row = mysql_fetch_row(res))) {
        for (int i=0 ; i < mysql_num_fields(res); i++)
            printf("%s\n",row[i]);
    }//print result to the request


    mysql_free_result(res);//emply the buffer
    mysql_close(&mysql);//free the pointer /close connect
    void mysql_free_result(MYSQL_RES * result);//free memory

    return 0;
}
