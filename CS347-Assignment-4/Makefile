exe:   	lexer.l parser.y  sql.c
	bison -d parser.y
	flex lexer.l
	gcc -o $@ parser.tab.c lex.yy.c  sql.c -lfl -g
		
clean:  exe parser.tab.c parser.tab.h lex.yy.c
	rm exe parser.tab.c parser.tab.h lex.yy.c
