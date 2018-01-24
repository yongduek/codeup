//
//  codeup_2625_삼각형갯수.cpp
//  codeup
//
//  Created by Yongduek Seo on 2018. 1. 21..
//  Copyright © 2018년 Yongduek Seo. All rights reserved.
//

#include<iostream>
using namespace std;

int main()
{
    int n;
    cin >> n; // 화단의 길이
    
    // a <= b <= c
    // a + b + c = n
    // a + b > c
    int count = 0;

    for (int c = 1; c <= n; c++) { // c is the longest
        for (int b = 1; b <= c; b++) { // second longest
            int a = n - b - c;
            if (a > 0 && a <= b && (a+b > c)) {
                count ++;
//                cout << count << " " << a << ' ' << b << ' ' << c << endl;
            }
        }
    }
    cout << count << endl;
    
    return 0;
}
