#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_letter(string temp);
int count_word(string temp);
int count_sent(string temp);
int index(int letter, int sent, int word);
int main(void)
{
    string input = get_string("Text: ");
    // int length = strlen(input);

    int letterCount = count_letter(input);
    int wordCount = 0;
    int sentCount = 0;

    if(letterCount>0)
    {
        wordCount = count_word(input);
        sentCount = count_sent(input);
    }
    int indexGrading = index(letterCount, sentCount, wordCount);
    if(indexGrading >= 16)
    {
        printf("Grade 16+\n");
    }
    else if(indexGrading < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", indexGrading);
    }
    // printf("Jumlah huruf= %i\n",letterCount);
    // printf("Jumlah kata= %i\n",wordCount);
    // printf("Jumlah kalimat= %i\n",sentCount);
}
// countint letter, if an input on i is a to z or A to Z, counting up by 1
int count_letter(string temp)
{
    int count = 0;
    for(int i = 0; temp[i] != '\0'; i++)
    {
        if(isalpha(temp[i]))
        {
            count++;
        }
    }
    return count;
}

// counting word. word are counted if theres is a space, but there are no space after it, "fawwaz m". is 2 word, "fawwaz   m" is 2 word
// \0 meain
int count_word(string temp)
{
    int count = 0;
    for(int i = 0; temp[i] != '\0'; i++)
    {
        if(((temp[i] == ' ' && temp[i+1] != ' ')|| temp[i+1] == '\0')  )
        {
            count++;
        }
    }
    return count;
}
//counting senteces, if i is !,?,or.
int count_sent(string temp)
{
    int count = 0;
    for(int i = 0; temp[i] != '\0'; i++)
    {
        if(temp[i] == '!' || temp[i] == '?' || temp[i] == '.')
        {
            count++;
        }
    }
    return count;
}
// the math too know the grading
// its float because its gonna be decimal
int index(int letter, int sent, int word)
{
    float L = (float)letter/(float)word * 100;
    float S = (float)sent/(float)word * 100;
    int index = round(0.0588 * L - 0.296 * S - 15.8);
    return index;
}