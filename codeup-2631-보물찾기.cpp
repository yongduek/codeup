//
//  2631.cpp
//  codeup
//
//  Created by Yongduek Seo on 11/03/2018.
//  Copyright © 2018 Yongduek Seo. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;

const int size = 100011;
int num[size];
int ii[size]; // cumulative sum

int main()
{
    int n, k;
    cin >> n >> k;
    
    for (int i=0; i<n; i++)
        cin >> num[i];
    
    // find the number of cases where partial sum == k

    int count = 0;

    int sumij = 0;
    int s = 0, e = n;
    for (int i=0; i<n; i++) {
        sumij += num[i];
        if (sumij == k) {
            count ++;
        }
        else if (sumij > k) {
            do {
                sumij -= num[s++];
            } while (sumij > k);
            if (sumij == k) count++;
        }
    }
    cout << count;
    return 0;
}
/***
 ! range sum 을 미리 구하더라도 k 가 발생하는 모든 경우의 수를 (i,j) 에 대해서 찾는 것은 O(n^2) 이다.
 ! 위 경우처럼 누적합을 계산하면서 누적합의 결과값을 검사하는 방식으로 처리하면 O(n)으로 해결할 수 있다.
 ***/
