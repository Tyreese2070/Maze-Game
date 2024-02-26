gcc maze.c -o maze

echo "-----Testing Args-----"

# Test 1 - Checking for no file input - Expected: Arg should be map text file
echo -n "1. No args: "
./maze > tmp
if grep -q "Invalid input" tmp;
then
    echo "PASS"
else
    echo "FAIL"
    cat tmp 
fi

# Test 2 - Too many args - Expected: only arg should be map text file
echo -n "2. Too many args: "
./maze x x > tmp
if grep -q "Invalid input" tmp;
then
    echo "PASS"
else
    echo "FAIL"
    cat tmp 
fi

echo
echo "-----Testing FILE I/O-----"

# Test 1 - Incorrect filetype - Expected: Should be .txt file

echo -n "1. Incorrect filetype: "
./maze tests/maze1.csv > tmp
if grep -q "Error: Invalid filetype" tmp;
then
    echo "PASS"
else
    echo "FAIL"
    cat tmp
fi

# Test 2 - No start point - Expected: Maps should have a start point("S")

echo -n "2. No start point on map: "
./maze tests/invalidmaps/nostart.txt > tmp
if grep -q "Error: No start on map" tmp;
then
    echo "PASS"
else
    echo "FAIL"
    cat tmp
fi

# Test 3 - No end point  - Expected: Maps should have an end point("E")

echo -n "3. No end point on map: "
./maze tests/invalidmaps/noend.txt > tmp
if grep -q "Error: No exit on map" tmp;
then
    echo "PASS"
else
    echo "FAIL"
    cat tmp
fi

# Test 4 - Invalid map characters - Expected: Maps should only contain " ", "S", "E"

echo -n "4. Invalid map characters: "
./maze tests/invalidmaps/invalidchar.txt > tmp
if grep -q "Error: Invalid characters on map" tmp;
then
    echo "PASS"
else
    echo "FAIL"
    cat tmp
fi

# Test 5 - Invalid width (<5)  - Expected: Map width should be between 5-100

echo -n "5. Map width < 5: "
./maze tests/invalidmaps/smallmap.txt > tmp
if grep -q "Error: Map width is less than 100" tmp;
then
    echo "PASS"
else
    echo "FAIL"
    cat tmp
fi

# Test 6 - Invalid width (>100)  - Expected: Map width should be between 5-100

echo -n "6. Map width > 100: "
./maze tests/invalidmaps/largemap.txt > tmp
if grep -q "Error: Map width is greater than 100" tmp;
then
    echo "PASS"
else
    echo "FAIL"
    cat tmp
fi

# Test 7 - Invalid height (<5)  - Expected: Height should be between 5-100

echo -n "7. Map height < 5: "
./maze tests/invalidmaps/smallmap.txt > tmp
if grep -q "Error: Map height is less than 5" tmp;
then
    echo "PASS"
else
    echo "FAIL"
    cat tmp
fi

# Test 8 - Invalid height (>100) - Expected: height should be between 5-100

echo -n "8. Map height > 100: "
./maze tests/invalidmaps/largemap.txt > tmp
if grep -q "Error: Map height is greater than 100" tmp;
then
    echo "PASS"
else
    echo "FAIL"
    cat tmp
fi

# Test 9 - Unequal rows  - Expected: Row lengths should be the same

echo -n "9. Row lengths not the same: "
./maze tests/invalidmaps/unequalmap.txt > tmp
if grep -q "Error: Row lengths are unequal" tmp;
then
    echo "PASS"
else
    echo "FAIL"
    cat tmp
fi

# Test 10 - Unequal columns  - Expected: Column lengths should be the same

echo -n "10. Column lengths not the same: "
./maze tests/invalidmaps/unequalmap.txt > tmp
if grep -q "Error: Column lengths are not the same" tmp;
then
    echo "PASS"
else
    echo "FAIL"
    cat tmp
fi

# Test 11 - Loads maze successfully  - Expected: Successful loading message should be seen on valid map input

echo -n "11. Maze loads successfully: "
./maze tests/validmaps/validmap1.txt > tmp
if grep -q "Map loaded successfully" tmp;
then
    echo "PASS"
else
    echo "FAIL"
    cat tmp
fi

echo
echo "-----Testing user input-----"

# Test 1 - Player moves up  - Expected: X character should be above user starting position
echo -n "1. Player moves up: "
echo "w" | ./maze tests/validmaps/movementmap.txt
if grep -q "#EX##" tmp;
then
    echo "PASS"
else
    echo "FAIL"
fi

