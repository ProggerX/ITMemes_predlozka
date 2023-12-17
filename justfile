default: build run clean

build:
	g++ ./src/* -I./include/ -L./lib/ -oout

run:
	./out

clean:
	rm -rf ./out
