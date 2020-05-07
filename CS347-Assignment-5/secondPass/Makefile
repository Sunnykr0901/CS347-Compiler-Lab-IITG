Intermediate:	Intermediate.l Intermediate.y SymbolTableParser.c
	bison -d Intermediate.y
	flex Intermediate.l
	g++ -o $@ Intermediate.tab.c lex.yy.c SymbolTableParser.c
clean:	Intermediate Intermediate.tab.c Intermediate.tab.h lex.yy.c
	rm Intermediate Intermediate.tab.c Intermediate.tab.h lex.yy.c