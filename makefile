all: main main2

main: main.cpp
	g++ -std=gnu++17 -O2 -pipe -static -Wall -o main main.cpp -D LOCAL_DEFINE

main2: main2.cpp
	g++ -std=gnu++17 -O2 -pipe -static -Wall -o main2 main2.cpp -D LOCAL_DEFINE