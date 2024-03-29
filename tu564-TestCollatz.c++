// --------------------------------
// projects/collatz/TestCollatz.c++
// Copyright (C) 2016
// Glenn P. Downing
// --------------------------------

// https://code.google.com/p/googletest/wiki/V1_7_Primer#Basic_Assertions

// --------
// includes
// --------

#include <iostream> // cout, endl
#include <sstream>  // istringtstream, ostringstream
#include <string>   // string
#include <utility>  // pair
#include "gtest/gtest.h"
#include "Collatz.h"

#define SPECIFIC_TO_CODER

using namespace std;

// -----------
// TestCollatz
// -----------

// ----
// read
// ----

TEST(CollatzFixture, read_1) {
    string s("1 10\n");
    const pair<int, int> p = collatz_read(s);
    ASSERT_EQ( 1, p.first);
    ASSERT_EQ(10, p.second);
}

TEST(CollatzFixture, read_2) {
    string s("100 200 300\n");
    const pair<int, int> p = collatz_read(s);
    ASSERT_EQ(100, p.first);
    ASSERT_EQ(200, p.second);
}

TEST(CollatzFixture, read_3) {
    string s("201 210\n");
    const pair<int, int> p = collatz_read(s);
    ASSERT_EQ(201, p.first);
    ASSERT_EQ(210, p.second);
}

// ------------
// cycle_length
// ------------
#ifdef SPECIFIC_TO_CODER
    TEST(CollatzFixture, cyc_len_1) {
        const int v = cycle_length (11111);
        ASSERT_EQ(56, v);
    }

    TEST(CollatzFixture, cyc_len_2) {
        const int v = cycle_length (360449);
        ASSERT_EQ(66, v);
    }

    TEST(CollatzFixture, cyc_len_3) {
        const int v = cycle_length (980449);
        ASSERT_EQ(184, v);
    }

    TEST(CollatzFixture, cyc_len_4) {
        const int v = cycle_length (145677);
        ASSERT_EQ(52, v);
    }
#endif

// ----
// eval
// ----

TEST(CollatzFixture, eval_1) {
    const int v = collatz_eval(1, 10);
    ASSERT_EQ(20, v);
}

TEST(CollatzFixture, eval_2) {
    const int v = collatz_eval(100, 200);
    ASSERT_EQ(125, v);
}

TEST(CollatzFixture, eval_3) {
    const int v = collatz_eval(201, 210);
    ASSERT_EQ(89, v);
}

TEST(CollatzFixture, eval_4) {
    const int v = collatz_eval(900, 1000);
    ASSERT_EQ(174, v);
}

TEST(CollatzFixture, eval_5) {
    const int v = collatz_eval(9999, 99999);
    ASSERT_EQ(351, v);
}

TEST(CollatzFixture, eval_6) {
    const int v = collatz_eval(53, 399);
    ASSERT_EQ(144, v);
}

TEST(CollatzFixture, eval_7) {
    const int v = collatz_eval(3309, 147);
    ASSERT_EQ(217, v);
}

TEST(CollatzFixture, eval_8) {
    const int v = collatz_eval(142397, 142397);
    ASSERT_EQ(39, v);
}

TEST(CollatzFixture, eval_9) {
    const int v = collatz_eval(360448, 360448);
    ASSERT_EQ(30, v);
}

// -----------------
// meta_cache_helper
// -----------------

#ifdef SPECIFIC_TO_CODER
    TEST(CollatzFixture, cache_helper_1) {
        const int v = meta_cache_helper (350, 450, LESS_THAN_1000, 100);
        ASSERT_EQ(134, v);
    }

    TEST(CollatzFixture, cache_helper_2) {
        const int v = meta_cache_helper (6, 989, LESS_THAN_1000, 100);
        ASSERT_EQ(179, v);
    }

    TEST(CollatzFixture, cache_helper_3) {
        const int v = meta_cache_helper (30000, 90000, MORE_THAN_1000, 1000);
        ASSERT_EQ(351, v);
    }

    TEST(CollatzFixture, cache_helper_4) {
        const int v = meta_cache_helper (4355, 14532, MORE_THAN_1000, 1000);
        ASSERT_EQ(276, v);
    }
#endif

// -------------
// collatz_cache
// -------------
#ifdef SPECIFIC_TO_CODER
    TEST(CollatzFixture, cache_1) {
        const int v = collatz_cache (450, 350);
        ASSERT_EQ(134, v);
    }

    TEST(CollatzFixture, cache_2) {
        const int v = collatz_cache (23, 37);
        ASSERT_EQ(112, v);
    }

    TEST(CollatzFixture, cache_3) {
        const int v = collatz_cache (30000, 90000);
        ASSERT_EQ(351, v);
    }

    TEST(CollatzFixture, cache_4) {
        const int v = collatz_cache (4355, 14532);
        ASSERT_EQ(276, v);
    }
