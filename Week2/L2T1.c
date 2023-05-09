#include <stdio.h>

int main(void){
    int iLkm;
    printf("Anna palautettujen tehtävien lukumäärä: ");
    scanf("%d", &iLkm);

    if (iLkm > 30){
        printf("Kurssilla on vain 30 tehtävää.\n");
    } else if (iLkm > 26){
        printf("Olet palauttanut %d tehtävää, joten arvosanasi on 5.\n", iLkm);
    } else if (iLkm > 23){
        printf("Olet palauttanut %d tehtävää, joten arvosanasi on 4.\n", iLkm);
    } else if (iLkm > 20 ){
        printf("Olet palauttanut %d tehtävää, joten arvosanasi on 3.\n", iLkm);
    } else if (iLkm > 17){
        printf("Olet palauttanut %d tehtävää, joten arvosanasi on 2.\n", iLkm);
    } else if (iLkm > 14){
        printf("Olet palauttanut %d tehtävää, joten arvosanasi on 1.\n", iLkm);
    } else {
        printf("Olet palauttanut %d tehtävää, joten arvosanasi on 0.\n", iLkm);
    }
    return(0);
}