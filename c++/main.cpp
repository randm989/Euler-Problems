/*
 * File:   main.cpp
 * Author: Josh
 *
 * Created on May 4, 2012, 5:29 PM
 */

#include <cstdlib>
#include <stdio.h>
#include <iostream>

#include "p1.hpp"
#include "p2.hpp"
#include "BigInt.hpp"

using namespace std;

/*
 *
 */
int main(int argc, char** argv) {
    BigInt b;
    b = "1234567890123456789012345";
    b += "111111111111111111111111111";
    std::string s = b.toString();
    cout << s << endl;

    cout << (BigInt(1) < BigInt(2)) << endl;
    return 0;
}

