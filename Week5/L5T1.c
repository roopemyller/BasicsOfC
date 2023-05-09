/* 13022023 roopemyller 389129 L5T1.c */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define VAKIO 30


int main (void){
    char* varaaMuisti();
    void sijoitaMerkkijono(char* pMuistilohko, char lukuPuskuri[VAKIO]);

    char lukuPuskuri[VAKIO];

    char* pMuistilohko = varaaMuisti();
    printf("Muisti varattu %d merkille.\n", VAKIO);
    sijoitaMerkkijono(pMuistilohko, lukuPuskuri);

    printf("Annoit merkkijonon '%s'.\n", pMuistilohko);

    free(pMuistilohko);
    printf("Muisti vapautettu.\nKiitos ohjelman käytöstä.\n");
    return(0);
}

char* varaaMuisti(){
    char* pMuistilohko;
    int muistin_maara = (VAKIO + 1) * sizeof(char);
    if ((pMuistilohko = (char *)malloc(muistin_maara)) == NULL){
        perror("Muistinvaraus epäonnistui");
        exit(0);
    }
    return(pMuistilohko);
}

void sijoitaMerkkijono(char* pMuistilohko, char lukuPuskuri[VAKIO]){
    printf("Anna merkkijono: ");
    fgets(lukuPuskuri, 255, stdin);
    lukuPuskuri[strlen(lukuPuskuri) - 1] = '\0';
    strcpy(pMuistilohko, lukuPuskuri);
    return;
}