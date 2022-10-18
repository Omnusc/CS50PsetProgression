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
    for(
        int i = 0 ; i < row ; i++
        )
        {
        // loop for space same as mario more
        for(int j = i ; j < row-1; j++ ){
             printf(" ");
        }
        // loop more #
        for (int k = 0 ; k <= i ; k ++){
            printf("#");
        }
        printf("\n");
    }
}