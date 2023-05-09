/* 22022023 roopemyller 389129 L6T4.c */
#define _XOPEN_SOURCE 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define VAKIO 30

typedef struct tieto {
    char aika[VAKIO];
    float arvo;
    struct tieto *pSeuraava;
}TIETO;

int main (void){
    int valikko();
    void kysyTiedostonimi(char *pN, char kehote[VAKIO]);
    TIETO *lueTiedosto(char *pN, TIETO *pAlku);
    TIETO *analysoi(TIETO *pAlku);
    void kirjoitaTiedosto(char pNimi[VAKIO], TIETO *pAlku);
    TIETO *tyhjenna(TIETO *pAlku);

    int iValinta, analysoitu = 0;
    char pNimi[VAKIO], kehote[VAKIO];
    char *pN = pNimi;

    TIETO *pAlku = NULL;

    do {
        iValinta = valikko();
        switch (iValinta) {
        case 1:
            // Lue tiedosto
            strcpy(kehote, "luettavan");
            kysyTiedostonimi(pN, kehote);
            pAlku = lueTiedosto(pN, pAlku);
            break;
        case 2: ;
            // Analysoi
            if (pAlku != NULL){
                pAlku = analysoi(pAlku);
                analysoitu++;
            }else{
                printf("\nEi analysoitavia tietoja, lue tiedot ensin.\n\n");
            }
            break;
        case 3:
            // Kirjoita tiedosto     
            if (analysoitu != 0){
                strcpy(kehote, "kirjoitettavan");
                kysyTiedostonimi(pN, kehote);
                kirjoitaTiedosto(pN, pAlku);
            }else{
                printf("\nEi kirjoitettavia tietoja, analysoi tiedot ensin.\n\n");
            }

            break;
        case 0:
            pAlku = tyhjenna(pAlku);
            printf("\nMuisti vapautettu.\n");
            printf("Lopetetaan.\n\n");
            break;
        default:
            printf("\nTuntematon valinta, yritä uudestaan.\n\n");
            break;
        }
    } while (iValinta != 0);
    
    printf("Kiitos ohjelman käytöstä.\n");
    return(0);
}

int valikko() {
    int iValinta;
    printf("Valitse haluamasi toiminto:\n1) Lue tiedosto\n2) Analysoi\n3) Kirjoita tiedosto\n0) Lopeta\nAnna valintasi: ");
    scanf("%d", &iValinta);
    getchar();
    return iValinta;
}

void kysyTiedostonimi(char *pN, char kehote[VAKIO]){
    printf("\nAnna %s tiedoston nimi: ", kehote);
    scanf("%s", pN);
    return;
}

TIETO *lueTiedosto(char *pN, TIETO *pAlku){
    TIETO *muistinvaraus(TIETO *pUusi);

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

        TIETO *pUusi, *ptr;

        pUusi = muistinvaraus(pUusi);
        strcpy(pUusi->aika, p1);
        pUusi->arvo = atof(p2);
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
    printf("Tiedosto '%s' luettu linkitettyyn listaan.\n\n", pN);
    return(pAlku);
}

TIETO *muistinvaraus(TIETO *pUusi){
    if ((pUusi = (TIETO*)malloc(sizeof(TIETO))) == NULL){
        perror("Muistin varaus epäonnistui");
        exit(0);
    }
    return pUusi;
}

TIETO *analysoi(TIETO *pAlku){
    // Lasketaan lämpötilojen keskiarvot eri kuukausille.
    TIETO *tyhjenna(TIETO *pAlku);
    char* itoa(int val, int base);

    TIETO *ptr = pAlku;
    float summat[12] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int lkm[12] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    struct tm tm;
    char buf[255];
    int i;

    while (ptr != NULL){
        memset(&tm, 0, sizeof(tm));
        strptime(ptr->aika, "%d.%m.%Y", &tm);
        strftime(buf, sizeof(buf), "%m\n", &tm);
        i = atoi(buf);
        summat[i - 1] = summat[i - 1] + ptr->arvo;
        lkm[i - 1]++;
        ptr = ptr->pSeuraava;

    }
    pAlku = tyhjenna(pAlku);
    ptr = pAlku;
    int a;
    for(a=0;a < 12;a++){
        TIETO *pUusi, *ptr;
        char buffer[VAKIO];
        pUusi = muistinvaraus(pUusi);
        if (lkm[a] == 0){
            strcpy(pUusi->aika, itoa(a,10));
            pUusi->arvo = 0;
            pUusi->pSeuraava = NULL;
        }else{
            strcpy(pUusi->aika, itoa(a,10));
            pUusi->arvo = (summat[a] / lkm[a]);
            pUusi->pSeuraava = NULL;
        }
        if (pAlku == NULL) {
            pAlku = pUusi;
        } else {
            ptr = pAlku;
            while (ptr->pSeuraava != NULL)
            ptr = ptr->pSeuraava;
            ptr->pSeuraava = pUusi;
        }
    }
    printf("\nLaskettu lämpötilojen keskiarvot eri kuukausille.\n\n");
    return(pAlku);    
}

void kirjoitaTiedosto(char pNimi[VAKIO], TIETO *pAlku){
    TIETO *ptr = pAlku;
    int i = 1;
    printf("Kuukausi;Keskiarvo\n");
    while (ptr != NULL) {
        printf("KK %d;%.2f\n", i, ptr->arvo);
        ptr = ptr->pSeuraava;
        i++;
    }

    FILE* T;
    if ((T = fopen(pNimi, "w")) == NULL) {
        perror("\nTiedoston avaaminen epäonnistui, lopetetaan");
        exit(0);
    }

    ptr = pAlku;
    i = 1;
    fprintf(T, "Kuukausi;Keskiarvo\n");
    while (ptr != NULL) {
        fprintf(T, "KK %d;%.2f\n", i, ptr->arvo);
        ptr = ptr->pSeuraava;
        i++;
    }
    fclose(T);
    printf("\nTiedosto '%s' kirjoitettu.\n\n", pNimi);
    return;
}

TIETO *tyhjenna(TIETO *pAlku) {
    TIETO *ptr = pAlku;
    while (ptr != NULL) {
        pAlku = ptr->pSeuraava;
        free(ptr);
        ptr = pAlku;
    }
    return(pAlku);
}


char* itoa(int val, int base){
	
	static char buf[32] = {0};
	
	int i = 30;
	
	for(; val && i ; --i, val /= base)
	
		buf[i] = "0123456789abcdef"[val % base];
	
	return &buf[i+1];
	
}