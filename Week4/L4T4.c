/* 09022023 roopemyller 389129 L4T4*/
#include <stdio.h>
#include <stdlib.h>
#define RIVI 3
#define SARAKE 3
#define VAKIO 30

int main(void){
    void kysyTiedosto(char pNimi[VAKIO]);
    void tulostaJaKirjoitaMatriisi(int matriisi[RIVI][SARAKE], char pNimi[VAKIO]);

    char pNimi[VAKIO];
    kysyTiedosto(pNimi);

    int matriisi[RIVI][SARAKE];
    printf("Anna arvot lähtömatriisille: \n");
    int i, j;
    for (i=0; i < RIVI; i++) {
        for (j=0; j < SARAKE; j++){
            printf("Rivi %d, alkio %d: ", i + 1, j + 1);
            scanf("%d", &matriisi[i][j]);
        }     
    }

    tulostaJaKirjoitaMatriisi(matriisi, pNimi);
    printf("Kiitos ohjelman käytöstä.\n");
    return(0);
}

void kysyTiedosto(char pNimi[VAKIO]){
    printf("Anna kirjoitettavan tiedoston nimi: ");
    scanf("%s", pNimi);
    return;
}

void tulostaJaKirjoitaMatriisi(int matriisi[RIVI][SARAKE], char pNimi[VAKIO]){
    FILE* T;
    if ((T = fopen(pNimi, "w")) == NULL){
        perror("Tiedoston avaaminen epäonnistui, lopetetaan");
        exit(0);
    }
    int i, j;
    printf("\nLähtömatriisi: \n");
    fprintf(T, "Lähtömatriisi: \n");
    int apu;
    for (i=0; i < RIVI; i++) {
        apu = 0;
        for (j=0; j < SARAKE; j++){
            if (apu == 0){
                fprintf(T, "%4d", matriisi[i][j]);
                apu++;
            }else{
                fprintf(T, "%5d", matriisi[i][j]);
            }
            printf("%4d ", matriisi[i][j]);
        }
        printf("\n");
        fprintf(T, " \n");
    }
    printf("\nLähtömatriisin transpoosi: \n");
    fprintf(T, "\nLähtömatriisin transpoosi: \n");
    int matriisi2[RIVI][SARAKE];
    
    for (i=0; i < RIVI; i++) {
        for (j=0; j < SARAKE; j++){
            matriisi2[j][i] = matriisi[i][j];
        }     
    }
    
    for (i=0; i < RIVI; i++) {
        apu = 0;
        for (j=0; j < SARAKE; j++){
            if (apu == 0){
                fprintf(T, "%4d", matriisi2[i][j]);
                apu++;
            }else{                
                fprintf(T, "%5d", matriisi2[i][j]);
            }
            printf("%4d ", matriisi2[i][j]);
        }
        printf("\n");
        fprintf(T, " \n");
    }
    fclose(T);
    printf("\nTiedosto '%s' kirjoitettu.\n", pNimi);
}