//
//  main.cpp
//  Codeforces
//
//  Created by Vladimir Shishov on 19/09/14.
//  Copyright (c) 2014 Vladimir Shishov. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <random>

int run(int argc, const char * argv[]);

int problem_118D(int argc, const char * argv[]);

int problem_378B(int argc, const char * argv[]);

int problem_463A(int argc, const char * argv[]);
int problem_463B(int argc, const char * argv[]);
int problem_463C(int argc, const char * argv[]);
int problem_463D(int argc, const char * argv[]);

int problem_465B(int argc, const char * argv[]);
int problem_466B(int argc, const char * argv[]);
int problem_466C(int argc, const char * argv[]);

int problem_471A(int argc, const char * argv[]);
int problem_471B(int argc, const char * argv[]);
int problem_471C(int argc, const char * argv[]);
int problem_471D(int argc, const char * argv[]);

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

int problem_483A(int argc, const char * argv[]);
int problem_483B(int argc, const char * argv[]);
int problem_483C(int argc, const char * argv[]);

int problem_UVa562(int argc, const char * argv[]);
int problem_UVa10616(int argc, const char * argv[]);
int problem_UVa10819(int argc, const char * argv[]);
int problem_UVa11832(int argc, const char * argv[]);


int generateRandomInt(int from, int to) {
    std::random_device rd; // for seed
    std::minstd_rand engine(rd());
    std::uniform_int_distribution<int> uniform_dist(from, to);
    return uniform_dist(engine);
}

#define REP(k,a) for(int k=0; k < (a); ++k)

//#define GENERATE

int main(int argc, const char * argv[])
{
#ifdef GENERATE
    std::ofstream testIn("input.txt");
    
//    int n = 40000;
//    testIn << n << std::endl;
//    
//    for (int i = 0; i < n; ++i) {
////        testIn << (i + 1) << " ";
//        testIn << 3 << " ";
//    }
    int m = generateRandomInt(1, 10);
    int n = generateRandomInt(1, 10);
    testIn << m << " " << n << std::endl;
    
    REP(i, m) {
        REP(j, n) {
            int val = generateRandomInt(0, 1);
            testIn << val << " ";
        }
        testIn << std::endl;
    }
    
    testIn.close();
//    return 0;
#endif
    
    bool stdin_emul = false;
    
    if (argc > 1) {
        if (strncmp("-stdin_emul", argv[1], 15) == 0)
            stdin_emul = true;
    }

    std::ifstream in("input.txt");
    if (stdin_emul) {
        std::cin.rdbuf(in.rdbuf());
    }
    
    return run(argc, argv);
}

