FLAGS = -std=c++14

main: *.cpp *.h
	g++ $(FLAGS) *.cpp *.h -o main