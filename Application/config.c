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

  /* NOM DE L'ENTREPRISE */



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
