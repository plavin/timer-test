.PHONY: run clean
run: timer-test
	./timer-test
	rm -rf timer-test
timer-test: main.cpp
	g++ --std=c++17 -O3 -o timer-test main.cpp
clean:
	rm -rf timer-test