#endif
// -----
// print
// -----

TEST(CollatzFixture, print_1) {
    ostringstream w;
    collatz_print(w, 1, 10, 20);
    ASSERT_EQ("1 10 20\n", w.str());
}

TEST(CollatzFixture, print_2) {
    ostringstream w;
    collatz_print(w, 100, 200, 125);
    ASSERT_EQ("100 200 125\n", w.str());
}

TEST(CollatzFixture, print_3) {
    ostringstream w;
    collatz_print(w, 201, 210, 89);
    ASSERT_EQ("201 210 89\n", w.str());
}

// -----
// solve
// -----

TEST(CollatzFixture, solve_1) {
    istringstream r("1 10\n100 200\n201 210\n900 1000\n");
    ostringstream w;
    collatz_solve(r, w);
    ASSERT_EQ("1 10 20\n100 200 125\n201 210 89\n900 1000 174\n", w.str());
}

TEST(CollatzFixture, solve_2) {
    istringstream r("450 350\n700 850\n100 100\n23500 34400\n");
    ostringstream w;
    collatz_solve(r, w);
    ASSERT_EQ("450 350 134\n700 850 171\n100 100 26\n23500 34400 311\n", w.str());
}

TEST(CollatzFixture, solve_3) {
    istringstream r("5 5 98\n999 1212 75\n342 429 23\n");
    ostringstream w;
    collatz_solve(r, w);
    ASSERT_EQ("5 5 6\n999 1212 182\n342 429 134\n", w.str());
}

/*
% g++ -fprofile-arcs -ftest-coverage -pedantic -std=c++11 -Wall Collatz.c++ TestCollatz.c++ -o TestCollatz -lgtest -lgtest_main -lpthread



% valgrind TestCollatz                                         >  TestCollatz.out 2>&1
% gcov -b Collatz.c++     | grep -A 5 "File 'Collatz.c++'"     >> TestCollatz.out
% gcov -b TestCollatz.c++ | grep -A 5 "File 'TestCollatz.c++'" >> TestCollatz.out



% cat TestCollatz.out
==14225== Memcheck, a memory error detector
==14225== Copyright (C) 2002-2011, and GNU GPL'd, by Julian Seward et al.
==14225== Using Valgrind-3.7.0 and LibVEX; rerun with -h for copyright info
==14225== Command: TestCollatz
==14225==
Running main() from gtest_main.cc
[==========] Running 7 tests from 1 test case.
[----------] Global test environment set-up.
[----------] 7 tests from Collatz
[ RUN      ] Collatz.read
[       OK ] Collatz.read (31 ms)
[ RUN      ] Collatz.eval_1
[       OK ] Collatz.eval_1 (5 ms)
[ RUN      ] Collatz.eval_2
[       OK ] Collatz.eval_2 (3 ms)
[ RUN      ] Collatz.eval_3
[       OK ] Collatz.eval_3 (3 ms)
[ RUN      ] Collatz.eval_4
[       OK ] Collatz.eval_4 (3 ms)
[ RUN      ] Collatz.print
[       OK ] Collatz.print (17 ms)
[ RUN      ] Collatz.solve
[       OK ] Collatz.solve (10 ms)
[----------] 7 tests from Collatz (88 ms total)

[----------] Global test environment tear-down
[==========] 7 tests from 1 test case ran. (132 ms total)
[  PASSED  ] 7 tests.
==14225==
==14225== HEAP SUMMARY:
==14225==     in use at exit: 0 bytes in 0 blocks
==14225==   total heap usage: 495 allocs, 495 frees, 70,302 bytes allocated
==14225==
==14225== All heap blocks were freed -- no leaks are possible
==14225==
==14225== For counts of detected and suppressed errors, rerun with: -v
==14225== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 2 from 2)
File 'Collatz.c++'
Lines executed:100.00% of 17
Branches executed:100.00% of 18
Taken at least once:61.11% of 18
Calls executed:89.47% of 19
Creating 'Collatz.c++.gcov'
File 'TestCollatz.c++'
Lines executed:100.00% of 26
Branches executed:57.14% of 224
Taken at least once:28.57% of 224
Calls executed:54.07% of 209
Creating 'TestCollatz.c++.gcov'
*/
