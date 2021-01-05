#include <math.h>
#include <stdio.h>

#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE pixel;
    BYTE midvalue;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Find average color value
            pixel = image[i][j];
            midvalue = (BYTE)round((pixel.rgbtBlue + pixel.rgbtGreen + pixel.rgbtRed) / 3.);
            image[i][j].rgbtBlue = image[i][j].rgbtGreen = image[i][j].rgbtRed = midvalue;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    BYTE originalRed, originalGreen, originalBlue;
    float sepiaRed, sepiaGreen, sepiaBlue;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            originalRed = image[i][j].rgbtRed;
            originalGreen = image[i][j].rgbtGreen;
            originalBlue = image[i][j].rgbtBlue;

            // Find sepia value for each color
            sepiaRed = .393 * originalRed + .769 * originalGreen + .189 * originalBlue;
            sepiaGreen = .349 * originalRed + .686 * originalGreen + .168 * originalBlue;
            sepiaBlue = .272 * originalRed + .534 * originalGreen + .131 * originalBlue;

            // Make sure we don't exceed 255 bits value
            image[i][j].rgbtRed = (sepiaRed > 255) ? 255 : (BYTE)round(sepiaRed);
            image[i][j].rgbtGreen = (sepiaGreen > 255) ? 255 : (BYTE)round(sepiaGreen);
            image[i][j].rgbtBlue = (sepiaBlue > 255) ? 255 : (BYTE)round(sepiaBlue);
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // Find center of the image
    int halfWidth = width / 2;
    RGBTRIPLE pixel;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < halfWidth; j++)
        {

            pixel = image[i][j];
            // width - 1 because we don't have pixel at index `width`
            image[i][j] = image[i][width - 1 - j];
            image[i][width - 1 - j] = pixel;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE imgCopy[height][width];

    // Make copy of original image
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            imgCopy[h][w] = image[h][w];
        }
    }

    int totalRed;
    int totalGreen;
    int totalBlue;
    float counter;

    // Iterate through each pixel
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            // Prepare values
            totalRed = 0;
            totalGreen = 0;
            totalBlue = 0;
            counter = 0.0;

            // Iterate through neighbours
            for (int i = -1; i <= 1; i++)
            {
                for (int j = -1; j <= 1; j++)
                {
                    // If exceeded upper bound go lower
                    if (h + i < 0)
                    {
                        i++;
                    }
                    // If exceeded left bound go right
                    if (w + j < 0)
                    {
                        j++;
                    }
                    // If exceeded lower bound or right bound skip
                    if (h + i >= height || w + j >= width)
                    {
                        continue;
                    }
                    // Sum values of colors
                    totalRed += imgCopy[h + i][w + j].rgbtRed;
                    totalGreen += imgCopy[h + i][w + j].rgbtGreen;
                    totalBlue += imgCopy[h + i][w + j].rgbtBlue;

                    // Count neighbor pixels
                    counter += 1;
                }
            }
            // Calculate average value, round it and set new pixel value
            image[h][w].rgbtRed = (BYTE)round(totalRed / counter);
            image[h][w].rgbtGreen = (BYTE)round(totalGreen / counter);
            image[h][w].rgbtBlue = (BYTE)round(totalBlue / counter);
        }
    }
    return;
}
