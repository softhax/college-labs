lex prog3b.l
yacc -d prog3b.y
clear
cc lex.yy.c y.tab.c -ll -ly
clear
