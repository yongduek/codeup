//
//  codeup_2623_최대공약수.cpp
//  codeup
//
//  Created by Yongduek Seo on 2018. 1. 21..
//  Copyright © 2018년 Yongduek Seo. All rights reserved.
//

#include <iostream>
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    
    int smallnum = a < b ? a : b;
    
    int gcd = 1;
    
    for (int i = 1; i <= smallnum; i++)
        if (a % i == 0 && b % i == 0)
            gcd = gcd < i ? i : gcd;
    
    cout << gcd << endl;
}
