g++ Testing.cpp -c
g++ Matrix.cpp -c
g++ "Testing.o" "Matrix.o" "MatrixTests.cpp" -o tests && tests -r compact

cmd /k