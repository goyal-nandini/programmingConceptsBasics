// main program/file
#include<iostream>
#include"MyClass.h"

int main(){
    myClass obj;

    obj.displayMessage();

    return 0;
}
// this program is compiled as: g++ header_files.cpp MyClass.cpp -o executableFile
//                               ./executableFile
//header_files.cpp and myClass.cpp are the source files to compile.