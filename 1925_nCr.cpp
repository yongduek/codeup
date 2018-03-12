//
//  1925_nCr.cpp
//  codeup
//
//  Created by Yongduek Seo on 3/12/18.
//  Copyright © 2018 com.yndk. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;

typedef unsigned long ul;

ul perm (int n, int r) {
    if (r==0) return 1;
    else
        return n * perm (n-1, r-1);
}

ul facto (unsigned n) {
    return (n==1) ? 1 : n * facto(n-1);
}

ul combi_recursive (int n, int r) {
    // 이 문제에서는 22C20 == 22C2 이므로 이 부분을 이용하는 것이 중요하다.
    int r2 = n - r;
    if (r2 < r)
        return perm (n, r2) / facto (r2) ;
    else
        return perm (n, r) / facto (r);
}

int main()
{
    int n, r;
    cin >> n >> r;
    cout << combi_recursive (n, r);
    return 0;
}
