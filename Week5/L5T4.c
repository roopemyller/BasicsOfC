/* 15022023 roopemyller 389129 L5T4 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define VAKIO 30

typedef struct tiedot {
    char nimi[VAKIO];
    int summa;
}TIEDOT;

struct palautus{
    TIEDOT* pTaulukko;
    int iMonta;
};
typedef struct palautus Palautus;


int main (void){
    int valikko();
    void kysyTiedostonimi(char *pN, char kehote[VAKIO]);
    Palautus lueTiedosto(char *pN, TIEDOT* pTaulukko, int iMonta);
    void kirjoitaTiedosto(char *pN, Palautus p);

    int iValinta, iOnkoTiedosto = 0, iMonta = 0, iOnkoTietoja = 0;
    char aLuettava[VAKIO], aKirjoitettava[VAKIO], kehote[VAKIO];
    char *pL = aLuettava;
    char *pK = aKirjoitettava;

    int kierros = 0;
    Palautus p;
    TIEDOT* pTaulukko = NULL;

    do{
        iValinta = valikko();
        switch (iValinta){
        case 1: ;
            /*Lue tiedosto
            taulukko sekä iMonta molemmat pitää saada palaamaan takaisin*/
            strcpy(kehote, "luettavan");
            kysyTiedostonimi(pL, kehote);
            iOnkoTiedosto++;
            p = lueTiedosto(pL, pTaulukko, iMonta);  
            break;
        case 2: ;
            /*Laske merkkijonojen summa*/
            if (iOnkoTiedosto == 0){
                printf("\nEi analysoitavaa, lue tiedosto ennen analyysia.\n\n");
                break;
            }
            printf("\nSummat laskettu %d merkkijonolle.\n\n", p.iMonta);
            iOnkoTietoja++;
            break;
        case 3: ;
            /*Kirjoita tiedosto*/  
            if (iOnkoTietoja == 0){
                printf("\nEi kirjoitettavia tietoja, analysoi tiedot ennen tallennusta.\n\n");
                break;
            }
            strcpy(kehote, "kirjoitettavan");
            kysyTiedostonimi(pK, kehote);
            printf("Tiedostoon kirjoitetaan seuraavat arvot:\n");
            kirjoitaTiedosto(pK, p);
            break;
        case 0: ;
            free(pTaulukko);
            pTaulukko = NULL;
            printf("\nMuisti vapautettu.\n");
            printf("Lopetetaan.\n");
            break;
        default:
            break;
        }

    }while (iValinta != 0);
    printf("\nKiitos ohjelman käytöstä.\n");
    return(0);
}

int valikko(){
    int iValinta;
    printf("Valitse haluamasi toiminto:\n");
    printf("1) Lue tiedosto\n");
    printf("2) Laske merkkijonojen summa\n");
    printf("3) Kirjoita tiedosto\n");
    printf("0) Lopeta\n");
    printf("Anna valintasi: ");
    scanf("%d", &iValinta);
    return(iValinta);
}

void kysyTiedostonimi(char *pN, char kehote[VAKIO]){
    printf("\nAnna %s tiedoston nimi: ", kehote);
    scanf("%s", pN);
    return;
}

Palautus lueTiedosto(char *pN, TIEDOT* pTaulukko, int iMonta){
    TIEDOT *muistinvaraus(TIEDOT *pTaulukko, int iMonta);
    int laskeSumma(char mJono[VAKIO]);

    Palautus p;

    char aRivi[VAKIO];
    FILE* T;
    if ((T = fopen(pN, "r")) == NULL) {
        perror("Tiedoston avaaminen epäonnistui, lopetetaan");
        exit(0);
    }

    while (fgets(aRivi, VAKIO, T) != NULL){
        aRivi[strlen(aRivi)-1] = '\0';  
        pTaulukko = muistinvaraus(pTaulukko, iMonta);
        strcpy(pTaulukko[iMonta].nimi, aRivi);
        pTaulukko[iMonta].summa = laskeSumma(aRivi);
        iMonta++;
    }
    fclose(T);
    printf("Tiedosto '%s' luettu.\n\n", pN);
    p.pTaulukko = pTaulukko;
    p.iMonta = iMonta;
    return p;
}

TIEDOT *muistinvaraus(TIEDOT *pTaulukko, int iMonta){
    if ((pTaulukko = (TIEDOT*)realloc(pTaulukko, (iMonta + 1) * sizeof(TIEDOT))) == NULL ){
        perror("Muistin varaus epäonnistui");
        exit(1);
    }
    return pTaulukko;
}

int laskeSumma(char mJono[VAKIO]){
    int a = 0;
    int iSumma = 0;
    while (a < strlen(mJono)){
        int cMerkkiArvo = mJono[a];
        iSumma = iSumma + cMerkkiArvo;
        a++;
    }
    return(iSumma);
}

void kirjoitaTiedosto(char *pN, Palautus p){
    FILE* T;
    if ((T = fopen(pN, "w")) == NULL) {
        perror("\nTiedoston avaaminen epäonnistui, lopetetaan");
        exit(0);
    }
    fprintf(T, "Nimi;Arvo\n");
    printf("Nimi;Arvo\n");
    int i = 0;
    while (i < p.iMonta){
        printf("%s;%d\n", p.pTaulukko[i].nimi, p.pTaulukko[i].summa);
        fprintf(T, "%s;%d\n", p.pTaulukko[i].nimi, p.pTaulukko[i].summa);
        i++;
    }
    fclose(T);
    printf("Tiedosto '%s' kirjoitettu.\n\n", pN);
    return;
}