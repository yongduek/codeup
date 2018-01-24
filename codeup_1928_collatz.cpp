//
//  codeup_1928_collatz.cpp
//  codeup
//
//  Created by Yongduek Seo on 2018. 1. 21..
//  Copyright © 2018년 Yongduek Seo. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <map>
using namespace std;

typedef unsigned long ul;


void Collatz (unsigned long n)
{
    if (n == 1) return;
    
    if (n % 2 == 0) {
        n = n / 2;
    }
    else {
        n = 3 * n + 1;
    }

    Collatz (n);
    
    cout << n << endl;
}

void solve(ul n)
{
    Collatz (n);
    cout << n << endl;
}

int main() {
    size_t a;
    cin >> a;
    
    solve (a);
    
    return 0;
}
