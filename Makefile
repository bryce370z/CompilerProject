a.out: SlicDataParser.y SlicScanner.l main.c
	bison -y -d SlicDataParser.y
	flex SlicScanner.l
	gcc lex.yy.c y.tab.c main.c -ll

clean:
	rm -f a.exe a.out lex.yy.c y.tab.c y.tab.h .DS_Store
