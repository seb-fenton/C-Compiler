CPPFLAGS += -W -Wall -g 

# This avoids error: ‘fileno’ was not declared in this scope
CPPFLAGS += -std=c++0x

# Avoid warnings about yyunput not used
CPPFLAGS += -Wno-unused-function

lexer : bin/c_lexer

src/maths_parser.tab.cpp src/maths_parser.tab.hpp : src/maths_parser.y
	bison -v -d src/maths_parser.y -o src/maths_parser.tab.cpp

src/c_lexer.yy.cpp : src/c_lexer.flex
	flex -o src/c_lexer.yy.cpp  src/c_lexer.flex

bin/c_lexer : src/c_lexer.yy.o src/c_lexer_main.o
	mkdir -p bin 
	g++ $(CPPFLAGS) -o bin/c_lexer src/c_lexer.yy.o src/c_lexer_main.o

clean :
	-rm -rf prog prog.exe
	-rm -rf src/*.yy.cpp
	-rm -rf src/*.o
	-rm -rf bin