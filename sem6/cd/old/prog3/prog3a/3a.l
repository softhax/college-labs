%{
#include "y.tab.h"
%}
%%
"for" return FOR;
[(] return LR;
[)] return RR;
[{] return LC;
[}] return RC;
[=] return '=';
[-] return '-';
[+] return '+';
[>] return '>';
[<] return '<';
[;] return ';';
[a-zA-Z]* return VAR;
[0-9]+ return NUM;
[ ] return SPACE;
%%

int yywrap(){
    return 1;
}
