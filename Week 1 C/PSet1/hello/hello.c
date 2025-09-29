#include <cs50.h>  // Include CS50 library for get_string function
#include <stdio.h> // Include standard input/output library for printf

int main(void)
{
    // Prompt the user for their name and store it in the variable 'name'
    string name = get_string("What is your name?\n");

    // Print a personalized greeting using the user's name
    printf("hello, %s\n", name);
}
