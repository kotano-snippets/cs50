#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <stdlib.h>

void send_help(void)
{
    printf("Usage: ./caesar key\n");
}

bool is_number(string arg)
{
    for (int i = 0; arg[i] != '\0'; i += 1)
    {
        if (!isdigit(arg[i]))
        {
            return false;
        }
    }
    return true;
}

int main(int argc, string argv[2])
{
    // Validate arguments
    if (argc != 2) {
        send_help();
        return 1;
    }
    else if (!is_number(argv[1]))
    {
        send_help();
        return 1;
    }

    // Encode the text
    int key = atoi(argv[1]) % 26;
    string plaintext = get_string("plaintext: ");
    printf("ciphertext: ");
    for (int i = 0; plaintext[i] != '\0'; i += 1)
    {
        int c = (int) plaintext[i] + key;
        if (!isalpha(plaintext[i]))
        {
            printf("%c", plaintext[i]);
        }
        else if ((isupper(plaintext[i]) && c > 90) || (islower(plaintext[i]) && c > 122))
        {
            printf("%c", c - 26);
        }
        else
        {
            printf("%c", c);
        }
    }
    printf("\n");
}