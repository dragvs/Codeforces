//
//  main.cpp
//  Codeforces
//
//  Created by Vladimir Shishov on 19/09/14.
//  Copyright (c) 2014 Vladimir Shishov. All rights reserved.
//

#include <iostream>
#include <fstream>


int problem_466C(int argc, const char * argv[]);

int problem_471A(int argc, const char * argv[]);
int problem_471B(int argc, const char * argv[]);
int problem_471C(int argc, const char * argv[]);

int problem_472B(int argc, const char * argv[]);
int problem_472C(int argc, const char * argv[]);

int problem_474A(int argc, const char * argv[]);
int problem_474B(int argc, const char * argv[]);
int problem_474C(int argc, const char * argv[]);
int problem_474D(int argc, const char * argv[]);
int problem_474E(int argc, const char * argv[]);
int problem_474F(int argc, const char * argv[]);

int problem_UVa562(int argc, const char * argv[]);
int problem_UVa10616(int argc, const char * argv[]);
int problem_UVa10819(int argc, const char * argv[]);
int problem_UVa11832(int argc, const char * argv[]);


int main(int argc, const char * argv[])
{
    std::ifstream in("input.txt");
    std::cin.rdbuf(in.rdbuf());
    
    return problem_474F(argc, argv);
}

