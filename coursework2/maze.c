#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define maxWidth 100
#define maxHeight 100

// struct for maze - coordinates are in the form (y,x)
struct Maze{
    int width;
    int height;
    char map[maxWidth][maxHeight];
    int winX, winY, startX, startY;

    // for error checking
    int err;
};

// Output the maze
void viewMaze(struct Maze maze){
    // Checking for player and start point overlap
    if (maze.map[maze.startY][maze.startX] != 'X'){
        maze.map[maze.startY][maze.startX] = 'S';
    }

    for (int i = 0; i < maze.height; i++) {
        printf("%.*s\n", maze.width, maze.map[i]);
    }
}

// Get coordinates of given character 
void getCoords(struct Maze maze, char key, int *xpos, int *ypos){
    for (int i = 0; i < maze.height; i++) {
        for (int j = 0; j < maze.width; j++) {
            char current_char = maze.map[i][j];
            if (key == current_char){
                *xpos = j;
                *ypos = i;
                return;
                // return i, j; //returning i as 0?
            }
        }
    }
    // key not found
    *xpos, *ypos = -1;
}

// Checks the maze meets specified requirements
int validateMaze(struct Maze maze){

    // Maze size checks
    if (maze.width < 5 || maze.width > 100 || maze.height < 5 || maze.height > 100){
        printf("Invalid dimensions. Width and height must be between 5-100.");
        return 3;
    }

    // Maze character checks
    for (int i = 0; i < maze.height; i++) {
        for (int j = 0; j < maze.width; j++) {
            char current_char = maze.map[i][j];
            if (current_char != ' ' && current_char != 'E' && current_char != 'S' && current_char != '#'){
                printf("Invalid characters\n");
                return 3;
            }
        }
    }

    // Checks maze dimensions are correct
    for (int i = 0; i < maze.height; i++){
        
        if (strlen(maze.map[i]) != maze.width){
            printf("Invalid maze");
            return 3;
            }
    }
    return 0;

}

// Handle the key inputs from the user
struct Maze handleMovement(struct Maze maze, char input){
    input = tolower(input);
    int x, y = -1;
    getCoords(maze, 'X', &x, &y);

    // Right
    if (input == 'd'){        
        if (x + 1 == maze.width){
            printf("Exceeded map limit\n");
            return maze;
        }

        else if(maze.map[y][x+1] == '#'){
            printf("Hit wall\n");
            return maze;
        }

        maze.map[y][x] = ' ';
        maze.map[y][x+1] = 'X';
        return maze;
    }

    // Left
    if (input == 'a'){        
        if (x - 1 == maze.width){
            printf("Exceeded map limit\n");
            return maze;
        }

        else if(maze.map[y][x-1] == '#'){
            printf("Hit wall\n");
            return maze;
        }

        maze.map[y][x] = ' ';
        maze.map[y][x-1] = 'X';
        return maze;
    }

    // Up
    if (input == 'w'){        
        if (y - 1 == maze.width){
            printf("Exceeded map limit\n");
            return maze;
        }

        else if(maze.map[y-1][x] == '#'){
            printf("Hit wall\n");
            return maze;
        }

        maze.map[y][x] = ' ';
        maze.map[y-1][x] = 'X';
        return maze;
    }

    // Down
    if (input == 's'){        
        if (y + 1 == maze.width){
            printf("Exceeded map limit\n");
            return maze;
        }

        else if(maze.map[y+1][x] == '#'){
            printf("Hit wall\n");
            return maze;
        }

        maze.map[y][x] = ' ';
        maze.map[y+1][x] = 'X';
        return maze;
    }

    printf("Invalid input\n");
}

// Checks if the user has reached the exit
int checkWin(struct Maze maze){
    int x, y = -1;
    getCoords(maze, 'X', &x, &y);
    if (x == maze.winX && y == maze.winY){
        return 1;
    }
    return 0;
}

struct Maze readFile(char filepath[]){
    struct Maze maze;
    maze.err = 0;

    int buffer_size = 1024;
    char line_buffer[buffer_size];
    char data[100];

    // Opening the file
    FILE *file = fopen(filepath, "r");
    if (file == NULL)
    {
        printf("Error: Could not open file\n");
        maze.err = 2;
        return maze;
    }

    // Reading from the file and adding it to the map
    else
    {
        while (fgets(line_buffer, buffer_size, file) != NULL)
        {
            // Removing new line character
            line_buffer[strcspn(line_buffer, "\n")] = '\0';
            maze.width = strlen(line_buffer);

            for (int i = 0; i < strlen(line_buffer); i++){
                maze.map[maze.height][i] = line_buffer[i];
            }
            maze.height++;
        }
        fclose(file);
        printf("Maze loaded successfully\n");
    }

    return maze;
}

int main(int argc, char *argv[]){

    char userInput;

    // Declare struct for the maze
    struct Maze maze;
    maze.height = 0;
    maze.width = 0;

    // Validate args
    if (argc != 2)
    {
        printf("Usage: ./maze <maze filepath>\n");
        return 1;
    }

    maze = readFile(argv[1]);
    if (maze.err == 2){
        return 2;
    }

    if (validateMaze(maze) == 3){
        printf("Invalid maze\n");
        return 3;
    }

    // Initializing maze struct variables
    // Set the coordinates of the exit point
    getCoords(maze, 'E', &maze.winX, &maze.winY);

    // Placing the user at the start point
    int x, y;
    getCoords(maze, 'S', &x, &y);
    maze.map[y][x] = 'X';
    maze.startX = x;
    maze.startY = y;

    // Gameplay loop
    while (1){
        printf("Input: ");
        scanf(" %c", &userInput);
        printf("\n");

        // Quit
        if (tolower(userInput) == 'q'){
            break;
        }

        // View maze
        else if (tolower(userInput) == 'm'){
            viewMaze(maze);
        }
        
        // Movement
        else{
            maze = handleMovement(maze, userInput);
        }

        // Check for win
        if (checkWin(maze) == 1){
            viewMaze(maze);
            printf("Congratulations, you win!!\n");
            break;
        }
    }

    return 0;
}