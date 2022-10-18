#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    if(score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    else if(score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else
    {
        printf("Tie\n");
    }
    // TODO: Print the winner
}

int compute_score(string word)
{
    //update score

    int score = 0;

    int test = strlen(word);

    // jadi logikanya adalah: we know that ascii (for example all lowercase a to z) start and ends with 97 and  122
    // so for example the word contain the letter 'a'. ascii for 'a' start with 97. we can substract it by 97 (the ascii of 'a' THE FIRST LETTER), and get the number 0.
    // 0 is the array number for the word 'a' in the int POINTS[] it is 1 point for the letter 'a'.
    // e.g if the letter is 'f', 'f' ascii is 102. substract 102 with 97 (the ascii of 'a' THE FIRST LETTER), and we get 5.
    // 5 is the array number for the word 'f' in the int POINTS[]. the points for f is 4 points.
    // and so on

    // loop for how long the string is
    for(int i = 0; i < test; i++)
    {
        if(isupper(word[i]) && (word[i] >= 65) && (word[i] <= 122))
        {
            score += POINTS[word[i] - 'A'];
        }
        else if (islower(word[i]) && (word[i] >= 65) && (word[i] <= 122))
        {
            score += POINTS[word[i] - 'a'];
        }
    }
    return score;
    // TODO: Compute and return score for string
}

