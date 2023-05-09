#include <stdio.h>
#define MIN 3
#define MAX 10
int main(void) {
    
    int iLuku;
    printf("Anna kokonaisluku väliltä 3 - 10: ");
    scanf("%d", &iLuku);
    printf("\n");
    if ((iLuku > MAX) || (iLuku < MIN)){
        printf("Antamasi luku ei ole määritellyllä välillä.\n");
    } else{
        int i = 1;
        for (i = 1; i <= iLuku; i++){
            int y = 1;
            for (y = 1; y <= iLuku; y++){
                printf("*");
            }
            printf("\n");
        }
    }
    

    return(0);
}