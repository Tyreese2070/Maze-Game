#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

#define maxWidth 100
#define maxHeight 100

struct Maze{
    int width;
    int height;
    char map[maxWidth][maxHeight];
    char filepath[150];
};

void getCoords(){}

// Move the user based on input
void moveCharacter(char userInput){
    // 'W' or 'w'- UP
    // 'A' or 'a'- LEFT
    // 'S' or 's' - DOWN
    // 'D' or 'd' - RIGHT
}

int search(char character)
{
    for (int i = 0; i <= maxWidth; i++){
        for (int j = 0; j <= maxHeight; j++){
            if maze.map[i][j] == character;
            return i, j;
        }
    }
    return 0;
}

// Load maze file
int loadMaze(){
    // load maze and store to struct
    int count = 0;
    int buffer_size = 1024;
    char line_buffer[buffer_size];

    // Adding to the struct and increasing the count to get the number of records
    char data[100];
    strcpy(data, filepath);
    FILE *file = fopen(data, "r");
    if (file == NULL)
    {
        printf("Error: Could not open file\n");
        return 1;
    }
    else
    {
        printf("File successfully loaded.\n");
        while (fgets(line_buffer, buffer_size, file) != NULL)
        {
            for(int i = 0; i < maxWidth; i++)
            {
                maze.map[i][count] = line_buffer[i];
            }
            count++;
        }
    }
    fclose(file);

    // Store each line

    // Close file
}

// View the map
void viewMap(){
    // Print out map from struct
}

// Validate the maze
int validateMaze(){
    /*
    Same Column length
    Same row length
    Contains only ' ', '#', 'S', 'E'
    Only one 'S', 'E'
    Don't have to be solvable
    */
}

// Main - inputs should be mazefile.txt
int main(int argc, char *argv[])
{

    // Declare struct for the maze
    struct Maze;

    // Validate filetype and args
    if (argc != 2)
    {
        printf("Invalid input\n");
        return 1;
    }

    char filepath[] = argv[1];

    FILE *file = fopen(filepath, "r");
    if (file == NULL)
    {
        perror("");
        return 1;
    }

    // read in the maze file
    int count = 0;
    int buffer_size = 1024;
    char line_buffer[buffer_size];

    // Adding to the struct and increasing the count to get the number of records
    loadMaze();
        // Replace start point with "X"

    // Validate maze file

    // Display the maze
        // Print out map file line by line


    // Gameplay loop

        // Check for user input, include lower and uppercase for each character

            // Do user action based on input
                // 'M' key for map
                // Standard movement keys (WASD) move the character
                // 'Q' key for quit

        // Check for game events after movement
            /*
            Check for walls
            Check for spaces
            Check for Exit - Return win message and end loop
            */

    // Quit the game

    return 0;
}