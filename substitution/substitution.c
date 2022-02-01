#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

int check_key (string key);

int main (int argc, string argv[])
{
    string key = argv[1];

    if (argc == 2)
    {
        int check_result = check_key(key);
        if (check_result == -1)
        {
            printf("Key must contain 26 characters.\n");
            return 1;
        }
        else if (check_result == -2)
        {
            printf("All characters should be from the alphabet.\n");
            return 1;
        }
        else if (check_result == -3){
            printf("Characters cannot be repeated.\n");
            return 1;
        }
    }
    else {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    string plain_text = get_string("plaintext: ");
    int plain_length = strlen(plain_text);
    char cipher_text[plain_length];

    for (int i = 0; i < plain_length; i++)          // Convert the plain text to cipher text without needing to change to upper/lower case
    {
        if (isalpha(plain_text[i])) {

            cipher_text[i] = islower(plain_text[i])
            ? tolower(key[plain_text[i] - 97])
            : toupper(key[plain_text[i] - 65]);
        }
        else
        {
            cipher_text[i] = plain_text[i];
        }
    }

    printf("ciphertext: %s\n",cipher_text);
    return 0;
}

int check_key (string key)
{
    int key_length = strlen(key);
    int letters_counter[26] = {};

    // Verify if the key has 26 characters, if not return -1
    if (key_length != 26)
    {
        return -1;
    }

    // Verify if all of the characters is an alphabeltical char, if not returns -2
    for (int i = 0; i < key_length; i++)
    {
        if (!isalpha(key[i]))
        {
            return -2;
        }
    }

    // Count the number of the same letter putting in an array, the 0 index of letters_counter can be interpreted as the quantity of A's
    for (int i = 0; i < key_length; ++i)
    {
        int upper_char = toupper(key[i]);
        letters_counter[upper_char - 65]++;
    }

    // Verify if an character was repeated, if was return -3
    for (int i = 0; i < key_length; i++)
    {
        if (letters_counter[i] > 1)
        {
            return -3;
        }
    }
    return 0; // If all the tests pass, return 0
}