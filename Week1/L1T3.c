#include <stdio.h>
int main(void){
    int luku1;
    printf("Anna ensimmäinen kokonaisluku: ");
    scanf("%d", &luku1);
    int luku2;
    printf("Anna toinen kokonaisluku: ");
    scanf("%d", &luku2);

    int tulo;
    tulo = ++luku1 * luku2;
    printf("%d * %d = %d\n", luku1, luku2, tulo);
    --luku1;
    int jako;
    jako = luku1 / luku2;
    printf("(%d / %d) - 10 = %d\n", luku1, luku2, (jako - 10));

    int jakojaannos;
    jakojaannos = luku1 % --luku2;
    printf("%d %% %d = %d\n", luku1, luku2, jakojaannos);

    return(0);
}