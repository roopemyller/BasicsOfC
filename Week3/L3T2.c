/* 30012023 roopemyller 389129 L3T2*/

#include <stdio.h>
#include <stdlib.h>

int main (void){

    int lueTiedosto(char aTiedostonnimi[30]);
    void kirjoitaTiedosto(char aTiedostonnimi[30], int iLukujenSumma);

    printf("Tämä ohjelma laskee tiedostossa olevien lukujen summan.\n");
    char aTLuku[30], aTKirjoitus[30];
    printf("Anna luettavan tiedoston nimi: ");
    scanf("%s", aTLuku);

    int iLukujenSumma = lueTiedosto(aTLuku);

    printf("\nAnna kirjoitettavan tiedoston nimi: ");
    scanf("%s", aTKirjoitus);
    kirjoitaTiedosto(aTKirjoitus,  iLukujenSumma);

    printf("\nKiitos ohjelman käytöstä.\n");
    return(0);
}

int lueTiedosto(char aTiedostonimi[30]){
    int iSumma = 0, iLuku;
    char rivi[50];
    FILE* T;
    if ((T = fopen(aTiedostonimi, "r")) == NULL) {
        perror("Tiedoston avaaminen epäonnistui, lopetetaan");
        exit(0);
    }
    while (fgets(rivi, 50, T) != NULL){
        sscanf(rivi, "%d", &iLuku);
        iSumma += iLuku;
    }
    fclose(T);
    printf("Tiedosto '%s' luettu, lukujen summa oli %d.\n", aTiedostonimi, iSumma);
    return(iSumma);
}

void kirjoitaTiedosto(char aTiedostonimi[30], int iLukujenSumma){
    FILE* T;
    if ((T = fopen(aTiedostonimi, "w")) == NULL) {
        perror("Tiedoston avaaminen epäonnistui, lopetetaan");
        exit(0);
    }
    fprintf(T, "Lukujen summa oli %d.\n", iLukujenSumma);
    fclose(T);
    printf("Tiedosto '%s' kirjoitettu.\n", aTiedostonimi);
    return;
}