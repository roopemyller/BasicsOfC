/* 06022023 roopemyller 389129 L4T2*/
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    if (argc == 3){
        char aRivi[52];
        int i = 0;
        int iLuku = atoi(argv[2]);
        FILE* T;
        if ((T = fopen(argv[1], "r")) == NULL) {
            perror("Tiedoston avaaminen epäonnistui, lopetetaan");
            exit(0);
        }
        while (fgets(aRivi, 52, T) != NULL){
            if (i < iLuku){
                printf("%s", aRivi);
                i++;
            }
        }
        if (i < iLuku){
                printf("\nTiedostossa ei ole enempää rivejä luettavaksi.");
        }
        fclose(T);
        printf("\nTiedostosta '%s' luettu %d riviä.\n", argv[1], i);
    }else if(argc > 3){
        printf("Annoit liikaa parametreja.\n");
    }else{
        printf("Et antanut tarpeeksi parametreja.\n");
    }
    
    return(0);
}