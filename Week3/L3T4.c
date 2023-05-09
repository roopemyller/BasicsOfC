/* 31012023 roopemyller 389129 L3T4*/

#include <stdio.h>
#define KOKO 60

char *yhdistaMjonot(char *mJono1, char *mJono2, int i);

int mjonoPituus(char *mJono);

int main (void){

    int iPituus1, iPituus2, iYhdistetty;
    char mJono1[KOKO], mJono2[KOKO], *yhdistetty;

    printf("Anna ensimmäinen merkkijono (max 30 merkkiä): ");
    fgets(mJono1, KOKO, stdin);

    printf("Anna toinen merkkijono (max 30 merkkiä): ");
    fgets(mJono2, KOKO, stdin);

    iPituus1 = mjonoPituus(mJono1);
    iPituus2 = mjonoPituus(mJono2);
    iYhdistetty = iPituus1 + iPituus2;
    if (iYhdistetty > 60){
        printf("Merkkijonojen yhteenlaskettu pituus on liian pitkä ohjelman muistialueelle.\n");
    }else{
        yhdistetty = yhdistaMjonot(mJono1, mJono2, iPituus1);
        printf("Yhdistetty merkkijono on:\n'%s'\n", yhdistetty);
    }

    printf("Kiitos ohjelman käytöstä.\n");
    return(0);
}

int mjonoPituus(char *mJono){
    int i;
    for(i=0; mJono[i] != '\n'; ++i);
    return (i);
}

char *yhdistaMjonot(char *mJono1, char *mJono2, int i){
    int j;
    for (j = 0; mJono2[j] != '\n'; ++j, ++i){
        mJono1[i] = mJono2[j];
    }
    return mJono1;
}