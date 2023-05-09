/* 14022023 roopemyller 389129 L5T3*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define VAKIO 30

typedef struct lasku {
    int luku1;
    int luku2;
    int summa;
}LASKU;

int main(int argc, char *argv[]){
    LASKU* varaaMuisti();
    void kysyTiedostonimi(char *pN);
    int valikko();
    int lisaaLukuun(int iLuku1, LASKU *pLasku, int iMonta);
    void kirjoitaTiedostoon(char pNimi[VAKIO], LASKU laskut[VAKIO], int iMonta);
    void tulostaTulokset(char pNimi[VAKIO]);
    if (argc < 2){
        printf("Et antanut tarpeeksi parametreja.\n");
        return(0);
    }else if (argc > 2){
        printf("Annoit liikaa parametreja.\n");
        return(0);
    }


    LASKU laskut[VAKIO];
    LASKU *pLasku = varaaMuisti();

    int iLuku, iValinta, iMonta = 0, iOnkoTiedosto = 0;
    char pNimi[VAKIO];
    char *pN = pNimi;

    iLuku = atoi(argv[1]);
    printf("Annoit luvun %d.", iLuku);
    do {
        iValinta = valikko();
        switch (iValinta) {
        case 1:
            kysyTiedostonimi(pN);
            iOnkoTiedosto++;
            break;
        case 2:
            iLuku = lisaaLukuun(iLuku, laskut, iMonta);
            iMonta++;
            break;
        case 3: ;
            if(iMonta == 0){
                printf("\nEi kirjoitettavia tietoja.\n");
                
            }else{
                if (iOnkoTiedosto == 0){
                    printf("\nEi tiedoston nimeä, anna kirjoitettavan tiedoston nimi ensin.\n");
                }else{
    	            kirjoitaTiedostoon(pNimi, laskut, iMonta);
                }
            }
            break;
        case 4:
            if(iOnkoTiedosto == 0){
                printf("\nEi tiedoston nimeä, anna luettavan tiedoston nimi ensin.\n");
            }else{
                tulostaTulokset(pNimi);
            }
            break;
        case 0:
            free(pLasku);
            pLasku = NULL;
            printf("\nMuisti vapautettu.\n");
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

LASKU* varaaMuisti(/*Mille varataan*/){
    /*Muistin varaus*/
    LASKU* pLaskuMuisti;
    int muistin_maara = (VAKIO + 1) * sizeof(LASKU);
    if ((pLaskuMuisti = (LASKU *)malloc(muistin_maara)) == NULL){
        perror("Muistinvaraus epäonnistui");
        exit(0);
    }
    return(pLaskuMuisti);
}

void kysyTiedostonimi(char *pN){
    printf("\nAnna kirjoitettavan tiedoston nimi: ");
    scanf("%s", pN);
    return;
}

int valikko() {
    int iValinta;
    printf("\nValitse haluamasi toiminto:\n1) Anna tiedoston nimi\n2) Lisää lukuun\n3) Kirjoita historia tiedostoon\n4) Lue historia tiedostosta\n0) Lopeta\nAnna valintasi: ");
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

void kirjoitaTiedostoon(char pNimi[VAKIO], LASKU *pLasku, int iMonta){
    int i;
    printf("\n");
    for (i=0; i < iMonta; i++){
        printf("%d+%d=%d\n", pLasku[i].luku1, pLasku[i].luku2, pLasku[i].summa);
    }
    FILE* T;
    if ((T = fopen(pNimi, "a")) == NULL) {
        perror("\nTiedoston avaaminen epäonnistui, lopetetaan");
        exit(0);
    }
    
    
    for (i=0; i < iMonta; i++){
        fprintf(T, "%d+%d=%d\n", pLasku[i].luku1, pLasku[i].luku2, pLasku[i].summa);
    }
    fclose(T);
    printf("\nTiedosto '%s' kirjoitettu.\n", pNimi);
    return;
}

void tulostaTulokset(char pNimi[VAKIO]){
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
