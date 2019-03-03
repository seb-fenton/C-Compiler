###CPPFLAG RULES###
CPPFLAGS += -W -Wall -g 
CPPFLAGS += -I include

# This avoids error: ‘fileno’ was not declared in this scope
CPPFLAGS += -std=c++0x

# Avoid warnings about yyunput not used
CPPFLAGS += -Wno-unused-function



###COMPILER RULES###
compiler: bin/c_compiler

bin/c_compiler : bin/c_compiler.o
	mkdir -p bin
	g++ $(CPPFLAGS) -o bin/c_compiler bin/c_compiler.o
	make parser

bin/c_compiler.o : src/c_compiler.cpp
	mkdir -p bin
	g++ $(CPPFLAGS) -c src/c_compiler.cpp -o bin/c_compiler.o



###PARSER RULES###
parser: src/c_lexer.yy.cpp
parsertest : bin/eval_expr

bin/eval_expr : bin/eval_parser.o src/c_parser.tab.o src/c_lexer.yy.o src/c_parser.tab.o
	g++ $(CPPFLAGS) -o bin/eval_expr $^

src/c_lexer.yy.cpp : src/c_lexer.flex src/c_parser.tab.hpp
	flex -o src/c_lexer.yy.cpp  src/c_lexer.flex

src/c_parser.tab.cpp src/c_parser.tab.hpp : src/c_parser.y
	bison -v -d src/c_parser.y -o src/c_parser.tab.cpp

bin/eval_parser.o : src/eval_parser.cpp
	mkdir -p bin
	g++ $(CPPFLAGS) -c src/eval_parser.cpp -o bin/eval_parse.o


###CLEAN RULES###
clean :
	-rm -rf prog prog.exe
	-rm -rf src/*.yy.cpp
	-rm -rf src/*.yy.hpp
	-rm -rf src/*.tab.hpp
	-rm -rf src/*.tab.cpp
	-rm -rf src/*.o
	-rm -rf bin