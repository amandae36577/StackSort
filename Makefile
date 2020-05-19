default: 
	g++ -c main.cpp 
	g++ -c Stack.h
	g++ -c Stack.cpp
	g++ -o sorted main.cpp Stack.cpp
run:
	./sorted input.txt output.txt
clean:
	rm StackSort/*.o
