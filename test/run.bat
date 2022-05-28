: run this file from main directory.

@echo off

cd test

echo Testing for CLANG
clang -std=c99 main.c -o main.exe
.\main.exe

pause

echo Testing for GCC
gcc -std=c99 main.c -o main.exe
.\main.exe

cd ..

rem .\main.exe