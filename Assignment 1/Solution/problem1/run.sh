g++ kruskals.cpp -o k1
g++ mst.cpp -o k2
./k1 < $1 > $2
./k2 < $1 >> $2
