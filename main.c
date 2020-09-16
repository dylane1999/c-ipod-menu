#include "PlaylistNode.h"
#include <stdio.h>

// Declare a character array variable to store title

char pTitle[50] = "";

// Create main method to run the program

int main(void)

{

     printf("Enter playlist's title:\n\n");

     scanf(" %50[^\n]", pTitle);

     // Call the method named "PrintMenu"
     PrintMenu(pTitle);

  

     return 0;

}