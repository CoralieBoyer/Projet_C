 --CREATE DATABASE 2vine_ki_C;
 --USE 2vine_ki_C;
 --CREATE USER 'usr'@'localhost' IDENTIFIED BY 'mdp';
 --GRANT ALL PRIVILEGES ON * . * TO 'usr'@'localhost';
 --FLUSH PRIVILEGES;

CREATE TABLE ENTREPRISE(  ID INTEGER  AUTO_INCREMENT,  Nom VARCHAR(255), Lien VARCHAR(255), PRIMARY KEY (ID));

CREATE TABLE TRAVAIL( ID INTEGER AUTO_INCREMENT, Domaine VARCHAR(255),PRIMARY KEY (ID));

CREATE TABLE SEXE( ID INTEGER AUTO_INCREMENT, Genre VARCHAR(255), PRIMARY KEY (ID));

CREATE TABLE YEUX(ID INTEGER AUTO_INCREMENT,  Couleur VARCHAR(255),  PRIMARY KEY (ID));

CREATE TABLE CHEVEUX( ID INTEGER AUTO_INCREMENT,  Taille VARCHAR(255),  Couleur VARCHAR(255),  PRIMARY KEY (ID));

CREATE TABLE AGE(  ID INTEGER AUTO_INCREMENT,  Age_min INTEGER,  Age_max INTEGER, PRIMARY KEY (ID));

CREATE TABLE TAILLE(  ID INTEGER AUTO_INCREMENT,  Taille_min INTEGER,  Taille_max INTEGER, PRIMARY KEY (ID));

CREATE TABLE PILOSITE(  ID INTEGER AUTO_INCREMENT,  Barbe BOOLEAN,  Moustache BOOLEAN,  Taille VARCHAR(255),  Couleur VARCHAR(255),  PRIMARY KEY (ID));

CREATE TABLE EMPLOYE(  ID INTEGER AUTO_INCREMENT,  Nom VARCHAR(255),  Prenom VARCHAR(255),  Image VARCHAR(255),  ID_ENTREPRISE INTEGER,  ID_TRAVAIL INTEGER,  ID_SEXE INTEGER,  ID_YEUX INTEGER,  ID_CHEVEUX INTEGER,  ID_AGE INTEGER,  ID_TAILLE INTEGER,  ID_PILOSITE INTEGER,PRIMARY KEY (ID));

CREATE TABLE QUESTIONS(  ID INTEGER AUTO_INCREMENT,  Phrase VARCHAR(255), ID_EMPLOYE INTEGER,  ID_TRAVAIL INTEGER,  ID_SEXE INTEGER,  ID_YEUX INTEGER,  ID_CHEVEUX INTEGER,  ID_AGE INTEGER,  ID_TAILLE INTEGER,  ID_PILOSITE INTEGER,PRIMARY KEY (ID));


ALTER TABLE EMPLOYE ADD FOREIGN KEY (ID_ENTREPRISE) REFERENCES ENTREPRISE(ID);
ALTER TABLE EMPLOYE ADD FOREIGN KEY (ID_TRAVAIL) REFERENCES TRAVAIL(ID);
ALTER TABLE EMPLOYE ADD FOREIGN KEY (ID_SEXE) REFERENCES SEXE(ID);
ALTER TABLE EMPLOYE ADD FOREIGN KEY (ID_YEUX) REFERENCES YEUX(ID);
ALTER TABLE EMPLOYE ADD FOREIGN KEY (ID_CHEVEUX) REFERENCES CHEVEUX(ID);
ALTER TABLE EMPLOYE ADD FOREIGN KEY (ID_AGE) REFERENCES AGE(ID);
ALTER TABLE EMPLOYE ADD FOREIGN KEY (ID_TAILLE) REFERENCES TAILLE(ID);
ALTER TABLE EMPLOYE ADD FOREIGN KEY (ID_PILOSITE) REFERENCES PILOSITE(ID);

