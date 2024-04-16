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

int getdata(char filename[30], char mode[2])
{
    // FitnessData data_array[100];
    int count = 0;
    int buffer_size = 1024;
    char line_buffer[buffer_size];
    char data[100];

    // Opening the file
    strcpy(data, filename);
    FILE *file = fopen(data, mode);
    if (file == NULL)
    {
        printf("Error: Could not open file\n");
        return -1;
    }
    else

    // Reading from the file and adding it to the array
    {
        while (fgets(line_buffer, buffer_size, file) != NULL)
        {
            count++;
        }
        fclose(file);
    }

    return count;
}

int main(int argc, char *argv[]){

    // Declare struct for the maze
    struct Maze maze;

    // Validate filetype and args
    if (argc != 2)
    {
        printf("Invalid input\n");
        return 1;
    }

    int count = 0;
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
            printf("%s", line_buffer);
            count++;
        }
        fclose(file);
    }

    return 0;
}