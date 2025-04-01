// Blackjack - Script by Khalil
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

// Making it more interactive
void Sleeps(int num) {
    #ifdef _WIN32
        Sleep(num * 1000); // Windows: milliseconds
    #else
        sleep(num);    // Linux: seconds
    #endif
}

typedef struct {
    char name[25];
    int number;
} Player;

int DrawCard(Player *player) {
    int card = (rand() % 11) + 1; // Always starts at 0 so add 1
    player->number += card;

    printf("%s drew the number: %d\n", player->name, card);
    printf("Their total is now: %d", player->number);

    return player->number;
}

int main() {
    srand(time(0)); // initalize rand() 
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
        Players[i].number = DrawCard(&Players[i]);
        
        bool lost = false;
        while (true) {
            // Not tested yet
            if (Players[i].number > 21) {
                printf("\n%s has lost!\n", Players[i].name);
                lost = true;
                Sleeps(2);
                break;
            } else if (Players[i].number == 21) {
                printf("\nLucky break! You got 21. Now it's the Dealer's turn to draw.\n");
                Sleeps(2);
                break;
            } 
            // 

            char answer;
            printf("\nWould you like to draw another card? Y/N: ");
            scanf(" %c", &answer); // need the space before the %c or errors
            
            if (toupper(answer) == 'Y'){
                printf("\n----------------------------------------\n");
                Players[i].number = DrawCard(&Players[i]);
            } else if (toupper(answer) == 'N') {
                printf("You have finished with the number: %d\n", Players[i].number);
                printf("Now it's the Dealer's turn to draw\n");
                Sleeps(2);
                break;
            } else {
                printf("Give a correct input.");
            }
        }

        // dealer's code goes here
    }

    return 0;
}

// printf("\nName: %s", Players[i].name);
// printf("Number: %d\n", Players[i].number);