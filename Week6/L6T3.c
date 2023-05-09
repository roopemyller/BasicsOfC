/* 21022023 roopemyller 389129 L6T3*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define VAKIO 30

typedef struct lasku {
    int luku1;
    int luku2;
    int summa;
    struct lasku *pSeuraava;
}LASKU;

int main(int argc, char *argv[]){
    int valikko();
    void kysyTiedostonimi(char *pN, char kehote[VAKIO]);
    LASKU *lisaaLukuun(int *iL, LASKU *pLasku);
    void kirjoitaTiedostoon(char pNimi[VAKIO], LASKU *pAlku);
    LASKU *lueTiedosto(char pNimi[VAKIO], LASKU *pAlku);
    LASKU *vapautaMuisti(LASKU *pAlku);

    if (argc < 2){
        printf("Et antanut tarpeeksi parametreja.\n");
        return(0);
    }else if (argc > 2){
        printf("Annoit liikaa parametreja.\n");
        return(0);
    }

    LASKU *pAlku = NULL;

    int iLuku, iValinta, iOnkoTietoja = 0;
    int *iL = &iLuku;
    char pNimi[VAKIO], kehote[VAKIO];
    char *pN = pNimi;

    iLuku = atoi(argv[1]);
    
    printf("Annoit luvun %d.", iLuku);
    do {
        iValinta = valikko();
        switch (iValinta) {
        case 1:
            pAlku = lisaaLukuun(iL, pAlku);
            iOnkoTietoja++;
            break;
        case 2: ;
            if(iOnkoTietoja == 0){
                printf("\nEi kirjoitettavia tietoja.\n");
                
            }else{
                strcpy(kehote, "kirjoitettavan");
                kysyTiedostonimi(pN, kehote);
                kirjoitaTiedostoon(pNimi, pAlku);            
            }
            break;
        case 3:
            strcpy(kehote, "luettavan");
            kysyTiedostonimi(pN, kehote);
            pAlku = lueTiedosto(pNimi, pAlku);            
            break;
        case 0:
            pAlku = vapautaMuisti(pAlku);
            printf("Lopetetaan.\n\n");
            break;
        default:
            printf("\nTuntematon valinta, yritä uudestaan.\n");
            break;
        }
    } while (iValinta != 0);
    
    printf("Kiitos ohjelman käytöstä.\n");
    return(0);
}

void kysyTiedostonimi(char *pN, char kehote[VAKIO]){
    printf("\nAnna %s tiedoston nimi: ", kehote);
    scanf("%s", pN);
    return;
}

int valikko() {
    int iValinta;
    printf("\nValitse haluamasi toiminto:\n1) Lisää lukuun\n2) Kirjoita historia tiedostoon\n3) Lue historia tiedostosta\n0) Lopeta\nAnna valintasi: ");
    scanf("%d", &iValinta);
    getchar();
    return iValinta;
}

LASKU *lisaaLukuun(int *iL, LASKU *pAlku){
    LASKU *muistinvaraus(LASKU *pUusi);

    LASKU *pUusi, *ptr;
    int lisattavaLuku;
    printf("\nAnna lukuun lisättävä kokonaisluku: ");
    scanf("%d", &lisattavaLuku);

    pUusi = muistinvaraus(pUusi);

    pUusi->luku1 = *iL;
    pUusi->luku2 = lisattavaLuku;
    pUusi->summa = (*iL + lisattavaLuku);
    pUusi->pSeuraava = NULL;
    
    printf("%d+%d=%d\n", pUusi->luku1, pUusi->luku2, pUusi->summa);


    *iL = (pUusi->summa);
    
    if (pAlku == NULL) {
        pAlku = pUusi;
    } else {
        ptr = pAlku;
        while (ptr->pSeuraava != NULL)
        ptr = ptr->pSeuraava;
        ptr->pSeuraava = pUusi;
    }
    
    return(pAlku);
}

LASKU *muistinvaraus(LASKU *pUusi){
    if ((pUusi = (LASKU*)malloc(sizeof(LASKU))) == NULL){
        perror("Muistin varaus epäonnistui");
        exit(0);
    }
    return pUusi;
}

void kirjoitaTiedostoon(char pNimi[VAKIO], LASKU *pAlku){
    LASKU *ptr = pAlku;
    while (ptr != NULL) {
        printf("%d+%d=%d\n", ptr->luku1, ptr->luku2, ptr->summa);
        ptr = ptr->pSeuraava;
    }

    FILE* T;
    if ((T = fopen(pNimi, "a")) == NULL) {
        perror("\nTiedoston avaaminen epäonnistui, lopetetaan");
        exit(0);
    }

    ptr = pAlku;
    while (ptr != NULL) {
        fprintf(T, "%d+%d=%d\n", ptr->luku1, ptr->luku2, ptr->summa);
        ptr = ptr->pSeuraava;
    }
    fclose(T);
    printf("\nTiedosto '%s' kirjoitettu.\n", pNimi);
    return;
}

LASKU *lueTiedosto(char pNimi[VAKIO], LASKU *pAlku){
    LASKU *muistinvaraus(LASKU *pUusi);

    char aRivi[VAKIO], *p1, *p2, *p3;    
    FILE* T;
    if ((T = fopen(pNimi, "r")) == NULL) {
        perror("Tiedoston avaaminen epäonnistui, lopetetaan");
        exit(0);
    }
    
    printf("Tiedostossa oleva laskuhistoria:\n");
    while (fgets(aRivi, VAKIO, T) != NULL){
        printf("%s", aRivi);
        aRivi[strlen(aRivi)-1] = '\0';  
        if ((p1 = strtok(aRivi, "+")) == NULL) {
            printf("Merkkijonon '%s' pilkkominen epäonnistui.\n", aRivi);
            exit(1);
        }
        if ((p2 = strtok(NULL, "=")) == NULL) {
            printf("Merkkijonon '%s' pilkkominen epäonnistui.\n", aRivi);
            exit(1);
        }
        if ((p3 = strtok(NULL, "\n")) == NULL) {
            printf("Merkkijonon '%s' pilkkominen epäonnistui.\n", aRivi);
            exit(1);
        }

        LASKU *pUusi, *ptr;

        pUusi = muistinvaraus(pUusi);

        pUusi->luku1 = atoi(p1);
        pUusi->luku2 = atoi(p2);
        pUusi->summa = atoi(p3);
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
    printf("Tiedosto '%s' luettu ja tulostettu.\n", pNimi);
    return(pAlku);
}

LASKU *vapautaMuisti(LASKU *pAlku){
    LASKU *ptr = pAlku;
    while (ptr != NULL){
        pAlku = ptr->pSeuraava;
        free(ptr);
        ptr = pAlku;
    }
    printf("\nMuisti vapautettu.\n");
    return(pAlku);
}