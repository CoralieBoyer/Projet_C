#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <setjmp.h>
#include "hpdf.h"

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

int main(int argc, char **argv)
{
    HPDF_Doc  pdf;
    char fname[256];
    HPDF_Page page;
    HPDF_Font font;
    HPDF_Encoder encoding;
	float x=480;

    //nommer fic
    strcpy (fname, argv[0]);
    strcat (fname, ".pdf");

    pdf = HPDF_New (error_handler, NULL);//voir si erreur lors de la recuperation des header
    if (!pdf) {
        printf ("error: cannot create PdfDoc object\n");
        return 1;
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

    x-=20;
    //titre pdf
    HPDF_Page_BeginText (page);//creation zone de texte
    HPDF_Page_SetFontAndSize (page, font, 10);
    HPDF_Page_MoveTextPos (page,0, x);//position text (y,x)
    HPDF_Page_ShowText (page, "Test");//text a afficher
    HPDF_Page_EndText (page);



    encoding = HPDF_GetEncoder (pdf, "ISO8859-3");//specifie le type de l'encodeur =>ici on prend l'alphabet francais

    /* save the document to a file */
    HPDF_SaveToFile (pdf, fname);

    HPDF_Free (pdf);
}
