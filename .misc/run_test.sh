#!/bin/bash
set -e

echo "Testing C files..."
for i in $(find . -name *.c -print | sort --unique); do
    echo "    Compiling $i - gcc $i -lm -std=c11"
    gcc $i -lm -std=c11
    echo "    Running $i - ./a.out 2> /dev/null"
    ./a.out 2> /dev/null
    rm -f a.out
    echo ""
done

echo ""
echo "Testing C++ files..."
for i in $(find . -name *.cpp -print | sort --unique); do
    echo "    Compiling $i - g++ $i -lm -pthread -std=c++11"
    g++ $i -lm -pthread -std=c++11
    echo "    Running $i - ./a.out 2> /dev/null"
    ./a.out 2> /dev/null
    rm -f a.out
    echo ""
done

echo ""
echo "Testing Java files..."
for i in $(find . -name *.java -print | sort --unique); do
    echo "    Compiling $i - javac -Werror -Xlint:all $i -d ."
    javac -Werror -Xlint:all $i -d .
    filename="${i##*/}"
    classname="${filename%.*}"
    echo "    Running $i - java $classname 2> /dev/null"
    java $classname 2> /dev/null
    echo ""
done
rm -f *.class

echo "Testing Python files..."
for i in $(find . -name *.py -print | sort --unique); do
    echo "    Running $i - python3 $i 2> /dev/null"
    python3 $i 2> /dev/null
    echo ""
done
