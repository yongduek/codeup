//
//  codeup_2016천단위코마.cpp
//  codeup
//
//  Created by Yongduek Seo on 2018. 1. 22..
//  Copyright © 2018년 Yongduek Seo. All rights reserved.
//

#include<iostream>
#include<stack>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    stack<char> stk;

    int count = 0;
    while (!s.empty()) {
        count ++;
        stk.push (s.back());
        s.pop_back();
        if (!s.empty() && count % 3 == 0)
            count = 0, stk.push (',');
    }
    while (!stk.empty()) {
        s.push_back(stk.top());
        stk.pop();
    }
    cout << s << endl;
    return 0;
}
