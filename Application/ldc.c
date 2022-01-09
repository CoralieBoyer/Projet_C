void backOffice(){
//var
char name_table[10];
char next;
int error;

printf("Bienvenue dans le menu de modification \n");
printf("Ici, vous pouvez ajouter/modifier/supprimer une information \n");

printf("Voici les TABLES que vous pouvez modifier\n");
printf_tables();
clean_stdin();
printf("Ou vous pouvez creer une nouvelle TABLE pour rajouter des informations\n");
clean_stdin();
do{
printf("Voulez-vous modifier une TABLE deja existante (m) ou en creer une nouvelle (a): ");
scanf("%c",&next);
if(next == 'm' || next == 'a')
	break;
}while(next != 'm' || next !='a');

if(next == 'm'){
	clean_stdin();
	choose_table(name_table);//renvoie le nom de la table select
	scanf("%c",&next);
	if(next == 'n'){
		do{
			printf("Voulez-vous quitter (q) ou choisir une nouvelle table (c): ");
			clean_stdin();
			scanf("%c",&next);
			if(next == 'q')
                        	return;
			if(next == 'c')
				break;
		}while(next != 'q' || next != 'c');

        if(next == 'c'){
            clean_stdin();
            choose_table(name_table);}//a countinuer
	}
	else if(next == 'o'){
		clean_stdin();
		printf("Voulez-vous ajouter (a),modifier (m) ou supprimer (s) un element ?: ");
		scanf("%c",&next);
		//clean_stdin();
		switch (next){
			case 'a':
				insert_element(name_table);
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
else if(next =='a'){
	printf("ajout de table \n");
}
}
