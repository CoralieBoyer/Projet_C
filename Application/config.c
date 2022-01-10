int configFunc(){
  config_t cfg;
  config_setting_t *setting;
  const char *str;

  config_init(&cfg);

  /* LECTURE FICHIER + RETURN SI ERREUR */
  if(! config_read_file(&cfg, "app.cfg")){
    fprintf(stderr, "%s:%d - %s\n", config_error_file(&cfg), config_error_line(&cfg), config_error_text(&cfg));
    config_destroy(&cfg);
    return 0;
  }

  /* NOM DE L'APPLICATION */
  if(config_lookup_string(&cfg, "name", &str))
      strcpy(appName,str);
    else
      return 0;

  /* NOM DE L'ENTREPRISE */
  if(config_lookup_string(&cfg, "entreprise", &str))
      strcpy(entrepriseName,str);
    else
      return 0;

  /*BASE DE DONNEES */
  for (int i = 0; i < 4; i++){
    strcpy(path,"");
    strcat(path,"database.");
    strcat(path,database[i]);
    if(config_lookup_string(&cfg, path, &str))
      strcpy(dbValues[i],str);
    else
      return 0;
  }
return 2;
}

int configLink(){
  char sql_cmd[2000];

  sprintf(sql_cmd,"SELECT Lien FROM ENTREPRISE WHERE Nom = '%s'", entrepriseName);
  mysql_query(&mysql,sql_cmd);
  MYSQL_RES * res = mysql_store_result(&mysql);
  row = mysql_fetch_row(res);

  if((long) mysql_affected_rows(&mysql) == -1 || (long) mysql_affected_rows(&mysql) == 0)
    return -1;
  else
    strcpy(entrepriseLink,row[0]);

return 2;
}
