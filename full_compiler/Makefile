CPPFLAGS += -W -Wall -g 
CPPFLAGS += -I include


# This avoids error: ‘fileno’ was not declared in this scope
CPPFLAGS += -std=c++0x

# Avoid warnings about yyunput not used
CPPFLAGS += -Wno-unused-function

parser : bin/eval_expr

src/c_parser.tab.cpp src/c_parser.tab.hpp : src/c_parser.y
	bison -v -d src/c_parser.y -o src/c_parser.tab.cpp

src/c_lexer.yy.cpp : src/c_lexer.flex src/c_parser.tab.hpp
	flex -o src/c_lexer.yy.cpp  src/c_lexer.flex

bin/eval_expr : src/eval_parser.o src/c_parser.tab.o src/c_lexer.yy.o src/c_parser.tab.o
	mkdir -p bin 
	g++ $(CPPFLAGS) -o bin/eval_expr $^

clean :
	-rm -rf prog prog.exe
	-rm -rf src/*.yy.cpp
	-rm -rf src/*.yy.hpp
	-rm -rf src/*.tab.hpp
	-rm -rf src/*.tab.cpp
	-rm -rf src/*.o
	-rm -rf bin