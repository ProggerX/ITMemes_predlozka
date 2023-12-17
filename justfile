default: build run clean

build:
	g++ ./src/* -I./include/ -L./lib/ -l:libtgbot-cpp.a -lboost_system -lssl -lcrypto -lpthread -oout


run:
	./out

clean:
	rm -rf ./out
