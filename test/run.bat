@echo off

echo Testing for CLANG
clang main.c -o main.exe
.\main.exe

echo Testing for GCC
gcc main.c -o main.exe
.\main.exe

rem .\main.exe