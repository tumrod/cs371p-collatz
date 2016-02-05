// --------------------------
// projects/collatz/Collatz.h
// Copyright (C) 2016
// Glenn P. Downing
// --------------------------

#ifndef Collatz_h
#define Collatz_h

// --------
// includes
// --------

#include <iostream> // istream, ostream
#include <string>   // string
#include <utility>  // pair

using namespace std;
extern int cache_array[1000001];
extern int LESS_THAN_1000[10];
extern int MORE_THAN_1000[1000];

// ------------
// collatz_read
// ------------

/**
 * read two ints
 * @param s a string
 * @return a pair of ints, representing the beginning and end of a range, [i, j]
 */
pair<int, int> collatz_read (const string& s);


// ------------
// cycle_length
// ------------

/**
 * @param n an input int
 * @return the cycle length n
 */
int cycle_length (unsigned long long n);


// ------------
// collatz_eval
// ------------

/**
 * @param i the beginning of the range, inclusive
 * @param j the end       of the range, inclusive
 * @return the max cycle length of the range [i, j]
 */
int collatz_eval (int i, int j);


// -----------------
// meta_cache_helper
// -----------------

/**
* @param i          the beginning of the range, inclusive
* @param j          the end       of the range, inclusive
* @param cache_rang the meta-cache array of either LESS_THAN_1000 or MORE_THAN_1000
* @param val        the increment value, either by 100 or by 1000
* @return the max cycle length with using meta cache
*/

int meta_cache_helper (int i, int j, int cache_range[], int val);


// -------------
// collatz_cache
// -------------

/**
* filter the category of meta cache
* @param i          the beginning of the range, inclusive
* @param j          the end       of the range, inclusive
* @return the max cycle length which is a result from the helper
*/

int collatz_cache (int i, int j);


// -------------
// collatz_print
// -------------

/**
 * print three ints
 * @param w an ostream
 * @param i the beginning of the range, inclusive
 * @param j the end       of the range, inclusive
 * @param v the max cycle length
 */

void collatz_print (ostream& w, int i, int j, int v);


// -------------
// collatz_solve
// -------------

/**
 * @param r an istream
 * @param w an ostream
 */
void collatz_solve (istream& r, ostream& w);

#endif // Collatz_h
