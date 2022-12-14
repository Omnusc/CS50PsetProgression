#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
// Ceaser Algorithm
// https://cs50.harvard.edu/x/2022/psets/2/caesar/
int main(int argc, string argv[])
{

    int key = 0;
    string test = argv[1];
    if (argc != 2)
    {
        printf("Error, missing command line\n");
        return 1;
    }
    else
    {

        int lengthTest = strlen(test);
        for (int i = 0; i < lengthTest; i++)
        {
            if (!isdigit(test[i]))
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }
        }

    }
    // pake modular nanti
    key = atoi(test);
    string plaintext = get_string("plaintext: ");
    int length = strlen(plaintext);
    printf("ciphertext: ");
    for (int k = 0; k < length; k++)
    {
        if ((plaintext[k] >= 'a' && plaintext[k] <= 'z') || (plaintext[k] >= 'A' && plaintext[k] <= 'Z') )
        {
            if (isupper(plaintext[k]))
            {
// jadi logikanya, misal huruf z itu value asciinya 122, cara kita balik ke a karena setelah z tidak ada huruf lagi, kita pakai modular jumlah alphabet / huruf z kecil atau z gede setelah
// di minus ascii value a kecil atau a gede, kemudian kita tambahin ascii value a lagi
// jadi 122 (z) kita tambahin 1 (key) dan minus value ascii a (122 - 97 + 1 = 26) hasilnya nah kita modularin 26, karena ada 26 huruf di alphabet, hasilnya adalah 0 yaitu kemudian kita tambahkan
// 97 agar dia balik ke a dalam value ascii
// (108-97+300) = 311; 311%26 = 25; 25 + 97 = 122 (z)
                plaintext[k]  = (plaintext[k] - 'A' + key) % 26 + 'A';
                printf("%c", plaintext[k]);
            }
            else if (islower(plaintext[k]))
            {
                plaintext[k]  = (plaintext[k] - 'a' + key) % 26 + 'a';
                printf("%c", plaintext[k]);
            }
        }
        else
        {
            printf("%c", plaintext[k]);
        }
    }
    printf("\n");


}