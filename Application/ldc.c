void backOffice(){
//var
char name_table[10];
char next;
int error;

printf("Bienvenue dans le menu de modification \n");
printf("Ici, vous pouvez ajouter/modifier/supprimer une information \n");

printf("Voici les TABLES que vous pouvez modifier\n");
printf_tables();

	choose_table(name_table);//renvoie le nom de la table select
	scanf("%c",&next);
	if(next == 'n'){
		do{
			printf("Voulez-vous quitter (q) ou choisir une nouvelle table (c): ");
			clean_stdin();
			scanf("%c",&next);
		}while(next != 'q' && next != 'c');

        	if(next == 'c'){
            		choose_table(name_table);
			clean_stdin();
		}
	}
	else if(next == 'o'){
		clean_stdin();
		printf("Voulez-vous ajouter (a),modifier (m) ou supprimer (s) un element ?: ");
		scanf("%c",&next);
		switch (next){
			case 'a':
				func_insert_element(name_table);
				break;
			case 'm':
				modify_element(name_table);
				break;
			case 's':
                        	delete_element(name_table);
                        	break;
			default://c pas encore quoi faire
                        	printf("erreur \n");
                        	break;
		}
	}
}