ALTER TABLE QUESTIONS ADD FOREIGN KEY (ID_EMPLOYE) REFERENCES EMPLOYE(ID);
ALTER TABLE QUESTIONS ADD FOREIGN KEY (ID_TRAVAIL) REFERENCES TRAVAIL(ID);
ALTER TABLE QUESTIONS ADD FOREIGN KEY (ID_SEXE) REFERENCES SEXE(ID);
ALTER TABLE QUESTIONS ADD FOREIGN KEY (ID_YEUX) REFERENCES YEUX(ID);
ALTER TABLE QUESTIONS ADD FOREIGN KEY (ID_CHEVEUX) REFERENCES CHEVEUX(ID);
ALTER TABLE QUESTIONS ADD FOREIGN KEY (ID_AGE) REFERENCES AGE(ID);
ALTER TABLE QUESTIONS ADD FOREIGN KEY (ID_TAILLE) REFERENCES TAILLE(ID);
ALTER TABLE QUESTIONS ADD FOREIGN KEY (ID_PILOSITE) REFERENCES PILOSITE(ID);

ALTER TABLE FICHIER ADD FOREIGN KEY (ID_EMPLOYE) REFERENCES EMPLOYE(ID);



INSERT INTO ENTREPRISE (Nom,Lien) VALUES("ESGI", "https://www.esgi.fr/");
INSERT INTO ENTREPRISE (Nom,Lien) VALUES("ICAN", "https://www.ican-design.fr");

INSERT INTO TRAVAIL (Domaine) VALUES("Professeur");
INSERT INTO TRAVAIL (Domaine) VALUES("Eleve");
INSERT INTO TRAVAIL (Domaine) VALUES("Administratif");

INSERT INTO SEXE (Genre) VALUES("H");
INSERT INTO SEXE (Genre) VALUES("F");
INSERT INTO SEXE (Genre) VALUES("A");

INSERT INTO YEUX (Couleur) VALUES("Marron");
INSERT INTO YEUX (Couleur) VALUES("Bleu");
INSERT INTO YEUX (Couleur) VALUES("Vert");

INSERT INTO CHEVEUX (Couleur,Taille) VALUES("Brun", "courts");
INSERT INTO CHEVEUX (Couleur,Taille) VALUES("Brun", "Long");
INSERT INTO CHEVEUX (Couleur,Taille) VALUES("Brun", "Mi-long");
INSERT INTO CHEVEUX (Couleur,Taille) VALUES("Brun", "Carre");
INSERT INTO CHEVEUX (Couleur,Taille) VALUES("Blond", "courts");
INSERT INTO CHEVEUX (Couleur,Taille) VALUES("Blond", "Long");
INSERT INTO CHEVEUX (Couleur,Taille) VALUES("Blond", "Mi-long");
INSERT INTO CHEVEUX (Couleur,Taille) VALUES("Blond", "Carre");
INSERT INTO CHEVEUX (Couleur,Taille) VALUES("Chatain", "courts");
INSERT INTO CHEVEUX (Couleur,Taille) VALUES("Chatain", "Long");
INSERT INTO CHEVEUX (Couleur,Taille) VALUES("Chatain", "Mi-long");
INSERT INTO CHEVEUX (Couleur,Taille) VALUES("Chatain", "Carre");
INSERT INTO CHEVEUX (Couleur,Taille) VALUES("Noir", "courts");
INSERT INTO CHEVEUX (Couleur,Taille) VALUES("Noir", "Long");
INSERT INTO CHEVEUX (Couleur,Taille) VALUES("Noir", "Mi-long");
INSERT INTO CHEVEUX (Couleur,Taille) VALUES("Noir", "Carre");
INSERT INTO CHEVEUX (Couleur,Taille) VALUES("Blanc", "courts");
INSERT INTO CHEVEUX (Couleur,Taille) VALUES("Blanc", "Long");
INSERT INTO CHEVEUX (Couleur,Taille) VALUES("Blanc", "Mi-long");
INSERT INTO CHEVEUX (Couleur,Taille) VALUES("Blanc", "Carre");
INSERT INTO CHEVEUX (Couleur,Taille) VALUES("Colore", "courts");
INSERT INTO CHEVEUX (Couleur,Taille) VALUES("Colore", "Long");
INSERT INTO CHEVEUX (Couleur,Taille) VALUES("Colore", "Mi-long");
INSERT INTO CHEVEUX (Couleur,Taille) VALUES("Colore", "Carre");
INSERT INTO CHEVEUX (Couleur,Taille) VALUES("Aucun", "Chauve");

