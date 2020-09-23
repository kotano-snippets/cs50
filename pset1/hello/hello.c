#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Ask user to enter his name and greet him.
    string name = get_string("What is your name?\n");
    if (name)
    {
        printf("Hello, %s", name);
    }
    else
    // If user entered empty string, say hello to the world.
    {
        printf("Hello, world\n");
    }
}