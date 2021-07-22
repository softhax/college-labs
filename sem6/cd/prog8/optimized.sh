clang loop.c -S -emit-llvm -o - -O1 > loop.ll
llc loop.ll
