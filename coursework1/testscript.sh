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

# Test 3 - 


rm -r tmp
