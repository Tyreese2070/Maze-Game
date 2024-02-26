gcc maze.c -o maze

echo "-----Testing Args-----"

# Test 1 - Checking for no file input
echo -n "1. No args: "
./maze > tmp
if grep -q "Invalid input" tmp;
then
    echo "PASS"
else
    echo "FAIL"
    cat tmp 
fi

# Test 2 - Too many args
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

# Test 1 - Incorrect filetype

echo -n "1. Incorrect filetype: "
./maze tests/maze1.csv > tmp
if grep -q "Error: Invalid filetype" tmp;
then
    echo "PASS"
else
    echo "FAIL"
    cat tmp
fi

# Test 2 - No start point

echo -n "2. No start point on map: "
./maze tests/invalidmaps/nostart.txt > tmp
if grep -q "Error: No start on map" tmp;
then
    echo "PASS"
else
    echo "FAIL"
    cat tmp
fi

# Test 3 - No end point

echo -n "3. No end point on map: "
./maze tests/invalidmaps/noend.txt > tmp
if grep -q "Error: No exit on map" tmp;
then
    echo "PASS"
else
    echo "FAIL"
    cat tmp
fi

# Test 4 - Invalid map characters

echo -n "4. Invalid map characters: "
./maze tests/invalidmaps/invalidchar.txt > tmp
if grep -q "Error: Invalid characters on map" tmp;
then
    echo "PASS"
else
    echo "FAIL"
    cat tmp
fi

# Test 5 - Invalid width (<5)

echo -n "5. Map width < 5: "
./maze tests/invalidmaps/smallmap.txt > tmp
if grep -q "Error: Map width is less than 100" tmp;
then
    echo "PASS"
else
    echo "FAIL"
    cat tmp
fi

# Test 6 - Invalid width (>100)

echo -n "6. Map width > 100: "
./maze tests/invalidmaps/largemap.txt > tmp
if grep -q "Error: Map width is greater than 100" tmp;
then
    echo "PASS"
else
    echo "FAIL"
    cat tmp
fi

# Test 7 - Invalid height (<5)

echo -n "7. Map height < 5: "
./maze tests/invalidmaps/smallmap.txt > tmp
if grep -q "Error: Map height is less than 5" tmp;
then
    echo "PASS"
else
    echo "FAIL"
    cat tmp
fi

# Test 8 - Invalid height (>100)

echo -n "8. Map height > 100: "
./maze tests/invalidmaps/largemap.txt > tmp
if grep -q "Error: Map height is greater than 100" tmp;
then
    echo "PASS"
else
    echo "FAIL"
    cat tmp
fi

# Test 9 - Unequal rows

echo -n "9. Row lengths not the same: "
./maze tests/invalidmaps/unequalmap.txt > tmp
if grep -q "Error: Row lengths are unequal" tmp;
then
    echo "PASS"
else
    echo "FAIL"
    cat tmp
fi

# Test 10 - Unequal columns

echo -n "10. Column lengths not the same: "
./maze tests/invalidmaps/unequalmap.txt > tmp
if grep -q "Error: Column lengths are not the same" tmp;
then
    echo "PASS"
else
    echo "FAIL"
    cat tmp
fi

# Test 11 - Loads maze successfully

echo -n "11. Maze loads successfully: "
./maze tests/invalidmaps/unequalmap.txt > tmp
if grep -q "Map loaded successfully" tmp;
then
    echo "PASS"
else
    echo "FAIL"
    cat tmp
fi

echo
echo "-----Testing user input-----"

# Test 1 - Player moves up
echo -n "4. Player moves right: "
if grep -Fqx -f tests/validmaps/movementoutputs/uptest.txt tmp;
then
    echo "PASS"
else
    echo "FAIL"
fi

# Test 2 - Player moves left
echo -n "4. Player moves right: "
if grep -Fqx -f tests/validmaps/movementoutputs/lefttest.txt tmp;
then
    echo "PASS"
else
    echo "FAIL"
fi

# Test 3 - Player moves down
echo -n "3. Player moves down: "
if grep -Fqx -f tests/validmaps/movementoutputs/downtest.txt tmp;
then
    echo "PASS"
else
    echo "FAIL"
fi

# Test 4 - player moves right 
echo -n "4. Player moves right: "
if grep -Fqx -f tests/validmaps/movementoutputs/righttest.txt tmp;
then
    echo "PASS"
else
    echo "FAIL"
fi

# Test 5 - invalid input
echo -n "5. Invalid input: "
echo "e" | ./maze tests/validmaps/validmap1.txt > tmp
if grep -q "Error: Invalid input" tmp;
then
    echo "PASS"
else
    echo "FAIL"
    cat tmp 
fi

# Test 6 - Map displays correctly
echo -n "6. Map displays on 'M' key: "
echo "m" | ./maze tests/validmaps/validmap2.txt > tmp
if grep -Fqx -f tests/validmaps/maptest.txt tmp;
then
    echo "PASS"
else
    echo "FAIL"
fi

echo
echo "-----Testing game functionality-----"

# Test 1 - User hits wall

echo -n "1. User hits wall: "
echo "a"| ./maze tests/validmaps/validmap2.txt > tmp
if grep -q "Wall hit!" tmp;
then
    echo "PASS"
else
    echo "FAIL"
    cat tmp
fi

# Test 2 - User exits maze

echo -n "2. Exit maze successfully: "
echo "d" | echo "d" | echo "d" | echo "d" | ./maze tests/validmaps/validmap2.txt > tmp
if grep -q "Congratulations, you have won!" tmp;
then
    echo "PASS"
else
    echo "FAIL"
    cat tmp
fi

# Test 3 - User starts at correct point

echo -n "3. User starts at correct point: "
./maze tests/validmaps/validmap2.txt > tmp
if grep -q "Congratulations, you have won!" tmp;
then
    echo "PASS"
else
    echo "FAIL"
    cat tmp
fi

echo
echo "-------Finished testing-------"

rm -r tmp