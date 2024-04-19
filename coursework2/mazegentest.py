import sys
import random

def main():
    global maze, width, height
    maze = []
    width = int(sys.argv[1])
    height = int(sys.argv[2])

    # Creating a maze full of walls
    for i in range(height):
        line = ['#'] * width
        maze.append(line)

    x = random.randint(0, width - 1)
    y = random.randint(0, height - 1)
    maze[y][x] = ' '
    walls = []
    addWalls(y, x, walls)

    while walls:
        randWall = random.choice(walls)
        x, y = randWall[1], randWall[0]

        adjacent_cells = []

        if x - 2 >= 0 and maze[y][x - 2] == '#':
            adjacent_cells.append((y, x - 2))
        if x + 2 < width and maze[y][x + 2] == '#':
            adjacent_cells.append((y, x + 2))
        if y - 2 >= 0 and maze[y - 2][x] == '#':
            adjacent_cells.append((y - 2, x))
        if y + 2 < height and maze[y + 2][x] == '#':
            adjacent_cells.append((y + 2, x))

        if adjacent_cells:
            random_adjacent_cell = random.choice(adjacent_cells)
            adj_y, adj_x = random_adjacent_cell
            maze[adj_y][adj_x] = ' '
            maze[(adj_y + y) // 2][(adj_x + x) // 2] = ' '
            addWalls(y, x, walls)
            addWalls(adj_y, adj_x, walls)

        walls.remove((y, x))

    writeToFile(maze)

def addWalls(y, x, walls):
    if x - 2 >= 0:
        walls.append((y, x - 2))
    if x + 2 < width:
        walls.append((y, x + 2))
    if y - 2 >= 0:
        walls.append((y - 2, x))
    if y + 2 < height:
        walls.append((y + 2, x))

def writeToFile(maze):
    with open("maze.txt", "w") as file:
        for row in maze:
            file.write(''.join(row) + '\n')

main()
