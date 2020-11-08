#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <math.h>



int main(void)
{
    string text = get_string("Text: ");
    int text_len = strlen(text);
    if (text_len == 0)
    {
        return 1;
    }
    int letters_count = 0;
    int words_count = 1;
    int sentences_count = 0;

    for (int i = 0; i < text_len; i += 1)
    {
        if (isalpha(text[i]))
        {
            // word_length += 1;
            letters_count += 1;
        }
        else
        {
            // if current symbol is a whitespace
            if ((int) text[i] == 32)
            {
                words_count += 1;
            }
            // If current symbol is . or ! or ?
            if (text[i] == 33 || text[i] == 46 || text[i] == 63)
            {
                sentences_count += 1;
            }
            // if (word_length != 0) {
            //     words_count += 1;
            //     word_length = 0;
            // }
        }
    }

    // printf("%s\n", text);
    // printf("%i letter(s)\n", letters_count);
    // printf("%i word(s)\n", words_count);
    // printf("%i sentence(s)\n", sentences_count);
    float average_letters = (float) letters_count / words_count * 100;
    // printf("letters per 100 words %f\n", average_letters);
    float average_sentences = (float) sentences_count / words_count * 100;
    // printf("sentences per 100 words %f\n", average_sentences);
    int index = round(0.0588 * average_letters - 0.296 * average_sentences - 15.8);

    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
    return 0;
}