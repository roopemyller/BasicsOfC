/* 10022023 roopemyller 389129 L4T3*/

#include <stdio.h>
#include <stdlib.h>

typedef struct lasku {
    int luku1;
    int luku2;
    int summa;
}LASKU;

int main(void){
    void kysyTiedostonimi(char *pN);
    int valikko();
    int lisaaLukuun(int iLuku1, LASKU *pLasku, int iMonta);
    void kirjoitaTiedostoon(char pNimi[30], LASKU laskut[30], int iMonta);
    void tulostaTulokset(char pNimi[30]);

    LASKU laskut[30];
    LASKU *pLasku = laskut;

    int iLuku, iValinta, iMonta = 0;
    char pNimi[30];
    char *pN = pNimi;

    printf("Anna kokonaisluku: ");
    scanf("%d", &iLuku);

    kysyTiedostonimi(pN);

    do {
        iValinta = valikko();
        switch (iValinta) {
        case 1:
            iLuku = lisaaLukuun(iLuku, laskut, iMonta);
            iMonta++;
            break;
        case 2: ;
            kirjoitaTiedostoon(pNimi, laskut, iMonta);
            break;
        case 3:
            tulostaTulokset(pNimi);
            break;
        case 0:
            printf("\nLopetetaan.\n\n");
            break;
        default:
            printf("\nTuntematon valinta, yritä uudestaan.\n");
            break;
        }
    } while (iValinta != 0);

    printf("Kiitos ohjelman käytöstä.\n");
    return(0);
}

void kysyTiedostonimi(char *pN){
    printf("Anna kirjoitettavan tiedoston nimi: ");
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

int lisaaLukuun(int iLuku1, LASKU *pLasku, int iMonta){
    int iLuku2;
    printf("\nAnna lukuun lisättävä kokonaisluku: ");
    scanf("%d", &iLuku2);
    printf("%d+%d=%d\n", iLuku1, iLuku2, (iLuku1 + iLuku2));
    pLasku[iMonta].luku1 = iLuku1;
    pLasku[iMonta].luku2 = iLuku2;
    pLasku[iMonta].summa = iLuku1 + iLuku2;
    return(iLuku1 + iLuku2);
}

void kirjoitaTiedostoon(char pNimi[30], LASKU *pLasku, int iMonta){
    FILE* T;
    if ((T = fopen(pNimi, "a")) == NULL) {
        perror("\nTiedoston avaaminen epäonnistui, lopetetaan");
        exit(0);
    }
    
    int i;
    for (i=0; i < iMonta; i++){
        fprintf(T, "%d+%d=%d\n", pLasku[i].luku1, pLasku[i].luku2, pLasku[i].summa);
    }
    fclose(T);
    printf("\nTiedosto '%s' kirjoitettu.\n", pNimi);
    return;
}

void tulostaTulokset(char pNimi[30]){
    char aRivi[52];
    FILE* T;
    if ((T = fopen(pNimi, "r")) == NULL) {
        perror("Tiedoston avaaminen epäonnistui, lopetetaan");
        exit(0);
    }
    printf("\nTiedostossa oleva laskuhistoria:\n");
    while (fgets(aRivi, 52, T) != NULL){
        printf("%s", aRivi);

    }
    fclose(T);
    printf("Tiedosto '%s' luettu ja tulostettu.\n", pNimi);
    return;
}
