#include <stdio.h>
#include <stdlib.h>


int print_pattern(int number) {
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
    /**
     * You are given a number N. You need to print the pattern for the given value of N.

  For N = 2 the pattern will be
  2 2 1 1
  2 1

  For N = 3 the pattern will be
  3 3 3 2 2 2 1 1 1
  3 3 2 2 1 1
  3 2 1

  Note: Instead of printing a new line print a "$" without quotes. After printing the total output, end of the line is expected.

  Your Task:
  Since this is a function problem, you don't need to worry about the test cases.
  Your task is to complete the function printPat() which takes one argument 'N' denoting the length of the pattern.

  Constraints:
  1 <= N <= 40
     *
    */
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
