g++ -c q4.cpp
g++ -o q4 q4.o -lglpk
./q4 < $1 > $2
