//
//  codeup_4012_석차계산.cpp
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

struct student {
    int grade;
    int rank;
    int selfid;
    string name;
    
    bool operator < (const student& s) const { return grade < s.grade; }
    bool operator > (const student& s) const { return grade > s.grade; }
};

vector<student> sa;

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        student st;
        cin >> st.grade;
        st.selfid = i;
        sa.push_back( st );
    }
    
    auto sb = sa;
    sort (sb.begin(), sb.end(), greater<student>()); // 내림차순 정렬
    
    // 순위 정하기
    int rank = 1, count = 1;
    sa[ sb[0].selfid ].rank = rank;
    for (int i = 1; i < n; i++)
        if (sb[i-1].grade == sb[i].grade) {
            sa[ sb[i].selfid ].rank = rank;
            count ++;
        } else {
            sa[ sb[i].selfid ].rank = (rank+=count);
            count = 1;
        }

    for (auto st : sa) // C++11, access by value
        printf ("%d %d\n", st.grade, st.rank);
}
