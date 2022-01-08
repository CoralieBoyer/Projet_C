//prot
void createPdf();
void closePdf();
void addPdf(char * question, char * answer);

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

    //creation dossier
    struct stat st = {0};

    if (stat("./tests", &st) == -1) {
        mkdir("./tests", 0700); //id employe
    }

    //nommer fic
    strcpy (fname, "PDF/test"); //id max + 1 fichier + date
    strcat (fname, ".pdf");

    pdf = HPDF_New (error_handler, NULL);//voir si erreur lors de la recuperation des header
    if (!pdf) {
        printf ("error: cannot create PdfDoc object\n");
        return;
    }

    font = HPDF_GetFont (pdf, "Times-Roman", "WinAnsiEncoding");//ecrire en Times-Roman

    page = HPDF_AddPage (pdf);//ajouter page a doc

    //taile pdf
    HPDF_Page_SetWidth (page, 200);//(y)
    HPDF_Page_SetHeight (page, 500);//(x)

    //titre pdf
    HPDF_Page_BeginText (page);//creation zone de texte
    HPDF_Page_SetFontAndSize (page, font, 20);
    HPDF_Page_MoveTextPos (page,0, x);//position text (y,x)
    HPDF_Page_ShowText (page, "2VINE_KI_C");//text a afficher
    HPDF_Page_EndText (page);
}

void addPdf(char * question, char * answer){
    x-=20;
    //Question
    HPDF_Page_BeginText (page);//creation zone de texte
    HPDF_Page_SetFontAndSize (page, font, 10);
    HPDF_Page_MoveTextPos (page,0, x);//position text (y,x)
    HPDF_Page_ShowText (page, question);//text a afficher
    HPDF_Page_EndText (page);

    x-=10;
    //Reponse
    HPDF_Page_BeginText (page);//creation zone de texte
    HPDF_Page_SetFontAndSize (page, font, 10);
    HPDF_Page_MoveTextPos (page,0, x);//position text (y,x)
    HPDF_Page_ShowText (page, answer);//text a afficher
    HPDF_Page_EndText (page);


}

void closePdf(){
    encoding = HPDF_GetEncoder (pdf, "ISO8859-3");//specifie le type de l'encodeur =>ici on prend l'alphabet francais

    /* save the document to a file */
    HPDF_SaveToFile (pdf, fname);

    HPDF_Free (pdf);
}
