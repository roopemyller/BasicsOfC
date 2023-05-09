#include <stdio.h>
#define PII 3.141

int main (void){

    float fSade;
    printf("Anna ympyrän säde: ");
    scanf("%f", &fSade);
    
    int iValinta;
    printf("\nValikko:\n1) Laske ympyrän kehän pituus\n2) Laske ympyrän pinta-ala\nValitse: ");
    scanf("%d", &iValinta);

    switch (iValinta) {
    case 1: ;
        float fKehanPituus = 2 * PII * fSade;
        printf("Ympyrän säde on %.3f ja sen kehän pituus %.3f.\n", fSade, fKehanPituus);
        break;
    case 2: ;
        float fPintaAla = PII * fSade * fSade;
        printf("Ympyrän säde on %.3f ja sen pinta-ala on %.3f.\n", fSade, fPintaAla);
        break;
    default:
        printf("Tuntematon valinta.\n");
        break;
    }

    return(0);
}