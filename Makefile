a.out: Parser.y Scanner.l main.c
	bison -y -d Parser.y
	flex Scanner.l
	gcc lex.yy.c y.tab.c main.c -ll

clean:
	rm -f a.exe a.out lex.yy.c y.tab.c y.tab.h .DS_Store
