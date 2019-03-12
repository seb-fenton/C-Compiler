###CPPFLAG RULES###
CPPFLAGS += -W -Wall -g 
CPPFLAGS += -I full_compiler/include

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

bin/c_compiler : full_compiler/include/ast/context.o full_compiler/src/c_compiler.o full_compiler/src/c_parser.tab.o full_compiler/src/c_lexer.yy.o
	make parser
	g++ $(CPPFLAGS) -o bin/c_compiler $^

full_compiler/src/c_compiler.o : full_compiler/src/c_compiler.cpp 
	mkdir -p bin
	g++ $(CPPFLAGS) -c full_compiler/src/c_compiler.cpp -o full_compiler/src/c_compiler.o



###PARSER RULES###
parser: src/c_lexer.yy.cpp
parsertest : bin/eval_expr

#bin/eval_expr : src/eval_parser.o src/c_parser.tab.o src/c_lexer.yy.o 
#	mkdir -p bin
#	g++ $(CPPFLAGS) -o bin/eval_expr $^

#src/c_lexer.yy.cpp : src/c_lexer.flex src/c_parser.tab.hpp
	#flex -o src/c_lexer.yy.cpp  src/c_lexer.flex

bin/eval_expr : full_compiler/include/ast/context.o full_compiler/src/eval_parser.o full_compiler/src/c_parser.tab.o full_compiler/src/c_lexer.yy.o
	mkdir -p bin
	g++ $(CPPFLAGS) -o bin/eval_expr $^

full_compiler/include/ast/context.o: full_compiler/include/ast/context.cpp full_compiler/include/ast/context.hpp
	g++ $(CPPFLAGS) -c full_compiler/include/ast/context.cpp -o full_compiler/include/ast/context.o

full_compiler/src/c_lexer.yy.cpp : full_compiler/src/c_lexer.flex full_compiler/src/c_parser.tab.hpp
	flex -o full_compiler/src/c_lexer.yy.cpp  full_compiler/src/c_lexer.flex

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
	-rm -rf full_compiler/src/*.yy.cpp
	-rm -rf full_compiler/src/*.yy.hpp
	-rm -rf full_compiler/src/*.tab.hpp
	-rm -rf full_compiler/src/*.tab.cpp
	-rm -rf full_compiler/src/*.o
	-rm -rf full_compiler/include/ast/*.o
	-rm -rf full_compiler/src/*.output
	-rm -rf bin
	-rm -rf tmp
