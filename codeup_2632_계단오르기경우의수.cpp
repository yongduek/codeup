//  관계기반 설계

//  codeup_2632_계단오르기경우의수.cpp
//  codeup
//
//  Created by Yongduek Seo on 2018. 1. 21..
//  Copyright © 2018년 Yongduek Seo. All rights reserved.
//

#include<iostream>
using namespace std;

int cnt[30];


int main()
{
    int n;
    cin >> n;

    cnt[1] = 1; // 1 번 계단으로 가는 방법은 1가지 뿐이다.
    cnt[2] = 2; // 2번 계단으로 가는 방법은 {1-2, 2} 두 가지이다.
    cnt[3] = cnt[1] + cnt[2]; // 3번 계단으로 오는 방법은
    // 바로 이전 계단인 2번 계단에서 오는 방법과
    // 2개 이전 계단인 1번 계단에서 오는 방법이 있다.
    // 그래서, 아래와 같은 점화식을 만드는 것이 가능하다.
    for (int k = 3; k <= n; k++)
        cnt[k] = cnt[k-1] + cnt[k-2]; // 그러하다.
    
    cout << cnt[n] << endl;
    
    return 0;
}
