/* 20022023 roopemyller 389129 L6T2.c */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define VAKIO 30

typedef struct tehtava{
    char aTehtava[VAKIO];
    int iLkm;
    struct tehtava *pSeuraava;
} MERKKI;

int main (void){
    void kysyTiedostonimi(char *pN);
    MERKKI *lueTiedosto(char *pN, MERKKI *pAlku);
    void tulostaTiedot(MERKKI *pAlku);
    MERKKI *vapautaMuisti(MERKKI *pAlku);

    MERKKI *pAlku = NULL;
    
    char pNimi[VAKIO];
    char *pN = pNimi;

    kysyTiedostonimi(pN);
    pAlku = lueTiedosto(pN, pAlku);
    tulostaTiedot(pAlku);
    pAlku = vapautaMuisti(pAlku);

    printf("Kiitos ohjelman käytöstä.\n");
    return(0);
}

void kysyTiedostonimi(char *pN){
    printf("Anna luettavan tiedoston nimi: ");
    scanf("%s", pN);
    return;
}

MERKKI *lueTiedosto(char *pN, MERKKI *pAlku){
    MERKKI *muistinvaraus(MERKKI *pUusi);

    char aRivi[VAKIO], *p1, *p2;

    FILE* T;
    if ((T = fopen(pN, "r")) == NULL) {
        perror("Tiedoston avaaminen epäonnistui, lopetetaan");
        exit(0);
    }
    while (fgets(aRivi, VAKIO, T) != NULL){
        aRivi[strlen(aRivi)-1] = '\0';  
        if ((p1 = strtok(aRivi, ";")) == NULL) {
            printf("Merkkijonon '%s' pilkkominen epäonnistui.\n", aRivi);
            exit(1);
        }
        if ((p2 = strtok(NULL, "\n")) == NULL) {
            printf("Merkkijonon '%s' pilkkominen epäonnistui.\n", aRivi);
            exit(1);
        }
        MERKKI *pUusi, *ptr;

        pUusi = muistinvaraus(pUusi);

        pUusi->iLkm = atoi(p2);
        strcpy(pUusi->aTehtava, p1);
        pUusi->pSeuraava = NULL;

        if (pAlku == NULL) {
            pAlku = pUusi;
        } else {
            ptr = pAlku;
            while (ptr->pSeuraava != NULL)
                ptr = ptr->pSeuraava;
            ptr->pSeuraava = pUusi;
        }
    }
    fclose(T);
    printf("Tiedosto '%s' luettu linkitettyyn listaan.\n", pN);
    return(pAlku);
}

MERKKI *muistinvaraus(MERKKI *pUusi){
    if ((pUusi = (MERKKI*)malloc(sizeof(MERKKI))) == NULL){
        perror("Muistin varaus epäonnistui");
        exit(0);
    }
    return pUusi;
}

void tulostaTiedot(MERKKI *pAlku){
    printf("Tehtäviä tehtiin seuraavasti:\n");
    MERKKI *ptr = pAlku;
    while (ptr != NULL) {
        printf("Tehtävän %s teki %d opiskelijaa.\n", ptr->aTehtava, ptr->iLkm);
        ptr = ptr->pSeuraava;
    }
    return;
}

MERKKI *vapautaMuisti(MERKKI *pAlku){
    MERKKI *ptr = pAlku;
    while (ptr != NULL){
        pAlku = ptr->pSeuraava;
        free(ptr);
        ptr = pAlku;
    }
    printf("\nMuisti vapautettu.\n");
    return(pAlku);
}