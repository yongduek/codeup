//
//  codeup_1916_fibonacci.cpp
//  codeup
//
//  Created by Yongduek Seo on 2018. 1. 21..
//  Copyright © 2018년 Yongduek Seo. All rights reserved.
//

#include<iostream>
using namespace std;

int mem[1024];

const int divisor = 10009;

unsigned long fib (int n) {
    if (mem[n])
        return mem[n];
    else {
        return mem[n] = (fib(n-1) % divisor + fib(n-2) % divisor) % divisor;
    }
}

int main()
{
    int n;
    cin >> n;

    mem[1] = mem[2] = 1;
    
    cout << fib(n) << endl;
    
    return 0;
}
