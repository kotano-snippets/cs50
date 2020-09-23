#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height;
    // Ask user to input number between 1 and 8.
    do
    {
        height = get_int("Height: ");
    } // If incorrect input, ask again.
    while (!height || height < 1 || height > 8);
    
    for (int line = 1; line <= height; line += 1)
    {
        for (int col = 0; col < height; col += 1)
        {
            // Print empty space if not reach the mountain.
            if (col < height - line)
            {
                printf(" ");
            }
            // Print first part of the mountain.
            else
            {
                printf("#");
            }
        }
        // Add two spaces between the top edges of the mountain.
        printf("  ");
        for (int i = 0; i < line; i += 1)
        {
            // Print second part of the mountain.
            printf("#");
        }
        printf("\n");
    }
}
