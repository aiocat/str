: run this file from main directory.

@echo off

cd test

echo Testing for CLANG
clang main.c -o main.exe
.\main.exe

echo Testing for GCC
gcc main.c -o main.exe
.\main.exe

cd ..

rem .\main.exe