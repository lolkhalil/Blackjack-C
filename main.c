// Blackjack - Script by Khalil
// gcc main.c -o main
#include <stdio.h>

int main() {
    printf("Welcome to Blackjack! This is my project coded in C!\n\n");
    
    int NumOfPlayers;    
    printf("How many players are there?:\n");

    while (NumOfPlayers == 0) // keeps going in an inf loop
    {
        scanf("%d", &NumOfPlayers); // might be because we are using a ptr?
        printf("Wrong input, numbers only. How many players are there?:\n");
        NumOfPlayers = 0;
    }

    for (int i = 0; i < NumOfPlayers; i++)
    {
        printf("hey dude");
    }
}