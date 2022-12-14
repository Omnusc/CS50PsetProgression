#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <strings.h>
#include <stdbool.h>

// Subtitute the user input according to the key
// NQXPOMAFTRHLZGECYJIUWSKDVB example of a valid key
bool check_char(string key, int lengthkey);
string lower_key(string key, int lengthkey);
int main(int argc, string argv[])
{
// Check if the command line have 2 input (program name, and key input)
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    string key = argv[1];
    int lengthkey = strlen(key);
    if (lengthkey != 26)
    {
        printf("Key must contain 26 characters\n");
        return 1;
    }
// Nested loop to check if there are any repeated alphabet
// So the 1st loop is for getting the 1st index (i) of NQXPOMAFTRHLZGECYJIUWSKDVB the 'N' alphabet and then 1++ index after that
// the 2nd loop is to check the i+1 in this case the 2nd index, and check it its the same as the 1st index, N is not equal to Q
// and then we go to i+2 index, and so on and so forth
// after the 2nd loop is over, we go back to the 1st loop to check the 2nd index, in this case alphabet 'Q', and we do it all over again.
    for (int i = 0; i < lengthkey; i ++)
    {
        for (int k = i + 1; k < lengthkey; k++)
        {
            if (key[i] == key[k])
            {
                printf("Key must not contain repeated alphabet\n");
                return 1;
            }
        }
    }
    for (int j = 0; j < lengthkey; j++)
    {
        if(!isalpha(key[j]))
        {
            printf("Input only alphabet\n");
            return 1;
        }
    }
    key = lower_key(key, lengthkey);
    string plain_text = get_string("plaintext: ");
    int length_plain_text = strlen(plain_text);
    // This loop is to change every string correspond to the key.
    // logic:
    // for example the string have the letter 'l' with the ascii of 108. so because it is lower case, we subsract it by 97 to get the number 11 (l is in the index of 11(starts with 0))
    // then we change it to the coresponding key index (index of 11)
    for (int l = 0; l < length_plain_text; l++)
    {
        if(islower(plain_text[l]))
        {
            plain_text[l] = key[plain_text[l] - 97];
        }
        else if (isupper(plain_text[l]))
        {
            // We make em lower case 1st so the arithmatic is simpler
            plain_text[l] = tolower(plain_text[l]);
            plain_text[l] = key[plain_text[l] - 97];
            // Change it back to upper
            plain_text[l] = toupper(plain_text[l]);
        }
    }
    printf("ciphertext: %s", plain_text);
    printf("\n");
}
string lower_key(string key, int lengthkey)
{
    for(int i = 0; i < lengthkey; i++)
    {
        if(isupper(key[i]))
        {
            key[i] = tolower(key[i]);
        }
    }
    return key;
}