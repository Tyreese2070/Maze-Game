gcc mazeGame.c -o mazeGame

echo "--Testing maze game inputs--"

# Test 1 - Checking for no file input
echo -n "1. No inputs: "
./mazeGame > tmp
if grep -q "Invalid input" tmp;
then
    echo "PASS"
else
    echo "FAIL"
    cat tmp 
fi

# Test 2 - Too many inputs
echo -n "2. Too many inputs: "
./mazeGame x x > tmp
if grep -q "Invalid input" tmp;
then
    echo "PASS"
else
    echo "FAIL"
    cat tmp 
fi

# Test 3 - Map displays correctly !! Check later
echo -n "3. Map displays on 'M' key: "
echo "m" | ./mazeGame tests/test1/test1.txt tmp
if grep -Fxq -f tests/test1/test1.txt -q tmp;
then
    echo "PASS"
else
    echo "FAIL"
    cat tmp 
fi

# Test 4 player moves right 
echo -n "4. Player moves right: "
echo "d" | echo "m" | ./mazeGame tests/test1.txt tmp
if grep -Fxq -f test1.txt -q tmp;
then
    echo "PASS"
else
    echo "FAIL"
    cat tmp 
fi

# Test 5 - No start point
echo -n "5. No start point on map: "
./mazeGame tests/invalidmaps/nostart.txt
if grep -q "Invalid maze" tmp;
then
    echo "PASS"
else
    echo "FAIL"
fi

# Test 6 - No end point
echo -n "6. No start point on map: "
./mazeGame tests/invalidmaps/noend.txt
if grep -q "Invalid maze" tmp;
then
    echo "PASS"
else
    echo "FAIL"
fi

# Test 6 - No end point
echo -n "7. Invalid map characters: "
./mazeGame tests/invalidmaps/invalidchar.txt
if grep -q "Invalid maze" tmp;
then
    echo "PASS"
else
    echo "FAIL"
fi

# Test 6 - No end point
echo -n "7. Invalid map dimensions: "
./mazeGame tests/invalidmaps/invalidchar.txt
if grep -q "Invalid maze" tmp;
then
    echo "PASS"
else
    echo "FAIL"
fi


:'
echo -n "4. Player moves correctly: "
./mazeGame tests/test1.txt < tests/test1Moves.in > tmp
if grep -q "Invalid input" tmp;
then
    echo "PASS"
else
    echo "FAIL"
    cat tmp 
fi
'

rm -r tmp
