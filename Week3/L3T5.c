/* 02022023 roopemyller 389129 L3T5*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define TARKISTETTAVA 'c'
#define MIN 32
#define MAX 127

int main (void){

    int siemenluvunAsettaminen();
    int montaMerkkia();
    char arvoMerkki();
    int tarkistaMerkki(char cMerkki);
    void tarkistaMerkkijono(char *mJono);

    int i, iSiemen, iMontaMerkkia;
    char mJono[30] = "", cMerkki;

    printf("Tämä ohjelma luo satunnaisia merkkijonoja.\n");
    iSiemen = siemenluvunAsettaminen();
    iMontaMerkkia = montaMerkkia();
    printf("\n");

    srand(iSiemen);

    for(i = 0; i < iMontaMerkkia; i++){
        int pituus = strlen(mJono);
        cMerkki = arvoMerkki();
        if (tarkistaMerkki(cMerkki)){
            mJono[pituus] = cMerkki;
            mJono[pituus + 1] = '\0';
        }
    }
    tarkistaMerkkijono(mJono);     
    printf("Generoitiin merkkijono '%s', jossa on %lu merkkiä.\n", mJono, strlen(mJono)); 
    printf("Kiitos ohjelman käytöstä.\n");
    return(0);
}

int siemenluvunAsettaminen(){
    /*Palauttaa kysyttävän siemenluvun
    TOIMII*/    
    int iLuku;
    printf("Anna satunnaisgeneraattorin siemenluku: ");
    scanf("%d", &iLuku);
    return(iLuku);
}

int montaMerkkia(){
    /*Palauttaa kysyttävän merkkien lkm
    TOIMII*/   
    int iLuku;
    printf("Anna arvottavien merkkien määrä: ");
    scanf("%d", &iLuku);
    return(iLuku);
}


char arvoMerkki(){
    /*Arpoo luvun ja sen perusteella merkin ja palauttaa sen
    TOIMII*/
    int iLuku = rand() % (MAX - MIN ) + MIN;
    char cMerkki = iLuku;   
    return cMerkki;
}

int tarkistaMerkki(char cMerkki){
    /*Tarkistaa onko merkki ok
    TOIMII*/
    if (isalnum(cMerkki) || isspace(cMerkki)){
        return(1);
    } 
    return(0);
}

void tarkistaMerkkijono(char *mJono){
    /*Tarkistaa onko merkkijonossa c kirjainta
    TOIMII*/
    if(strchr(mJono, TARKISTETTAVA) != NULL){
        printf("Merkkijonosta löydettiin merkki 'c'.\n");
    }else{
        printf("Merkkijonossa ei ollut merkkiä 'c'.\n");
    }
    return;
}