INSERT INTO AGE (Age_min, Age_max) VALUES(15,20);
INSERT INTO AGE (Age_min, Age_max) VALUES(20,25);
INSERT INTO AGE (Age_min, Age_max) VALUES(25,30);
INSERT INTO AGE (Age_min, Age_max) VALUES(30,35);
INSERT INTO AGE (Age_min, Age_max) VALUES(35,40);
INSERT INTO AGE (Age_min, Age_max) VALUES(40,45);
INSERT INTO AGE (Age_min, Age_max) VALUES(45,50);
INSERT INTO AGE (Age_min, Age_max) VALUES(50,55);
INSERT INTO AGE (Age_min, Age_max) VALUES(55,60);
INSERT INTO AGE (Age_min, Age_max) VALUES(60,65);
INSERT INTO AGE (Age_min, Age_max) VALUES(65,70);

INSERT INTO TAILLE (Taille_min, Taille_max) VALUES(120,130);
INSERT INTO TAILLE (Taille_min, Taille_max) VALUES(130,140);
INSERT INTO TAILLE (Taille_min, Taille_max) VALUES(140,150);
INSERT INTO TAILLE (Taille_min, Taille_max) VALUES(150,160);
INSERT INTO TAILLE (Taille_min, Taille_max) VALUES(160,170);
INSERT INTO TAILLE (Taille_min, Taille_max) VALUES(170,180);
INSERT INTO TAILLE (Taille_min, Taille_max) VALUES(180,190);
INSERT INTO TAILLE (Taille_min, Taille_max) VALUES(190,200);


INSERT INTO PILOSITE (Barbe,Moustache,Taille,Couleur) VALUES(0, 1, 'Petit', 'Noir');
INSERT INTO PILOSITE (Barbe,Moustache,Taille,Couleur) VALUES(0, 1, 'Moyen', 'Noir');
INSERT INTO PILOSITE (Barbe,Moustache,Taille,Couleur) VALUES(0, 1, 'Grand', 'Noir');
INSERT INTO PILOSITE (Barbe,Moustache,Taille,Couleur) VALUES(1, 0, 'Petit', 'Noir');
INSERT INTO PILOSITE (Barbe,Moustache,Taille,Couleur) VALUES(1, 0, 'Moyen', 'Noir');
INSERT INTO PILOSITE (Barbe,Moustache,Taille,Couleur) VALUES(1, 0, 'Grand', 'Noir');
INSERT INTO PILOSITE (Barbe,Moustache,Taille,Couleur) VALUES(1, 1, 'Petit', 'Noir');
INSERT INTO PILOSITE (Barbe,Moustache,Taille,Couleur) VALUES(1, 1, 'Moyen', 'Noir');
INSERT INTO PILOSITE (Barbe,Moustache,Taille,Couleur) VALUES(1, 1, 'Grand', 'Noir');
INSERT INTO PILOSITE (Barbe,Moustache,Taille,Couleur) VALUES(0, 1, 'Petit', 'Blond');
INSERT INTO PILOSITE (Barbe,Moustache,Taille,Couleur) VALUES(0, 1, 'Moyen', 'Blond');
INSERT INTO PILOSITE (Barbe,Moustache,Taille,Couleur) VALUES(0, 1, 'Grand', 'Blond');
INSERT INTO PILOSITE (Barbe,Moustache,Taille,Couleur) VALUES(1, 0, 'Petit', 'Blond');
INSERT INTO PILOSITE (Barbe,Moustache,Taille,Couleur) VALUES(1, 0, 'Moyen', 'Blond');
INSERT INTO PILOSITE (Barbe,Moustache,Taille,Couleur) VALUES(1, 0, 'Grand', 'Blond');
INSERT INTO PILOSITE (Barbe,Moustache,Taille,Couleur) VALUES(1, 1, 'Petit', 'Blond');
INSERT INTO PILOSITE (Barbe,Moustache,Taille,Couleur) VALUES(1, 1, 'Moyen', 'Blond');
INSERT INTO PILOSITE (Barbe,Moustache,Taille,Couleur) VALUES(1, 1, 'Grand', 'Blond');
INSERT INTO PILOSITE (Barbe,Moustache,Taille,Couleur) VALUES(0, 0, 'Aucun', 'Aucun');

