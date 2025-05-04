#include <stdio.h>
#include <string.h>

typedef struct {
    char name[25];
    int number;
} Player;

int main() {
    Player players[10];
    snprintf(players[0].name, sizeof(players[0].name), "%s", "kha");
    players[0].number = 21;
    snprintf(players[1].name, sizeof(players[1].name), "%s", "lily");
    players[1].number = 19;
    
    printf("hi %s", players[0].name);
    printf("hi %s", players[1].name);

    char Winners[2][60]; // array of strings, first value is how many strings, second value is the max length of each string

    snprintf(Winners[0], sizeof(Winners[0]), "%s has won with the number: %d", players[0].name, players[0].number);
    snprintf(Winners[1], sizeof(Winners[1]), "%s has won with the number: %d", players[1].name, players[1].number);
    printf("\n%s", Winners[0]);

    // test the for loop for winners with players
    for (int i = 0; i < sizeof(Winners)/sizeof(Winners[0]); i++) {
        printf("\n%d", i);
        printf("\n%s", Winners[i]);
    }
}