CPPFLAGS += -W -Wall -g 

# This avoids error: ‘fileno’ was not declared in this scope
CPPFLAGS += -std=c++0x

# Avoid warnings about yyunput not used
CPPFLAGS += -Wno-unused-function

lexer : c_lexer

src/c_lexer.yy.cpp : src/c_lexer.flex
	flex -o src/c_lexer.yy.cpp  src/c_lexer.flex

bin/c_lexer : src/c_lexer.yy.o src/c_lexer_main.o
	g++ $(CPPFLAGS) -o bin/c_lexer src/c_lexer.yy.o src/c_lexer_main.o

clean :
	-rm -f prog prog.exe
	-rm -f *.yy.cpp
	-rm -f test/out/*
	-rm -f *.o