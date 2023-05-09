/* 20022023 roopemyller 389129 L6T1.c */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct merkki{
    int iNumero;
    char cMerkki;
    struct merkki *pSeuraava;
} MERKKI;

int main (void){

    MERKKI *pAlku = NULL, *pLoppu = NULL;
    MERKKI *pUusi, *ptr;
    int iLopeta = 0;
    char uusimerkki;
    char q = 'q';
    int i = 0;
    printf("Anna listan kirjaimet.\n");
    do{
        printf("Anna kirjain, q lopettaa: ");
        scanf("%c", &uusimerkki);
        
        if (uusimerkki == q){
            iLopeta++;
        }else{
            if ((pUusi = (MERKKI*)malloc(sizeof(MERKKI))) == NULL){
                perror("Muistin varaus epäonnistui");
                exit(0);
            }
            pUusi->iNumero = i; // i on ympärillä olevan silmukan askeltajan arvo
            pUusi->cMerkki = uusimerkki;
            pUusi->pSeuraava = NULL;
            // Uuden alkion lisääminen listaan viimeiseksi alkioksi
            if (pAlku == NULL) { // lista on tyhjä, joten tehdään ensimmäinen alkio
            pAlku = pUusi;
            pLoppu = pUusi;
            } else { // lista ei ole tyhjä, joten lisätään loppuun
            pLoppu->pSeuraava = pUusi;
            pLoppu = pUusi;
            }
        }
        getchar();
        i++;
    }while (iLopeta != 1);

    printf("Listassa on seuraavat kirjaimet:\n");
    ptr = pAlku;
    while (ptr != NULL) {
        printf("%c ", ptr->cMerkki);
        ptr = ptr->pSeuraava;
    }
    ptr = pAlku;
    while (ptr != NULL){
        pAlku = ptr->pSeuraava;
        free(ptr);
        ptr = pAlku;
    }

    printf("\n\nMuisti vapautettu.\n");
    printf("Kiitos ohjelman käytöstä.\n");
    return(0);
}