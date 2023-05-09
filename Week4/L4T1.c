/* 06022023 roopemyller 389129 L4T1*/
#include <stdio.h>
#include <string.h>
#define VAKIO 50

struct kappale{
    char aNimi[VAKIO];
    char aEsittaja[VAKIO];
    char aPituus[VAKIO];
    int iVuosi;
};

int main (void){
    struct kappale kple;

    printf("Anna kappaleen nimi: ");
    fgets(kple.aNimi, VAKIO, stdin);
    kple.aNimi[strlen(kple.aNimi) - 1] = '\0';

    printf("Anna kappaleen esittäjä: ");
    fgets(kple.aEsittaja, VAKIO, stdin);
    kple.aEsittaja[strlen(kple.aEsittaja) - 1] = '\0';

    printf("Anna kappaleen pituus: ");
    fgets(kple.aPituus, VAKIO, stdin);
    kple.aPituus[strlen(kple.aPituus) - 1] = '\0';

    printf("Anna kappaleen julkaisuvuosi: ");
    scanf("%d", &kple.iVuosi);

    printf("Kappaleen nimi on '%s' ja esittäjä '%s'.\n", kple.aNimi, kple.aEsittaja);
    printf("Kappale on %s minuuttia pitkä ja julkaistu vuonna %d.\n", kple.aPituus, kple.iVuosi);
    printf("Kiitos ohjelman käytöstä.");
    return(0);
}