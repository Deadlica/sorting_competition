program: main.cpp timer.cpp reader.cpp
	g++ -O3 -o sorter main.cpp timer.cpp reader.cpp -g

run: program
	./sorter
