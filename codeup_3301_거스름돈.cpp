//
//  codeup_3301_거스름돈.cpp
//  codeup
//
//  Created by Yongduek Seo on 2018. 1. 22..
//  Copyright © 2018년 Yongduek Seo. All rights reserved.
//

#include<iostream>
#include<stack>
using namespace std;

const int nnotes = 8;
int notes[nnotes] = { 50000, 10000, 5000, 1000, 500, 100, 50, 10 };

int main()
{
    int n;
    cin >> n;
    
    int num = 0;
    for (int i = 0; i < nnotes; i++) {
        num += n / notes[i];
        n = n % notes[i];
    }
    cout << num << endl;
    return 0;
}