INSERT INTO QUESTIONS (Phrase,ID_TAILLE) VALUES('Est-ce que la personne fait entre 1m20 et 1m30 ?', 1);
INSERT INTO QUESTIONS (Phrase,ID_TAILLE) VALUES('Est-ce que la personne fait entre 1m30 et 1m40 ?', 2);
INSERT INTO QUESTIONS (Phrase,ID_TAILLE) VALUES('Est-ce que la personne fait entre 1m40 et 1m50 ?', 3);
INSERT INTO QUESTIONS (Phrase,ID_TAILLE) VALUES('Est-ce que la personne fait entre 1m50 et 1m60 ?', 4);
INSERT INTO QUESTIONS (Phrase,ID_TAILLE) VALUES('Est-ce que la personne fait entre 1m60 et 1m70 ?', 5);
INSERT INTO QUESTIONS (Phrase,ID_TAILLE) VALUES('Est-ce que la personne fait entre 1m70 et 1m80 ?', 6);
INSERT INTO QUESTIONS (Phrase,ID_TAILLE) VALUES('Est-ce que la personne fait entre 1m90 et 2m ?', 7);

INSERT INTO QUESTIONS (Phrase,ID_AGE) VALUES('Est-ce que la personne a entre 15 et 20 ans ?', 1);
INSERT INTO QUESTIONS (Phrase,ID_AGE) VALUES('Est-ce que la personne a entre 20 et 25 ans ?', 2);
INSERT INTO QUESTIONS (Phrase,ID_AGE) VALUES('Est-ce que la personne a entre 25 et 30 ans ?', 3);
INSERT INTO QUESTIONS (Phrase,ID_AGE) VALUES('Est-ce que la personne a entre 30 et 35 ans ?', 4);
INSERT INTO QUESTIONS (Phrase,ID_AGE) VALUES('Est-ce que la personne a entre 35 et 40 ans ?', 5);
INSERT INTO QUESTIONS (Phrase,ID_AGE) VALUES('Est-ce que la personne a entre 40 et 45 ans ?', 6);
INSERT INTO QUESTIONS (Phrase,ID_AGE) VALUES('Est-ce que la personne a entre 45 et 50 ans ?', 7);
INSERT INTO QUESTIONS (Phrase,ID_AGE) VALUES('Est-ce que la personne a entre 50 et 55 ans ?', 8);
INSERT INTO QUESTIONS (Phrase,ID_AGE) VALUES('Est-ce que la personne a entre 55 et 60 ans ?', 9);
INSERT INTO QUESTIONS (Phrase,ID_AGE) VALUES('Est-ce que la personne a entre 60 et 65 ans ?', 10);
INSERT INTO QUESTIONS (Phrase,ID_AGE) VALUES('Est-ce que la personne a entre 65 et 70 ans ?', 11);


