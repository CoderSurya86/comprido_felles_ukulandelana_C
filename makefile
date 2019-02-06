./bin/computeLongestCommonSequence: ./obj/main.o
	g++ -g -Wall -std=c++11 ./obj/main.o -o ./bin/computeLongestCommonSequence
./obj/main.o: ./src/main.cpp
	g++ -g -Wall -std=c++11 -c ./src/main.cpp
clean:
	rm -rf ./obj/* ./bin/*