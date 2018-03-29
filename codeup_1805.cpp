//
//  codeup_1805.cpp
//  codeup
//
//  Created by Yongduek Seo on 3/29/18.
//  Copyright © 2018 com.yndk. All rights reserved.
//
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct robot {
    int id;
    int gas;
    
    robot (int iid, int igas) : id(iid), gas(igas) { }
    bool operator < (const robot& r) const { return id < r.id; }
};

vector<robot> vbots;

int main()
{
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        vbots.push_back ( robot(a,b) );
    }
    
    sort (vbots.begin(), vbots.end());
    for (auto b : vbots)
        printf ("%d %d\n", b.id, b.gas);
    
    return 0;
}
