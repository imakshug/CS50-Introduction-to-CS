

// Include standard input/output library
#include <stdio.h>
// Include CS50 library for get_int
#include <cs50.h>

int main(void)
{
    // Declare variable for pyramid height
    int height;
    // Prompt user for a height between 1 and 8 (inclusive)
    do
    {
        height = get_int("Enter Height: ");
    } while (height < 1 || height > 8);

    // Loop through each row of the pyramid
    for (int i = 0; i < height; i++)
    {
        // Print spaces for left pyramid alignment
        for (int j = 0; j < height - i - 1; j++)
        {
            printf(" ");
        }
        // Print left pyramid hashes
        for (int k = height - i - 1; k < height; k++)
        {
            printf("#");
        }
        // Print the gap between pyramids
        printf("  ");
        // Print right pyramid hashes
        for (int l = 0; l < i + 1; l++)
        {
            printf("#");
        }
        // Move to the next line after each row
        printf("\n");
    }
}