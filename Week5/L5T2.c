/* 13022023 roopemyller 389129 L5T2*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VAKIO 30

int main(void){
    void kysyTiedosto(char pNimi[VAKIO]);
    void lueTiedosto(char pNimi[VAKIO]);

    char pNimi[VAKIO];
    kysyTiedosto(pNimi);
    lueTiedosto(pNimi);
    printf("Kiitos ohjelman käytöstä.\n");
    return(0);
}

void kysyTiedosto(char pNimi[VAKIO]){
    printf("Anna luettavan tiedoston nimi: ");
    scanf("%s", pNimi);
    return;
}

void lueTiedosto(char pNimi[VAKIO]){
    FILE* T;
    char rivi[50], *p1, *p2;
    char minJoukkue[30];
    int minPisteet = __INT_MAX__;
    if ((T = fopen(pNimi, "r")) == NULL){
        perror("Tiedoston avaaminen epäonnistui, lopetetaan");
        exit(0);
    }
    while (fgets(rivi, 50, T) != NULL){
        if ((p1 = strtok(rivi, ";")) == NULL) {
            printf("Merkkijonon '%s' pilkkominen epäonnistui.\n", rivi);
            exit(1);
        }
        if ((p2 = strtok(NULL, "\n")) == NULL) {
            printf("Merkkijonon '%s' pilkkominen epäonnistui.\n", rivi);
            exit(1);
        }
        int joukkueenPisteet = atoi(p2);
        if (joukkueenPisteet < minPisteet){
            minPisteet = joukkueenPisteet;
            strcpy(minJoukkue, p1);
        }

    }
    printf("Tiedosto '%s' luettu.\n", pNimi);
    printf("Pienin pistemäärä oli joukkueella '%s' %d pisteellä.\n", minJoukkue, minPisteet);
    fclose(T);

    return;
}
