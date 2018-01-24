//
//  codeup_3733_Collatz_conjecture.cpp
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

map<ul,ul> length;

ul Collatz (unsigned long n)
{
    if (n == 1) return 1;
    
    if (length.find(n) != length.end())
        return length[n];
    
    ul n_input = n;
    
    if (n % 2 == 0) {
        n = n / 2;
    }
    else {
        n = 3 * n + 1;
    }
    
    length[n_input] = 1 + Collatz (n);
    
    return length[n_input];
}


void solve_recurseive(ul a, ul b)
{
    for (size_t i = b; i >= a; i--)
        length[i] = Collatz (i);
    
    ul maxlen = length[a];
    ul index = a;
    for (auto i = a; i <= b; i++)
        if (maxlen < length[i]) {
            maxlen = length[i];
            index = i;
        }
    
    cout << index << ' ' << maxlen << endl;
}

void solve (ul a, ul b)
{
    ul maxlen = 0;
    ul maxnum = 0;
    
    for (ul num = a; num <= b; num++) {
        ul count = 0;
        if (1) {
            if (num == 113383) {
                int aa = 0;
                aa ++;
            }
            ul n = num;
            while (true) {
                if (length.find(n) == length.end()) {
                    count++;
                    if (n == 1) break;
                    else if (n % 2 == 0) n /= 2;
                    else n = 3*n+1;
                }
                else {
                    count = count + length[n];
                    break;
                }
            }
        }
        
        length[num] = count;
        if (maxlen < count) { maxlen = count; maxnum = num; }
        //cout << num << ' ' << count << endl;
    }
    
    cout << maxnum << ' ' << maxlen << endl;
}

const unsigned maxmem = 100000000;
unsigned mem[maxmem];

void solve_mem (ul a, ul b)
{
    ul maxlen = 0;
    ul maxnum = 0;
    
    for (ul num = a; num <= b; num++) {
        ul count = 0;
        if (1) {
            ul n = num;
            while (true) {
                if (n >= maxmem) {
                    count++;
                    if (n % 2 == 0) n /= 2;
                    else n = 3*n+1;
                }
                else {
                    if (mem[n] == 0) {
                        count++;
                        if (n == 1) break;
                        else if (n % 2 == 0) n /= 2;
                        else n = 3*n+1;
                    }
                    else {
                        count = count + mem[n];
                        break;
                    }
                }
            }
        }
        
        mem[num] = count;
        if (maxlen < count) { maxlen = count; maxnum = num; }
        //cout << num << ' ' << count << endl;
    }
    
    cout << maxnum << ' ' << maxlen << endl;
}

int main() {
    size_t a, b;
    cin >> a >> b;
    
//    solve (a, b);
//    solve_recurseive(a, b);
    
    solve_mem (a, b);
    return 0;
}
