/* 30012023 roopemyller 389129 L3T3*/

#include <stdio.h>
#include <stdlib.h>

int main(void){
    int valikko();
    int lisaaLukuun(int iLuku1, char pNimi[30]);
    void tulostaTulokset(char pNimi[30]);

    int iLuku, iValinta;
    char pNimi[30];
    printf("Anna kokonaisluku: ");
    scanf("%d", &iLuku);

    printf("Anna kirjoitettavan tiedoston nimi: ");
    scanf("%s", pNimi);

    do {
        iValinta = valikko();
        switch (iValinta) {
        case 1:
            iLuku = lisaaLukuun(iLuku, pNimi);
            break;
        case 2: ;
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

int valikko() {
    int iValinta;
    printf("\nValitse haluamasi toiminto:\n1) Lisää lukuun\n2) Tulosta tulokset\n0) Lopeta\nAnna valintasi: ");
    scanf("%d", &iValinta);
    getchar();
    return iValinta;
}

int lisaaLukuun(int iLuku1, char pNimi[30]){
    int iLuku2;
    printf("\nAnna lukuun lisättävä kokonaisluku: ");
    scanf("%d", &iLuku2);
    printf("%d+%d=%d\n", iLuku1, iLuku2, (iLuku1 + iLuku2));
    FILE* T;
    if ((T = fopen(pNimi, "a")) == NULL) {
        perror("Tiedoston avaaminen epäonnistui, lopetetaan");
        exit(0);
    }
    fprintf(T, "%d+%d=%d\n", iLuku1, iLuku2, (iLuku1 + iLuku2));
    fclose(T);
    return(iLuku1 + iLuku2);
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