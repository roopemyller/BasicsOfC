#include <stdio.h>

int main(void){

    int iLuku;
    printf("Anna kokonaisluku: ");
    scanf("%d", &iLuku);

    int iValinta;
    do {
        printf("\nValikko:\n1) Lisää lukuun\n2) Vähennä luvusta\n0) Lopeta\nValintasi: ");
        scanf("%d", &iValinta);
        switch (iValinta) {
        case 1: ;
            int iLuku1;
            printf("\nAnna lukuun lisättävä kokonaisluku: ");
            scanf("%d", &iLuku1);
            iLuku = iLuku + iLuku1;
            printf("Luku on nyt %d.\n", iLuku);
            break;
        case 2: ;
            int iLuku2;
            printf("\nAnna luvusta vähennettävä kokonaisluku: ");
            scanf("%d", &iLuku2);
            iLuku = iLuku - iLuku2;
            printf("Luku on nyt %d.\n", iLuku);
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