INSERT INTO QUESTIONS (Phrase,ID_CHEVEUX) VALUES('Est-ce que la personne a des cheveux brun courts ?', 1);
INSERT INTO QUESTIONS (Phrase,ID_CHEVEUX) VALUES('Est-ce que la personne a des cheveux brun long ?', 2);
INSERT INTO QUESTIONS (Phrase,ID_CHEVEUX) VALUES('Est-ce que la personne a des cheveux brun mi-long ?', 3);
INSERT INTO QUESTIONS (Phrase,ID_CHEVEUX) VALUES('Est-ce que la personne a un carre brun ?', 4);
INSERT INTO QUESTIONS (Phrase,ID_CHEVEUX) VALUES('Est-ce que la personne a des cheveux blond courts ?', 5);
INSERT INTO QUESTIONS (Phrase,ID_CHEVEUX) VALUES('Est-ce que la personne a des cheveux blond long ?', 6);
INSERT INTO QUESTIONS (Phrase,ID_CHEVEUX) VALUES('Est-ce que la personne a des cheveux blond mi-long ?', 7);
INSERT INTO QUESTIONS (Phrase,ID_CHEVEUX) VALUES('Est-ce que la personne a un carre blond ?', 8);
INSERT INTO QUESTIONS (Phrase,ID_CHEVEUX) VALUES('Est-ce que la personne a des cheveux chatain courts ?', 9);
INSERT INTO QUESTIONS (Phrase,ID_CHEVEUX) VALUES('Est-ce que la personne a des cheveux chatain long ?', 10);
INSERT INTO QUESTIONS (Phrase,ID_CHEVEUX) VALUES('Est-ce que la personne a des cheveux chatain mi-long ?', 11);
INSERT INTO QUESTIONS (Phrase,ID_CHEVEUX) VALUES('Est-ce que la personne a un carre chatain ?', 12);
INSERT INTO QUESTIONS (Phrase,ID_CHEVEUX) VALUES('Est-ce que la personne a des cheveux noir courts ?', 13);
INSERT INTO QUESTIONS (Phrase,ID_CHEVEUX) VALUES('Est-ce que la personne a des cheveux noir long ?', 14);
INSERT INTO QUESTIONS (Phrase,ID_CHEVEUX) VALUES('Est-ce que la personne a des cheveux noir mi-long ?', 15);
INSERT INTO QUESTIONS (Phrase,ID_CHEVEUX) VALUES('Est-ce que la personne a un carre noir ?', 16);
INSERT INTO QUESTIONS (Phrase,ID_CHEVEUX) VALUES('Est-ce que la personne a des cheveux blanc courts ?', 17);
INSERT INTO QUESTIONS (Phrase,ID_CHEVEUX) VALUES('Est-ce que la personne a des cheveux blanc long ?', 18);
INSERT INTO QUESTIONS (Phrase,ID_CHEVEUX) VALUES('Est-ce que la personne a des cheveux blanc mi-long ?', 19);
INSERT INTO QUESTIONS (Phrase,ID_CHEVEUX) VALUES('Est-ce que la personne a un carre blanc ?', 20);
INSERT INTO QUESTIONS (Phrase,ID_CHEVEUX) VALUES('Est-ce que la personne a des cheveux colore courts ?', 21);
INSERT INTO QUESTIONS (Phrase,ID_CHEVEUX) VALUES('Est-ce que la personne a des cheveux colore long ?', 22);
INSERT INTO QUESTIONS (Phrase,ID_CHEVEUX) VALUES('Est-ce que la personne a des cheveux colore mi-long ?', 23);
INSERT INTO QUESTIONS (Phrase,ID_CHEVEUX) VALUES('Est-ce que la personne a un carre colore ?', 24);
INSERT INTO QUESTIONS (Phrase,ID_CHEVEUX) VALUES('Est-ce que la personne et chauve ?', 25);


