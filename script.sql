-- CREATE DATABASE 2vine_ki_C;
-- CREATE USER 'usr'@'localhost' IDENTIFIED BY 'mdp';
-- GRANT ALL PRIVILEGES ON * . * TO 'usr'@'localhost';
-- FLUSH PRIVILEGES;

CREATE TABLE ENTREPRISE(  ID INTEGER  AUTO_INCREMENT,  Nom VARCHAR(255),PRIMARY KEY (ID));

CREATE TABLE TRAVAIL( ID INTEGER AUTO_INCREMENT, Domaine VARCHAR(255),  Image VARCHAR(255),PRIMARY KEY (ID));

CREATE TABLE SEXE( ID INTEGER AUTO_INCREMENT, Genre VARCHAR(255), Image VARCHAR(255),PRIMARY KEY (ID));

CREATE TABLE YEUX(ID INTEGER AUTO_INCREMENT,  Couleur VARCHAR(255),  Image VARCHAR(255),PRIMARY KEY (ID));

CREATE TABLE CHEVEUX( ID INTEGER AUTO_INCREMENT,  Taille VARCHAR(255),  Couleur VARCHAR(255),  Image VARCHAR(255),PRIMARY KEY (ID));

CREATE TABLE AGE(  ID INTEGER AUTO_INCREMENT,  Age_min INTEGER,  Age_max INTEGER,  Image VARCHAR(255),PRIMARY KEY (ID));

CREATE TABLE TAILLE(  ID INTEGER AUTO_INCREMENT,  Taille_min INTEGER,  Taille_max INTEGER,  Image VARCHAR(255),PRIMARY KEY (ID));

CREATE TABLE PILOSITE(  ID INTEGER AUTO_INCREMENT,  Barbe BOOLEAN,  Moustache BOOLEAN,  Taille VARCHAR(255),  Couleur VARCHAR(255),  Image VARCHAR(255),PRIMARY KEY (ID));

CREATE TABLE EMPLOYE(  ID INTEGER AUTO_INCREMENT,  Nom VARCHAR(255),  Prenom VARCHAR(255),  Image VARCHAR(255),  ID_ENTREPRISE INTEGER,  ID_TRAVAIL INTEGER,  ID_SEXE INTEGER,  ID_YEUX INTEGER,  ID_CHEVEUX INTEGER,  ID_AGE INTEGER,  ID_TAILLE INTEGER,  ID_PILOSITE INTEGER,PRIMARY KEY (ID));

CREATE TABLE QUESTIONS(  ID INTEGER AUTO_INCREMENT,  Nom VARCHAR(255),  Prenom VARCHAR(255),  Image VARCHAR(255),  ID_EMPLOYE INTEGER,  ID_TRAVAIL INTEGER,  ID_SEXE INTEGER,  ID_YEUX INTEGER,  ID_CHEVEUX INTEGER,  ID_AGE INTEGER,  ID_TAILLE INTEGER,  ID_PILOSITE INTEGER,PRIMARY KEY (ID));

CREATE TABLE FICHIER(  ID INTEGER AUTO_INCREMENT,  Nom VARCHAR(255),  Date_modif DATE,  ID_EMPLOYE INTEGER,PRIMARY KEY (ID));


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
