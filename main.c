// Blackjack - Script by Khalil
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

typedef struct {
    char name[25];
    int number;
} Player;

int DrawCard(Player player) {
    int card = (rand() % 11) + 1; // Always starts at 0 so add 1
    player.number += card;

    printf("%s drew the number: %d", player.name, card);
    printf("Their total is now: %s", player.number);

    return player.number;
}

int main() {
    srand(time(0));
    char num_of_players[25];    
    bool valid_input = false;

    printf("\n----------------------------------------\n");
    printf("Welcome to Blackjack! This is my project coded in C!\n");
    printf("How many players are there?: ");

    while(!valid_input) {
        fgets(num_of_players, sizeof(num_of_players), stdin);

        // Remove newline if there is one
        num_of_players[strcspn(num_of_players, "\n")] = 0;
        
        // Checking if a number was entered
        valid_input = true;
        for (int i = 0; num_of_players[i] != '\0'; i++) {
            if (num_of_players[i] < '0' || num_of_players[i] > '9') {
                valid_input = false;
                printf("Wrong input, numbers only. How many players are there?: ");
                break;
            }
        }
    }
    
    // Convert it into an integer
    int num_players = atoi(num_of_players) + 1; // cancels out i = 1;
    
    Player Players[10]; // Making a list of all of the Players
    char input_name[25];
    // Getting all of the Players
    for (int i = 1; i < num_players; i++)
    {   
        memset(input_name, 0 , sizeof(input_name)); // cleanup
        
        printf("What is Player %d's Name?: ", i);
        fgets(input_name, sizeof(input_name), stdin);
        
        // Again removing new line
        input_name[strcspn(input_name, "\n")] = 0;
        
        // Making each Player
        snprintf(Players[i].name, sizeof(Players[i].name), "%s", input_name);
        Players[i].number = 0;
    }
    
    // Starting the Game for each Player
    for (int i = 1; i < num_players; i++ ) 
    {
        printf("\nHi %s, here is your First Draw!\n", Players[i].name);
        Players[i].number = DrawCard(Players[i]);
        // breaks here, literally just stops after it draws the card for some reason

        char answer;

        printf("\nWould you like to draw another card? Y/N: ");
        fgets(answer, sizeof(answer), stdin);

        if (answer == "Y") 
        {
            printf("\n----------------------------------------\n");
            Players[i].number = DrawCard(Players[i]);
        } 
        else if (answer == "N") 
        {
            printf("You have finished with the number: %s", Players[i].number);
            printf("Now it's the Dealer's turn to draw");
        } 
        else 
        {
            printf("Give a correct input.");
        } 
    }

    return 0;
}

// printf("\nName: %s", Players[i].name);
// printf("Number: %d\n", Players[i].number);