#!/bin/bash

# Check if clang-format is installed
if ! command -v clang-format &> /dev/null
then
    echo "clang-format could not be found. Please install it."
    exit
fi

# Find all relevant files (e.g., .cpp, .h, .c, .cc, .cxx, .hpp)
FILES=$(find . -path ./build -prune -o -name '*.cpp' -o -name '*.h' -o -name '*.c' -o -name '*.cc' -o -name '*.cxx' -o -name '*.hpp')

# Format each file
for FILE in $FILES
do
    echo "Formatting $FILE"
    clang-format -i "$FILE"
done

echo "Formatting complete!"
