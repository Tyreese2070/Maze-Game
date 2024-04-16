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

int main(int argc, char *argv[]){

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
        return 1;
    }

    // Reading from the file and adding it to the map array
    else
    {
        while (fgets(line_buffer, buffer_size, file) != NULL)
        {
            for (int i = 0; i < strlen(line_buffer); i++){
                strcpy(maze.map[i][maze.height], line_buffer[i]);
            }
            maze.height++;
        }
        fclose(file);
    }

    for (int i = 0; i < maze.width; i++){
        for (int j = 0; j < maze.height; j++){
            if (i = maze.width){
                printf("%s\n", maze.map[i][j]);
            }
            printf("%s", maze.map[i][j]);
        }
    }

    return 0;
}