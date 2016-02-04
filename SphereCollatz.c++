// ----------------------------
// projects/collatz/Collatz.c++
// Copyright (C) 2016
// Glenn P. Downing
// ----------------------------

// --------
// includes
// --------

#include <cassert>  // assert
#include <iostream> // endl, istream, ostream
#include <sstream>  // istringstream
#include <string>   // getline, string
#include <utility>  // make_pair, pair
using namespace std;

int cache[1000001] = { 0 };
// ------------
// collatz_read
// ------------

pair<int, int> collatz_read (const string& s) {
    istringstream sin(s);
    int i;
    int j;
    sin >> i >> j;
    return make_pair(i, j);}

// ------------
// collatz_eval
// ------------
int collatz_eval (int i, int j) {
    assert(i > 0);
    assert(j > 0);

    if (i > j) {
        swap(i, j);
    }

    int mid_range = j/2 + 1;
    if (mid_range > i)
        i = mid_range;

    int max_cycle_len = 0;

    for (i = i; i < j+1; ++i) {
        int c = 1;
        int index = i;
        unsigned long n = i;

        if (n <= 1000000 && cache[n] != 0) {
            c = cache[n];
        } else {
            while (n > 1) {
                // printf("n = %d\t c= %d\n", n, c);
                if (n%2 == 0) {
                    n = (n/2);
                    // printf("even n = %llu\n", n);
                }
                else {
                    n = (3 * n) + 1;
                    // printf("odd n = %llu\n", n);
                }
                if (n <= 1000000 and cache[n] != 0) {
                    c += cache[n];
                    break;
                }
                ++c;
            }
        }
        
        //printf("cache[%d] = %d\n", index, c);

        assert(c > 0);
        cache[index] = c;

        //max_cycle_len = max(max_cycle_len, c);
        if (c > max_cycle_len) {
            max_cycle_len = c;
            //printf("cache[%d] = %d\n", index, c);
        }
    }

    return max_cycle_len;
}



// -------------
// collatz_print
// -------------

void collatz_print (ostream& w, int i, int j, int v) {
    w << i << " " << j << " " << v << endl;}

// -------------
// collatz_solve
// -------------

void collatz_solve (istream& r, ostream& w) {
    string s;
    while (getline(r, s)) {
        const pair<int, int> p = collatz_read(s);
        const int            i = p.first;
        const int            j = p.second;
        const int            v = collatz_eval(i, j);
        collatz_print(w, i, j, v);}}

// ----
// main
// ----

int main () {
    using namespace std;
    collatz_solve(cin, cout);
    return 0;}
