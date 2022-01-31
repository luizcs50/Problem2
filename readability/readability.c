#include <cs50.h>
#include <string.h>
#include <math.h>
#include <stdio.h>

int countLetters(string text, int len);
int countWords (string text, int len);
int countSentences (string text, int len);
float getIndex (int lettersCount, int wordsCount, int sentencesCount);

int main (void)
{
    string text = get_string("Text: ");
    int length = strlen(text),
        wordsCount = countWords (text, length),
        lettersCount = countLetters(text, length),
        sentencesCount = countSentences (text, length);

    int grade = round(getIndex(lettersCount, wordsCount, sentencesCount));

    if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %d\n", grade);
    }

    return 1;
}


int countLetters (string text, int len)
{
    int count = 0;
    for (int i = 0; i < len; i++)
    {
        if ( (text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z') )
        {
            count++;
        }
    }
    return count;
}

int countWords (string text, int len)
{
    int count = 0;

    for (int i = 0; i < len; i++)
    {
        if (text[i] == ' ')
        {
            count++;
        }

    }

    return count + 1;
}

int countSentences (string text, int len)
{
    int count = 0;

    for (int i = 0; i < len; i++)
    {
        if (text[i] == '!' || text[i] == '.' || text[i] == '?' )
        {
            count++;
        }
    }

    return count;
}

float getIndex (int lettersCount, int wordsCount, int sentencesCount)
{
    return 0.0588 * lettersCount / wordsCount * 100 - 0.296 * sentencesCount / wordsCount * 100 - 15.8; // Coleman-Liau Index
}