#include <stdio.h>
#include <string.h>

int main(void){
    char cMerkki;
    printf("Anna merkki: ");
    scanf("%c", &cMerkki);
    int iMerkinArvo = cMerkki;
    printf("Merkki '%c' on ASCII-taulukon mukaan lukuna %d.\n", cMerkki, iMerkinArvo);

    char cMjono[15];
    printf("Anna merkkijono: ");
    scanf("%s", cMjono);
    
    int i = 0;
    int iSumma = 0;
    while (i < strlen(cMjono)){
        int cMerkkiArvo = cMjono[i];
        iSumma = iSumma + cMerkkiArvo;
        i++;
    }
    printf("Merkkijonon '%s' merkkien summa on %d.\n", cMjono, iSumma);
    return(0);
}