//prot
void createPdf();
void closePdf();
void addPdf(char * question, char * answer);
void createPagePdf();

//func
void createPdf(){
#ifdef HPDF_DLL
void  __stdcall
#else
void
#endif
error_handler  (HPDF_STATUS   error_no,
                HPDF_STATUS   detail_no,
                void         *user_data)
{
    printf ("ERROR: error_no=%04X, detail_no=%u\n", (HPDF_UINT)error_no,
                (HPDF_UINT)detail_no);
}

/* CREATION DU DOSSIER */
    struct stat st = {0};
    if (stat(directory, &st) == -1) {
	mkdir(directory, 0700); //id employe
    }

/* NOMMER LE FICHIER */
    //recup date
    recoverDate();

    strcpy (fname, directory);
    strcat (fname,"/fic-");
    strcat (fname, date);
    strcat (fname, ".pdf");

    pdf = HPDF_New (error_handler, NULL);//voir si erreur lors de la recuperation des header
    if (!pdf) {
        printf ("error: cannot create PdfDoc object\n");
        return;
    }

    font = HPDF_GetFont (pdf, "Times-Roman", "WinAnsiEncoding");//ecrire en Times-Roman

    createPagePdf();

/* HAUT DE PAGE */
    //titre
    HPDF_Page_BeginText (page);//creation zone de texte
    HPDF_Page_SetFontAndSize (page, font, 20);
    HPDF_Page_MoveTextPos (page,100, x);//position text (y,x)
    HPDF_Page_ShowText (page, "2VINE_KI_C");//text a afficher
    HPDF_Page_EndText (page);

    //date
    x-=20;
    char tmp[255];
    strcpy(tmp,"Date : ");
    strncat(tmp,date,10);
    strcat (tmp, "\0");
    HPDF_Page_BeginText (page);//creation zone de texte
    HPDF_Page_SetFontAndSize (page, font, 10);
    HPDF_Page_MoveTextPos (page,220, x);//position text (y,x)
    HPDF_Page_ShowText (page, tmp);//text a afficher
    HPDF_Page_EndText (page);



    strcpy(tmp,"Joueur : ");
    strcat(tmp, userFirstName);
    strcat(tmp, " ");
    strcat(tmp, userName);
    HPDF_Page_BeginText (page);//creation zone de texte
    HPDF_Page_SetFontAndSize (page, font, 10);
    HPDF_Page_MoveTextPos (page,0, x);//position text (y,x)
    HPDF_Page_ShowText (page, tmp);//text a afficher
    HPDF_Page_EndText (page);

    x-=10;
}

void createPagePdf(){
/* CREATION DE LA PAGE */
    page = HPDF_AddPage (pdf);//ajouter page a doc

/* PARAMETRES DE LA PAGE */
    //Initialisation de x
    x=480;

    //taile de la page
    HPDF_Page_SetWidth (page, 300);//(y)
    HPDF_Page_SetHeight (page, 500);//(x)

}

void addPdf(char * question, char * answer){
    x-=20; //position du texte
    if(x-10 <= 0)
      createPagePdf();

    //Question
    HPDF_Page_BeginText (page);//creation zone de texte
    HPDF_Page_SetFontAndSize (page, font, 10);
    HPDF_Page_MoveTextPos (page,0, x);//position text (y,x)
    HPDF_Page_ShowText (page, question);//text a afficher
    HPDF_Page_EndText (page);

    x-=10; //position du texte
    //Reponse
    HPDF_Page_BeginText (page);//creation zone de texte
    HPDF_Page_SetFontAndSize (page, font, 10);
    HPDF_Page_MoveTextPos (page,0, x);//position text (y,x)
    HPDF_Page_ShowText (page, answer);//text a afficher
    HPDF_Page_EndText (page);


}

void closePdf(char *answer){
    char tmp[255];

    x-=30; //position du texte
    if(x-25 <= 0)
       createPagePdf();

    //Question
    HPDF_Page_BeginText (page);//creation zone de texte
    HPDF_Page_SetFontAndSize (page, font, 10);
    HPDF_Page_MoveTextPos (page,100, x);//position text (y,x)
    HPDF_Page_ShowText (page, "La personne a ete trouvee ?");//text a afficher
    HPDF_Page_EndText (page);

    x-=10; //position du texte
    //Reponse
    HPDF_Page_BeginText (page);//creation zone de texte
    HPDF_Page_SetFontAndSize (page, font, 10);
    HPDF_Page_MoveTextPos (page,150, x);//position text (y,x)
    HPDF_Page_ShowText (page, answer);//text a afficher
    HPDF_Page_EndText (page);

    if(answer == "oui"){

      strcpy(tmp,"Reponse : ");
      strcat(tmp, name);
      x-=15;
      HPDF_Page_BeginText (page);//creation zone de texte
      HPDF_Page_SetFontAndSize (page, font, 10);
      HPDF_Page_MoveTextPos (page,0, x);//position text (y,x)
      HPDF_Page_ShowText (page, tmp);//text a afficher
      HPDF_Page_EndText (page);
    }

    encoding = HPDF_GetEncoder (pdf, "ISO8859-3");//specifie le type de l'encodeur =>ici on prend l'alphabet francais

    /* save the document to a file */
      HPDF_SaveToFile (pdf, fname);

    HPDF_Free (pdf);
}
