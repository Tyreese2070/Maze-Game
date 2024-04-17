#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define maxWidth 100
#define maxHeight 100

struct Maze{
    int width;
    int height;
    char map[maxWidth][maxHeight];
    int winX, winY, startX, startY;
};

// Maze coordinates are (y,x).

void viewMaze(struct Maze maze, int startX, int startY){
    // Printing the maze
    if (maze.map[startY][startX] != 'X'){
        maze.map[startY][startX] = 'S';
    }

    for (int i = 0; i < maze.height; i++) {
        printf("%.*s\n", maze.width, maze.map[i]);
    }
}

void getCoords(struct Maze maze, char key, int *xpos, int *ypos){
    for (int i = 0; i < maze.height; i++) {
        for (int j = 0; j < maze.width; j++) {
            char current_char = maze.map[i][j];
            if (key == current_char){
                *xpos = j;
                *ypos = i;
                return;
                // return i, j; returning i as 0?
            }
        }
    }
    // key not found
    *xpos, *ypos = -1;
}

int validateMaze(struct Maze maze){
    if (maze.width < 5 || maze.width > 100 || maze.height < 5 || maze.height > 100){
        return 3;
    }

    for (int i = 0; i < maze.height; i++) {
        for (int j = 0; j < maze.width; j++) {
            char current_char = maze.map[i][j];
            if (current_char != 'X' || current_char != ' '|| current_char != 'E' || current_char != 'S' || current_char != '#'){
                return 3;
            }
        }
    }

}

// Handle the key inputs from the user
struct Maze handleMovement(struct Maze maze, char input){
    input = tolower(input);
    int x, y = -1;
    getCoords(maze, 'X', &x, &y);

    // Right
    if (input == 'd'){        
        if (x + 1 == maze.width){
            printf("Exceeded map limit (%d, %d)\n", y, x);
            return maze;
        }

        else if(maze.map[y][x+1] == '#'){
            printf("Hit wall, (%d, %d)\n", x, y);
            return maze;
        }

        maze.map[y][x] = ' ';
        maze.map[y][x+1] = 'X';
        return maze;
    }

    // Left
    if (input == 'a'){        
        if (x - 1 == maze.width){
            printf("Exceeded map limit (%d, %d)\n", y, x);
            return maze;
        }

        else if(maze.map[y][x-1] == '#'){
            printf("Hit wall, (%d, %d)\n", x, y);
            return maze;
        }

        maze.map[y][x] = ' ';
        maze.map[y][x-1] = 'X';
        return maze;
    }

    // Up
    if (input == 'w'){        
        if (y - 1 == maze.width){
            printf("Exceeded map limit (%d, %d)\n", y, x);
            return maze;
        }

        else if(maze.map[y-1][x] == '#'){
            printf("Hit wall, (%d, %d)\n", x, y);
            return maze;
        }

        maze.map[y][x] = ' ';
        maze.map[y-1][x] = 'X';
        return maze;
    }

    // Down
    if (input == 's'){        
        if (y + 1 == maze.width){
            printf("Exceeded map limit (%d, %d)\n", y, x);
            return maze;
        }

        else if(maze.map[y+1][x] == '#'){
            printf("Hit wall, (%d, %d)\n", x, y);
            return maze;
        }

        maze.map[y][x] = ' ';
        maze.map[y+1][x] = 'X';
        return maze;
    }

    printf("Invalid input\n");
}

int checkWin(struct Maze maze){
    int x, y = -1;
    getCoords(maze, 'X', &x, &y);
    if (x == maze.winX && y == maze.winY){
        return 1;
    }
    return 0;
}

int main(int argc, char *argv[]){

    char userInput;

    // Declare struct for the maze
    struct Maze maze;
    maze.height = 0;
    maze.width = 0;

    // Validate filetype and args
    if (argc != 2)
    {
        printf("Invalid input\n");
        return 1;
    }

    int buffer_size = 1024;
    char line_buffer[buffer_size];
    char data[100];

    // Opening the file
    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("Error: Could not open file\n");
        return 2;
    }

    // Reading from the file and adding it to the map array
    else
    {
        while (fgets(line_buffer, buffer_size, file) != NULL)
        {
            maze.width = strlen(line_buffer);
            for (int i = 0; i < strlen(line_buffer); i++){
                maze.map[maze.height][i] = line_buffer[i];
            }
            maze.height++;
        }
        fclose(file);
        printf("Maze loaded successfully\n");
    }

    // Initializing maze variables
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

        if (tolower(userInput) == 'q'){
            break;
        }

        else if (tolower(userInput) == 'm'){
            viewMaze(maze, maze.startX, maze.startY);
        }
        
        else{
            maze = handleMovement(maze, userInput);
        }

        if (checkWin(maze) == 1){
            viewMaze(maze, maze.startX, maze.startY);
            printf("Congratulations, you win!!\n");
            break;
        }
    }

    return 0;
}