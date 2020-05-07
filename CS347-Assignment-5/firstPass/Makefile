Parser:	Parser.l Parser.y Function.c IntermediateCodeGenerator.c
	bison -d Parser.y
	flex Parser.l
	g++ -o $@ Parser.tab.c lex.yy.c Function.c IntermediateCodeGenerator.c
clean:	Parser Parser.tab.c Parser.tab.h lex.yy.c
	rm Parser Parser.tab.c Parser.tab.h lex.yy.c