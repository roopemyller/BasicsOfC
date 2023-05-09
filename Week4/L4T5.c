/* 10022023 roopemyller 389129 L4T5*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
    void tulosta(char *mjono);
    void tulostaTakaperin(char *mjono, int n);

    int iValinta;
    char *mjono;
    int i = 0;

    if (argc == 2){
        // merkkijono on argv[1]
        strcpy(mjono, argv[1]);

        do {
            printf("Valitse haluamasi toiminto:\n1) Tulosta merkkijono\n2) Tulosta merkkijono takaperin\n0) Lopeta\n"); 
            printf("Anna valintasi: ");
            scanf("%d", &iValinta);
            switch (iValinta) {
                case 1:
                    tulosta(mjono);
                    break;
                case 2: ;
                    tulostaTakaperin(mjono, strlen(mjono));
                    break;
                case 0:
                    printf("Lopetetaan.\n");
                    break;
                default:
                    printf("\nTuntematon valinta, yritä uudestaan.\n");
                    break; 
            }
            printf("\n");
        } while (iValinta != 0);      
        printf("Kiitos ohjelman käytöstä.\n");  
    }else if(argc > 2){
        printf("Annoit liikaa parametreja.\n");
    }else{
        printf("Et antanut tarpeeksi parametreja.\n");
    } 
    return(0);
}

void tulosta(char *mjono){
    if (*mjono != '\0'){
        printf("%c\n", *mjono);
        tulosta(mjono + 1);
    }
    return;
}

void tulostaTakaperin(char *mjono, int n){
    int i;
    if (n > 0){
        i = n - 1;
        printf("%c\n", mjono[i]);
        tulostaTakaperin(mjono, i);
    }
    return;
}
    