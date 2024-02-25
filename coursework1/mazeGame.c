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

// View the map
void viewMap(){
}

// Validate the maze
int validateMaze(){
    int valid = 1;

    if(valid==0){
        return 1;
    }
    else{
        return 0;
    }
}

// Main - inputs should be mazefile.txt
int main(int argc, char *argv[])
{
    // Get username
    char username[20];

    // Declare an array for the player
    // Declare an array for the maze

    // read in the maze file

    // Validate maze file
        /*
        Same Column length
        Same row length
        Contains only ' ', '#', 'S', 'E'
        Only one 'S', 'E'
        Don't have to be solvable
        */

    // Display the maze
        // Display user as X

    // Check for user input

    // Check for game events after movement
        /*
        Check for walls
        Check for spaces
        Check for 'M' key for map
        */

    // Quit the game

    if (argc != 2)
    {
        printf("Invalid input\n");
    }

    printf("########\n##X   E#\n####  ##\n#####   \n########\n");


    return 0;
}