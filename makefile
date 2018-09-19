Lab6: main.o Exec.o Sudoku.o
	g++ -std=c++11 -g -Wall main.o Exec.o Sudoku.o -o Lab6
main.o: main.cpp
	g++ -std=c++11 -g -Wall -c main.cpp
Exec.o: Exec.cpp
	g++ -std=c++11 -g -Wall -c Exec.cpp
Sudoku.o: Sudoku.cpp
	g++ -std=c++11 -g -Wall -c Sudoku.cpp
clean:
	rm *.o Lab6
