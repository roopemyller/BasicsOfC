/* 30012023 roopemyller 389129 L3T1*/

#include <stdio.h>

int main (void){

    printf("Tämä ohjelma laskee suorakulmion pinta-alan.\n");

    float fKanta;
    printf("Anna suorakulmion kanta: ");
    scanf("%f", &fKanta);

    float fKorkeus;
    printf("Anna suorakulmion korkeus: ");
    scanf("%f", &fKorkeus);

    float fPintaAla = fKanta * fKorkeus;
    printf("Suorakulmion pinta-ala on %.2f.\n", fPintaAla);

    printf("Kiitos ohjelman käytöstä.\n");
    return(0);
}