INSERT INTO QUESTIONS (Phrase,ID_PILOSITE) VALUES('Est-ce que la personne n a pas de barbe mais une petite moustache noires ?', 1);
INSERT INTO QUESTIONS (Phrase,ID_PILOSITE) VALUES('Est-ce que la personne n a pas de barbe mais une taille moyenne moustache noires ?', 2);
INSERT INTO QUESTIONS (Phrase,ID_PILOSITE) VALUES('Est-ce que la personne n a pas de barbe mais une grande moustache noires ?', 3);
INSERT INTO QUESTIONS (Phrase,ID_PILOSITE) VALUES('Est-ce que la personne n a pas de moustache mais une petite barbe noires ?', 4);
INSERT INTO QUESTIONS (Phrase,ID_PILOSITE) VALUES('Est-ce que la personne n a pas de moustache mais une taille moyenne barbe noires ?', 5);
INSERT INTO QUESTIONS (Phrase,ID_PILOSITE) VALUES('Est-ce que la personne n a pas de moustache mais une grande barbe noires ?', 6);
INSERT INTO QUESTIONS (Phrase,ID_PILOSITE) VALUES('Est-ce que la personne  a une petite moustache et une petite barbe noires ?', 7);
INSERT INTO QUESTIONS (Phrase,ID_PILOSITE) VALUES('Est-ce que la personne  a une moyenne moustache et une moyenne barbe noires ?', 8);
INSERT INTO QUESTIONS (Phrase,ID_PILOSITE) VALUES('Est-ce que la personne  a une grande moustache et une grande barbe noires ?', 9);
INSERT INTO QUESTIONS (Phrase,ID_PILOSITE) VALUES('Est-ce que la personne n a pas de barbe mais une petite moustache blondes ?', 10);
INSERT INTO QUESTIONS (Phrase,ID_PILOSITE) VALUES('Est-ce que la personne n a pas de barbe mais une taille moyenne moustache blondes ?', 11);
INSERT INTO QUESTIONS (Phrase,ID_PILOSITE) VALUES('Est-ce que la personne n a pas de barbe mais une grande moustache blondes ?', 12);
INSERT INTO QUESTIONS (Phrase,ID_PILOSITE) VALUES('Est-ce que la personne n a pas de moustache mais une petite barbe blondes ?', 13);
INSERT INTO QUESTIONS (Phrase,ID_PILOSITE) VALUES('Est-ce que la personne n a pas de moustache mais une taille moyenne barbe blondes ?', 14);
INSERT INTO QUESTIONS (Phrase,ID_PILOSITE) VALUES('Est-ce que la personne n a pas de moustache mais une grande barbe blondes ?', 15);
INSERT INTO QUESTIONS (Phrase,ID_PILOSITE) VALUES('Est-ce que la personne  a une petite moustache et une petite barbe blondes ?', 16);
INSERT INTO QUESTIONS (Phrase,ID_PILOSITE) VALUES('Est-ce que la personne  a une moyenne moustache et une moyenne barbe blondes ?', 17);
INSERT INTO QUESTIONS (Phrase,ID_PILOSITE) VALUES('Est-ce que la personne  a une grande moustache et une grande barbe blondes ?', 18);
INSERT INTO QUESTIONS (Phrase,ID_PILOSITE) VALUES('Est-ce que la personne   n a pas moustache ni de barbe ?', 19);

INSERT INTO QUESTIONS (Phrase,ID_YEUX) VALUES('Est-ce que la personne a des yeux marrons ?', 1);
INSERT INTO QUESTIONS (Phrase,ID_YEUX) VALUES('Est-ce que la personne a des yeux bleus ?', 2);
INSERT INTO QUESTIONS (Phrase,ID_YEUX) VALUES('Est-ce que la personne a des yeux verts ?', 3);

INSERT INTO QUESTIONS (Phrase,ID_SEXE) VALUES('Est-ce que la personne est un homme ?', 1);
INSERT INTO QUESTIONS (Phrase,ID_SEXE) VALUES('Est-ce que la personne est une femme ?', 2);
INSERT INTO QUESTIONS (Phrase,ID_SEXE) VALUES('Est-ce que la personne se considere n appartenir a aucun genre ?', 3);

INSERT INTO QUESTIONS (Phrase,ID_TRAVAIL) VALUES('Est-ce que la personne est un professeur ?', 1);
INSERT INTO QUESTIONS (Phrase,ID_TRAVAIL) VALUES('Est-ce que la personne est un eleve ?', 2);
INSERT INTO QUESTIONS (Phrase,ID_TRAVAIL) VALUES('Est-ce que la personne est un personnel administratif ?', 3);


INSERT INTO EMPLOYE (Nom,Prenom,ID_ENTREPRISE,ID_TRAVAIL,ID_SEXE,ID_YEUX,ID_CHEVEUX,ID_AGE,ID_TAILLE,ID_PILOSITE) VALUES("Degard", "Annaelle",1,2,2,1,14,1,3,19);
INSERT INTO EMPLOYE (Nom,Prenom,ID_ENTREPRISE,ID_TRAVAIL,ID_SEXE,ID_YEUX,ID_AGE,ID_TAILLE,ID_PILOSITE) VALUES("Boyer", "Coralie",1,2,2,1,1,4,19);
INSERT INTO EMPLOYE (Nom,Prenom,ID_ENTREPRISE,ID_TRAVAIL,ID_SEXE,ID_YEUX,ID_CHEVEUX,ID_AGE,ID_TAILLE,ID_PILOSITE) VALUES("Sananes", "Frederique",1,2,1,1,13,6,5,19);
