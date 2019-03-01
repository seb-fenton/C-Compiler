CPPFLAGS += -W -Wall -g 

# This avoids error: ‘fileno’ was not declared in this scope
CPPFLAGS += -std=c++0x

# Avoid warnings about yyunput not used
CPPFLAGS += -Wno-unused-function

lexer : bin/c_lexer

bin/c_lexer : ../../full_compiler/src/c_lexer.yy.o c_lexer_main.o
	mkdir -p bin 
	g++ $(CPPFLAGS) -o bin/c_lexer ../../full_compiler/src/c_lexer.yy.o c_lexer_main.o

../../full_compiler/src/c_lexer.yy.cpp : ../../full_compiler/src/c_lexer.flex
	flex -o ../../full_compiler/src/c_lexer.yy.cpp  ../../full_compiler/src/c_lexer.flex

clean :
	-rm -rf prog prog.exe
	-rm -rf ../../full_compiler/src/*.yy.cpp
	-rm -rf ../../full_compiler/src/*.o
	-rm -rf *.o
	-rm -rf bin
	-rm -rf testfiles/out/*.stderr.txt
	-rm -rf testfiles/out/*.stdout.txt