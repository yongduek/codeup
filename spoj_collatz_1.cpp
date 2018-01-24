//
//  spoj_collatz_1.cpp
//  codeup
//
//  Created by Yongduek Seo on 2018. 1. 21..
//  Copyright © 2018년 Yongduek Seo. All rights reserved.
//

#include <iostream>
using namespace std;

typedef unsigned long ul;

ul Collatz (unsigned long n)
{
    if (n == 1) return 1;
    
    if (n % 2 == 0) {
        n = n / 2;
    }
    else {
        n = 3 * n + 1;
    }
    
    ul length = 1 + Collatz (n);
    
    return length;
}

int main() {
    size_t a;
    cin >> a;
 
    ul len = Collatz (a);
    
    cout << len << endl;
    return 0;
}
