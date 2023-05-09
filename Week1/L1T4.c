#include <stdio.h>
#include <string.h>
int main(void) {
    char merkki;
    printf("Anna merkki: ");
    scanf("%c", &merkki);
    printf("Annoit merkin '%c'.\n", merkki);
    getchar();
    char merkkijono[20];
    printf("Anna korkeintaan 20 merkkiä pitkä merkkijono: ");
    /* fgets(merkkijono, 20, stdin); */
    scanf("%s", merkkijono);
    /*merkkijono[strlen(merkkijono)-1] = '\0'; */
    printf("Annoit merkkijonon '%s'.\n", merkkijono);
    return(0);
}