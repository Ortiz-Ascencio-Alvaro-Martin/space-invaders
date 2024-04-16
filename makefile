bin/test : src/tui_test.cpp
	g++ src/tui_test.cpp -o bin/test -std=c++2a -lftxui-screen -lftxui-component -lftxui-dom         

run : bin/test
	./bin/test