# Test 2 - Player moves left  - Expected: X character should be to the left of starting position
echo -n "2. Player moves left: "
echo "a" | ./maze tests/validmaps/movementmap.txt
if grep -q "#X  #" tmp;
then
    echo "PASS"
else
    echo "FAIL"
fi

# Test 3 - Player moves down  - Expected: X character should be below the starting position
echo -n "3. Player moves down: "
echo "s" | ./maze tests/validmaps/movementmap.txt
if grep -q "##X##" tmp;
then
    echo "PASS"
else
    echo "FAIL"
fi

# Test 4 - player moves right  - Expected: X character should be to the right of the starting position
echo -n "4. Player moves right: "
echo "s" | ./maze tests/validmaps/movementmap.txt
if grep -q "#  X#" tmp;
then
    echo "PASS"
else
    echo "FAIL"
fi

# Test 5 - invalid input when playing - Expected: Only inputs should be "m" or movement keys
echo -n "5. Invalid input while playing: "
echo "e" | ./maze tests/validmaps/validmap1.txt > tmp
if grep -q "Error: Invalid input" tmp;
then
    echo "PASS"
else
    echo "FAIL"
    cat tmp 
fi

# Test 6 - Map displays correctly  - Expected: Map should appear showing user position as X and end position as E
echo -n "6. Map displays on 'M' key: "
echo "m" | ./maze tests/validmaps/validmap2.txt > tmp
if grep -q "##X   E#" tmp;
then
    echo "PASS"
else
    echo "FAIL"
fi

# Test 7 - Game quits of 'Q' press - Expected: Message is shown and game ends when user enters 'Q'
echo -n "7. Map displays on 'M' key: "
echo "q" | ./maze tests/validmaps/validmap2.txt > tmp
if grep -q "Game quit" tmp;
then
    echo "PASS"
else
    echo "FAIL"
fi

echo
echo "-----Testing game functionality-----"

# Test 1 - User hits wall  - Expected: User stays in the same position if trying to move into a wall

echo -n "1. User hits wall: "
echo "a"| echo "m" | ./maze tests/validmaps/validmap2.txt > tmp
if grep -q "##X   E#" tmp;
then
    echo "PASS"
else
    echo "FAIL"
    cat tmp
fi

# Test 2 - User exits maze  - Expected: Success message

echo -n "2. Exit maze successfully: "
echo "d" | echo "d" | echo "d" | echo "d" | ./maze tests/validmaps/validmap2.txt > tmp
if grep -q "Congratulations, you have won!" tmp;
then
    echo "PASS"
else
    echo "FAIL"
    cat tmp
fi

# Test 3 - User starts at correct point  - Expected: User X appears where starting position was

echo -n "3. User starts at correct point: "
./maze tests/validmaps/validmap2.txt > tmp
if grep -q "##X   E#" tmp;
then
    echo "PASS"
else
    echo "FAIL"
    cat tmp
fi

echo
echo "-----Testing valid maps-----"
# Testing various valid map files

echo -n "Maze map 1: "
./maze tests/validmaps/validmap3.txt > tmp
if grep -q "Map loaded successfully" tmp;
then
    echo "PASS"
else
    echo "FAIL"
    cat tmp
fi

echo -n "Maze map 2: "
./maze tests/validmaps/validmap4.txt > tmp
if grep -q "Map loaded successfully" tmp;
then
    echo "PASS"
else
    echo "FAIL"
    cat tmp
fi

echo -n "Maze map 3: "
./maze tests/validmaps/validmap5.txt > tmp
if grep -q "Map loaded successfully" tmp;
then
    echo "PASS"
else
    echo "FAIL"
    cat tmp
fi

echo -n "Maze map 4: "
./maze tests/validmaps/validmap6.txt > tmp
if grep -q "Map loaded successfully" tmp;
then
    echo "PASS"
else
    echo "FAIL"
    cat tmp
fi

echo -n "Maze map 5: "
./maze tests/validmaps/validmap7.txt > tmp
if grep -q "Map loaded successfully" tmp;
then
    echo "PASS"
else
    echo "FAIL"
    cat tmp
fi

# Testing max height and width
echo -n "Big maze map: "
./maze tests/validmaps/validmapMax.txt > tmp
if grep -q "Map loaded successfully" tmp;
then
    echo "PASS"
else
    echo "FAIL"
    cat tmp
fi

# Testing min height and width
echo -n "Small maze map: "
./maze tests/validmaps/validmapMin.txt > tmp
if grep -q "Map loaded successfully" tmp;
then
    echo "PASS"
else
    echo "FAIL"
    cat tmp
fi

echo
echo "-------Finished testing-------"

rm -r tmp