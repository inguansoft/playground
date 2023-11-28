#include <stdio.h>
#include <stdlib.h>


/**
 * 16 bits
 * @param number
 * @return
 */
int print_pattern(uint number) {
    int i, j, k;
    if (number > 0 && number < 41) {
        for (i=number; i>0; i--){ // Iterations
            for (j=i; j>0; j--) { //Number
                for (k=i; k>0; k--) { //Iterate
                    printf("%d ", j);
                }
            }
            printf("$");
        }
        printf("\n");
        return 0;
    } else {
        printf("Number has to be between 1 and 40\n");
        return 1;
    }
}

int main(void) {

    int i=0;
    for (i=0;i<5;i++) {
        printf("Getting pattern for %02x\n",i);
        if (print_pattern(i) == 0) {
            printf("Successfully loaded %02x!\n",i);
        } else {
            printf("EXIT with failure using %02x!\n",i);
        }
    }
    return EXIT_SUCCESS;

}
