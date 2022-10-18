#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int row;
    // looping and check if row less than or more than 8
    do
    {
        row = get_int("Row= ");
    }
    while (row > 8 || row < 1);
    // 1st loop for the colomn
    for (int i = 0; i < row; i++){
        // this 2nd loop is for the space before the #, it is minus row because theres only 2 colomn for space in a row of 3
        //e.g 3 row
        // (Space)(Space)#
        // (Space)##
        // ###
        // so ittl look like this
        //  #
        // ##
        //###
        for (int j = i; j < row - 1; j++){
            printf (" ");
        }
        for (int k = 0; k <=i; k++){

            printf("#");
        }
        // this print f gonna loop to according to the 1st loop, after every ##
        printf("  ");
        // this last loop is for the square triangle, there's only one loop because it correspondent with the 1st loop
    
        for(int l = 0; l<=i; l++){
            printf("#");
        }
    printf("\n");
    }

}