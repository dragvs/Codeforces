//
//  main.cpp
//  Codeforces
//
//  Created by Vladimir Shishov on 19/09/14.
//  Copyright (c) 2014 Vladimir Shishov. All rights reserved.
//

#include <iostream>
#include <fstream>

int problem_118D(int argc, const char * argv[]);

int problem_466C(int argc, const char * argv[]);

int problem_471A(int argc, const char * argv[]);
int problem_471B(int argc, const char * argv[]);
int problem_471C(int argc, const char * argv[]);

int problem_472A(int argc, const char * argv[]);
int problem_472B(int argc, const char * argv[]);
int problem_472C(int argc, const char * argv[]);

int problem_474A(int argc, const char * argv[]);
int problem_474B(int argc, const char * argv[]);
int problem_474C(int argc, const char * argv[]);
int problem_474D(int argc, const char * argv[]);
int problem_474E(int argc, const char * argv[]);
int problem_474F(int argc, const char * argv[]);

int problem_475A(int argc, const char * argv[]);
int problem_475B(int argc, const char * argv[]);
int problem_475C(int argc, const char * argv[]);
int problem_475D(int argc, const char * argv[]);
int problem_475E(int argc, const char * argv[]);

int problem_478A(int argc, const char * argv[]);
int problem_478B(int argc, const char * argv[]);
int problem_478C(int argc, const char * argv[]);
int problem_478D(int argc, const char * argv[]);

int problem_479A(int argc, const char * argv[]);
int problem_479B(int argc, const char * argv[]);
int problem_479C(int argc, const char * argv[]);
int problem_479D(int argc, const char * argv[]);
int problem_479E(int argc, const char * argv[]);

int problem_UVa562(int argc, const char * argv[]);
int problem_UVa10616(int argc, const char * argv[]);
int problem_UVa10819(int argc, const char * argv[]);
int problem_UVa11832(int argc, const char * argv[]);


int main(int argc, const char * argv[])
{
    bool stdin_emul = false;
    
    if (argc > 1) {
        if (strncmp("-stdin_emul", argv[1], 15) == 0)
            stdin_emul = true;
    }

    std::ifstream in("input.txt");
    if (stdin_emul) {
        std::cin.rdbuf(in.rdbuf());
    }
    
    return problem_479E(argc, argv);
}

