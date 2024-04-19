import sys
import random

global mazePath
global walls
global visited
global maze
global width, height
mazePath = []
walls = []
visited = []
maze = []
width = 0
height = 0

# Maze coordinates are (y,x)
def main():

    # Validate number of args
    if len(sys.argv)-1 != 2:
        print("Usage: python mazegen <width> <height>")
        return 1

    width = int(sys.argv[1])
    height = int(sys.argv[2])

    # Creating a maze full of walls
    for i in range(0, height):
        line = []
        for j in range(0, width):
            line.append('#')

        maze.append(line)

    x = random.randint(0, width-1)
    y = random.randint(0, height-1)
    maze[y][x] = ' '
    mazePath.append((y, x))
    visited.append((y,x))

    addWalls(y,x)

    while (len(walls) > 0):
        randWall = random.randint(0,len(walls)-1)
        x = walls[randWall][1]
        y = walls[randWall][0]

        if (y-1 >= 0 and y+1 <= height-1 and x+1 <= width-1 and x-1 >= 0):
            if (maze[y][x+1] in visited and maze[y][x-1] not in visited):
                maze[y][x] = ' '
                maze[y][x-1] = ' '
                visited.append((y,x))
                visited.append((y,x-1))
                addWalls(y,x-1)

            if (maze[y][x-1] in visited and maze[y][x+1] not in visited):
                maze[y][x] = ' '
                maze[y][x+1] = ' '
                visited.append((y,x))
                visited.append((y,x+1))
                addWalls(y,x-1)

            if (maze[y-1][x] in visited and maze[y+1][x] not in visited):
                maze[y][x] = ' '
                maze[y+1][x] = ' '
                visited.append((y,x))
                visited.append((y+1,x))
                addWalls(y-1,x)
            
            if (maze[y+1][x] in visited and maze[y-1][x] not in visited):
                maze[y][x] = ' '
                maze[y-1][x] = ' '
                visited.append((y,x))
                visited.append((y-1,x))
                addWalls(y+1,x)

        walls.remove((y,x))

    
    writeToFile(maze)

def addWalls(y, x):
    if (x - 1 >= 0):
        walls.append((y,x-1))
    if (x + 1 <= width-1):
        walls.append((y, x+1))
    if (y + 1 <= height-1):
        walls.append((y+1, x))
    if (y - 1 >= 0):
        walls.append((y-1, x))

# Writing maze to text file
def writeToFile(maze):
    file = open("maze.txt", "w")
    for i in range(0, len(maze)):
        for j in range(0, len(maze[i])):
            file.write(maze[i][j])
        if i != len(maze)-1:
            file.write("\n")
    file.close()

main()