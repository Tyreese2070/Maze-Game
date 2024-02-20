#include <stdio.h>
#include <stdlib.h>

// Maze game

struct Maze{
    int width;
    int height;
    char mazeLayout;
    char filepath[50];
};

struct Player{
    char username[20];
    int playerPosition;

};

// Move the user
void moveCharacter(char userInput){
}

// Load maze file
void getMaze(){
}

// View an image of the map
void viewMap(){
}

// Main with command line args
int main(char argc, char *argv[])
{
    // Get username
    char username[20];
    printf("Enter a username: ");
    scanf("%s", &username);
    struct Player player = {username, 0};

    // Declare an array for the player
    // Declare an array for the maze

    // read in the maze file

    // Validate maze file

    // Display the maze

    // Check for user input

    // Check for game events

    // Quit the game
    return 0;
}