//
//  spoj_prime1.cpp
//  codeup
//
//  Created by Yongduek Seo on 2018. 1. 17..
//  Copyright © 2018년 Yongduek Seo. All rights reserved.
//

#include <stdio.h>
#include <iostream>

using namespace std;

typedef unsigned long ul;
const ul maxN = 1000000000;

bool check_prime (ul k) {
    if (k == 1) return false;
    if (k == 2) return true;
    
    // now lets examine.
    // if k is even, then false!
    if (k % 2 == 0) return false;
    
    // examine odd numbers only
    bool result = true;
    for (ul n = 3; n*n <= k; n+=2) {
        if (k % n == 0) {
            result = false;
            break;
        }
    }
    return result;
}

int main() {
    int t;
    cin >> t;
    
    for (int i=0; i<t; i++) {
        unsigned long m, n;
        cin >> m >> n;
        for (ul k = m; k <= n; k++) {
            bool r = check_prime (k);
            if (r)
                cout << k << endl;
        }
        cout << endl;
    }
    return 0;
}
