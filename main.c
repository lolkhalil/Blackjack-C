// Blackjack - Script by Khalil
// gcc main.c -o main
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Player {
    char name[25];
    int number;
};

int main() {
    char num_of_players[25];    
    bool valid_input = false;

    printf("\n----------------------------------------\n");
    printf("Welcome to Blackjack! This is my project coded in C!\n");
    printf("How many players are there?:\n");

    while(!valid_input) {
        fgets(num_of_players, sizeof(num_of_players), stdin);

        // Remove newline if there is one
        num_of_players[strcspn(num_of_players, "\n")] = 0;

        // Checking if a number was entered
        valid_input = true;
        for (int i = 0; num_of_players[i] != '\0'; i++) {
            if (num_of_players[i] < '0' || num_of_players[i] > '9') {
                valid_input = false;
                printf("Wrong input, numbers only. How many players are there?:\n");
                break;
            }
        }
    }
    
    // Convert it into an integer
    int num_players = atoi(num_of_players) + 1; // cancels out i = 1;

    struct Player Players[10];
    char input_name[25];
    for (int i = 1; i < num_players; i++)
    {   
        memset(input_name, 0 , sizeof(input_name)); // cleanup

        printf("What is Player %d's Name?:\n", i);
        fgets(input_name, sizeof(input_name), stdin);

        // Making each Player
        snprintf(Players[i].name, sizeof(Players[i].name), "%s", input_name);
        Players[i].number = i;

        // printf("Name: %s", Players[i].name);
        // printf("Number: %d", Players[i].number);
    }
}