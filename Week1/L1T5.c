#include <stdio.h>
int main(void) {
    char nimi[30];
    char rotu[30];
    int ika;
    float paino;
    printf("Anna lemmikin nimi: ");
    scanf("%s", nimi);
    printf("Anna lemmikin rotu: ");
    scanf("%s", rotu);
    printf("Anna lemmikin ikä: ");
    scanf("%d", &ika);
    printf("Anna lemmikin paino: ");
    scanf("%f", &paino);
    printf("Lemmikin nimi on %s ja rotu on %s.\nSen ikä on %d vuotta ja paino %.1f kg.\n", nimi, rotu, ika, paino);
    return(0);
}