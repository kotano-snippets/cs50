#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;

// Number of bytes in jpeg header
const int BLOCK_SIZE = 512;
const int HEADER_SIZE = 4;

int main(int argc, char *argv[])
{
    // Check proper usage
    if (argc < 2)
    {
        printf("Usage: ./recover [filename]\n");
        return 1;
    }

    FILE *input = fopen(argv[1], "r");
    FILE *output = NULL;

    // In unable to open file
    if (input == NULL)
    {
        printf("Could not open file.\n");
    }

    BYTE buffer[BLOCK_SIZE];
    char filename[8];
    int fileCounter = -1;

    // While possible to read file
    while (fread(buffer, BLOCK_SIZE, 1, input))
    {
        // If new block contains header of new jpeg file
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // Then it is a start of a new JPEG file
            if (output != NULL)
            {
                fclose(output);
            }
            fileCounter += 1;
            sprintf(filename, "%03i.jpg", fileCounter);
            output = fopen(filename, "w");
        }

        // If files sequence started
        if (fileCounter >= 0)
        {
            fwrite(buffer, BLOCK_SIZE, 1, output);
        }
    }
    fclose(input);
    fclose(output);
}