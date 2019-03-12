###CPPFLAG RULES###
CPPFLAGS += -W -Wall -g 
CPPFLAGS += -I include

# This avoids error: ‘fileno’ was not declared in this scope
CPPFLAGS += -std=c++0x

# Avoid warnings about yyunput not used
CPPFLAGS += -Wno-unused-function



###COMPILER RULES###
compiler: bin/c_compiler

#bin/c_compiler : bin/c_compiler.o src/c_parser.tab.o src/c_lexer.yy.o
#	make parser
#	g++ $(CPPFLAGS) -o bin/c_compiler bin/c_compiler.o src/c_parser.tab.o src/c_lexer.yy.o

#bin/c_compiler.o : src/c_compiler.cpp 
#	mkdir -p bin
#	g++ $(CPPFLAGS) -c src/c_compiler.cpp -o bin/c_compiler.o

bin/c_compiler : include/ast/context.o src/c_compiler.o src/c_parser.tab.o src/c_lexer.yy.o
	make parser
	g++ $(CPPFLAGS) -o bin/c_compiler $^

src/c_compiler.o : src/c_compiler.cpp 
	mkdir -p bin
	g++ $(CPPFLAGS) -c src/c_compiler.cpp -o src/c_compiler.o



###PARSER RULES###
parser: src/c_lexer.yy.cpp
parsertest : bin/eval_expr

#bin/eval_expr : src/eval_parser.o src/c_parser.tab.o src/c_lexer.yy.o 
#	mkdir -p bin
#	g++ $(CPPFLAGS) -o bin/eval_expr $^

#src/c_lexer.yy.cpp : src/c_lexer.flex src/c_parser.tab.hpp
	#flex -o src/c_lexer.yy.cpp  src/c_lexer.flex

bin/eval_expr : include/ast/context.o src/eval_parser.o src/c_parser.tab.o src/c_lexer.yy.o
	mkdir -p bin
	g++ $(CPPFLAGS) -o bin/eval_expr $^

include/ast/context.o: include/ast/context.cpp include/ast/context.hpp
	g++ $(CPPFLAGS) -c include/ast/context.cpp -o include/ast/context.o

src/c_lexer.yy.cpp : src/c_lexer.flex src/c_parser.tab.hpp
	flex -o src/c_lexer.yy.cpp  src/c_lexer.flex

src/c_parser.tab.cpp src/c_parser.tab.hpp : src/c_parser.y
	bison -v -d src/c_parser.y -o src/c_parser.tab.cpp

src/eval_parser.o : src/eval_parser.cpp
	mkdir -p bin
	g++ $(CPPFLAGS) -c src/eval_parser.cpp -o src/eval_parser.o


###CLEAN RULES###
clean :
	-rm -rf prog prog.exe
	-rm -rf src/*.yy.cpp
	-rm -rf src/*.yy.hpp
	-rm -rf src/*.tab.hpp
	-rm -rf src/*.tab.cpp
	-rm -rf src/*.o
	-rm -rf src/*.output
	-rm -rf bin
	-rm -rf include/ast/*.o
	-rm -rf src/*.output
	-rm -rf bin
	-rm -rf tmp
